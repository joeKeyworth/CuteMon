#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#include "cutemon.h"
#include "./ui_cutemon.h"
#include <thread>
#define _WIN32_WINNT 0x602
#define DIV 1024
#include <windows.h>
#include <stdlib.h>
#include <winnt.h>
#include <QDebug>
#include <QLineF>
#include <QString>
#include <QTimer>
#include <list>
#include <tlhelp32.h>
#include <tchar.h>
#include <fileapi.h>
#include <winbase.h>
#include <psapi.h>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <intrin.h>
#include <stdio.h>

//network view lib
#include <winsock2.h>
#include <iphlpapi.h>

#pragma comment(lib, "iphlpapi")

//logical core view lib
#include <winternl.h>
#pragma comment(lib, "ntdll.lib")

#define RESOLUTION 120

using namespace std;
typedef long long int64_t;
typedef unsigned long long uint64_t;

//process variables
//map<pID, Variable>
/* did not work for some reason, had to switch back to individual maps
struct process{
    unsigned int pid;
    bool isUser;
    double cpuUsage = 0;
    double memUsage = 0;
    QTreeWidgetItem* uiObject;
    QTreeWidgetItem* o_uiObject;
};
map<unsigned int, process> procMap;
*/

map<unsigned int, QTreeWidgetItem*> ProcessMap;
map<unsigned int, QTreeWidgetItem*> OverviewMap;
map<unsigned int, double> processUsageCPU;
map<unsigned int, double> processUsageMEM;
map<unsigned int, bool> isUserMap;
map<unsigned int, int> processThreadCount;
map<unsigned int, int64_t> processUptime;

int REFRESH = 1000;


//cpu variables
int g_cpuIndex = 0;
int coreIndex = 0;
int g_cpu;
int g_coreCount;
int g_cpu_arr[RESOLUTION];
QCustomPlot *g_cpuPlot;
QCustomPlot *g_o_cpuPlot;
QTreeWidget *g_coreTable;
map<int, QTreeWidgetItem*> coreMap;
QString g_cpuName;

//memory variables
int g_memIndex = 0;
int g_statex_arr[RESOLUTION];
MEMORYSTATUSEX g_statex;
unsigned long long g_currentMemUsed;
unsigned long long g_totalMem;
QCustomPlot *g_ramPlot;
QCustomPlot *g_o_memPlot;

//disk variables
//map<diskName, diskObject>
struct disk{
    ULARGE_INTEGER FreeBytesAvailableToCaller;
    ULARGE_INTEGER TotalNumberOfBytes;
    ULARGE_INTEGER TotalNumberOfFreeBytes;
};

map<string, disk> diskMap;

//network variables
int uploadArr[RESOLUTION];
int downloadArr[RESOLUTION];
int g_netIndex = 0;
int g_peakUp;
int g_peakDown;
QString g_ipv4addr;
QString g_ipv6addr;
QString g_conntype;
QString g_NICname;
QString g_constrength;
QString g_SSID;
QString g_MAC;
QString g_authtype;
QCustomPlot *g_netPlot;
QCustomPlot *g_NETPLOT;

//global variables
Ui::CuteMon *g_ui;
//Text[3], Background[3], c_Line[3], c_Shade[3], c_Bord[3], m_Line[3], m_Shade[3], m_Bord[3], n_Line1[3], n_Line1Shade[3], n_Line2[3], n_Bord[3], p_Max[3], p_Min[3];
map<QString, int> catSelector;
int g_pA[19][3];
int TEXT = 0, BACK = 1,
    TBACK = 2,TBORD = 3, THOVER = 4, TSELECT  =5,
    CLINE = 6, CSHADE = 7, CBORD = 8,
    MLINE = 9, MSHADE = 10, MBORD = 11,
    NLINE1 = 12, NLINE1SHADE = 10, NLINE2 = 14, NBORD = 15,
    PMAX = 16, PMIN = 17;

uint64_t fileTimeToUtc(const FILETIME *ftime){
    LARGE_INTEGER li;
    li.LowPart = ftime->dwLowDateTime;
    li.HighPart = ftime->dwHighDateTime;

    return li.QuadPart;
}

int coreArray[16][RESOLUTION];

void* getCoreUsage(){
    SYSTEM_PROCESSOR_PERFORMANCE_INFORMATION perf[g_coreCount];
    uint64_t idle[g_coreCount];
    uint64_t kernal[g_coreCount];
    uint64_t user[g_coreCount];

    for(int i = 0; i < g_coreCount; i++){
        for(int b = 0; b < RESOLUTION; b++){
            coreArray[i][b] = 0;
        }
    }
    while(1){
        NtQuerySystemInformation(SystemProcessorPerformanceInformation, &perf, sizeof(SYSTEM_PROCESSOR_PERFORMANCE_INFORMATION) * g_coreCount, NULL);
        for(int i = 0; i < g_coreCount; i++){
            idle[i] = perf[i].IdleTime.QuadPart;
            kernal[i] = perf[i].KernelTime.QuadPart;
            user[i] = perf[i].UserTime.QuadPart;
        }
        Sleep(REFRESH * 0.5);
        NtQuerySystemInformation(SystemProcessorPerformanceInformation, perf, sizeof(SYSTEM_PROCESSOR_PERFORMANCE_INFORMATION) * g_coreCount, NULL);
        uint64_t delta_idle, delta_kernal, delta_user, total_sys;
        int a = 0;
        for(int c = 0; c < g_coreCount; c++){
            qDebug() << "a: " << a;
            delta_idle = perf[a].IdleTime.QuadPart - idle[a];
            delta_kernal = perf[a].KernelTime.QuadPart - kernal[a];
            delta_user = perf[a].UserTime.QuadPart - user[a];
            total_sys = delta_kernal + delta_user;
            coreArray[c][coreIndex] = (total_sys - delta_idle) * 100 / total_sys;
            a++;
            printf("Core (%d): %d%%\n", a, coreArray[c][coreIndex]);
        }
        coreIndex++;
        if(coreIndex == RESOLUTION){
            coreIndex = 0;
        }
    }

}

void* getCPU(){
    //before and after values
    FILETIME idleTime,kernTime,usrTime;
    FILETIME idleTime2,kernTime2,usrTime2;
    while(true){
        //store processor timing values as before values
        if(!GetSystemTimes(&idleTime,&kernTime,&usrTime)){
            return 0;
        }

        //sleep 500ms
        Sleep(REFRESH * 0.5);

        //store timing values as after values
        if(!GetSystemTimes(&idleTime2,&kernTime2,&usrTime2)){
            return 0;
        }
        //conparing two values and converting them into a percentage
        ULARGE_INTEGER kerL,kerR,usrL,usrR,idlL,idlR;

        //get difference between kernal times
        memcpy(&kerL, &kernTime2, sizeof(FILETIME));
        memcpy(&kerR, &kernTime, sizeof(FILETIME));
        long long kernal = kerL.QuadPart - kerR.QuadPart;

        //get difference between user times
        memcpy(&usrL, &usrTime2, sizeof(FILETIME));
        memcpy(&usrR, &usrTime, sizeof(FILETIME));
        long long user = usrL.QuadPart - usrR.QuadPart;

        //get difference between idle times
        memcpy(&idlL, &idleTime2, sizeof(FILETIME));
        memcpy(&idlR, &idleTime, sizeof(FILETIME));
        long long idle = idlL.QuadPart - idlR.QuadPart;

        //get total system active time
        long long system = kernal + user;

        //get percentage of system to idle time and store within global array
        g_cpu = int((system - idle) * 100 / system);
        g_cpu_arr[g_cpuIndex] = g_cpu;
        g_cpuIndex += 1;
        if(g_cpuIndex == RESOLUTION){
            g_cpuIndex = 0;
        }
    }
}

void* getMEM(){
    g_statex.dwLength = sizeof (g_statex);

    while(true){
        //get memory statex
        GlobalMemoryStatusEx (&g_statex);
        g_totalMem = g_statex.ullTotalPhys;
        g_currentMemUsed = g_statex.dwMemoryLoad * g_statex.ullTotalPhys;
        //store memory usage in global array
        g_statex_arr[g_memIndex] = g_statex.dwMemoryLoad;
        g_memIndex += 1;
        if(g_memIndex == RESOLUTION){
            g_memIndex = 0;
        }
        Sleep(REFRESH * 0.5);
    }
}

void* getProcessUsage(){
    while(1){
        //initialise variables
        map<unsigned int, int64_t> lastSystemTime;
        map<unsigned int, int64_t> lastTime;
        list<unsigned int> procBuffer;
        FILETIME now;
        FILETIME creationTime;
        FILETIME exitTime;
        FILETIME kernalTime;
        FILETIME userTime;
        int64_t systemTime;
        int64_t time;
        int64_t systemTimeDelta;
        int64_t timeDelta;
        double cpu;
        //for each recognized active process
        for(auto process : ProcessMap){
            //get current system time
            GetSystemTimeAsFileTime(&now);
            //open the current process
            HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, false, process.first);
            //attempt to retrieve process timing information, skip process if fail
            if(!GetProcessTimes(hProcess, &creationTime, &exitTime, &kernalTime, &userTime)){
                CloseHandle(hProcess);
                continue;
            }
            //get process memory information
            PROCESS_MEMORY_COUNTERS_EX pmc;
            GetProcessMemoryInfo(hProcess,(PROCESS_MEMORY_COUNTERS*)&pmc,sizeof(pmc));
            SIZE_T virtualMemUsed = pmc.WorkingSetSize;
            processUsageMEM[process.first] = static_cast<int>(virtualMemUsed) / 1000000;

            //getCpu information
            systemTime = (fileTimeToUtc(&kernalTime) + fileTimeToUtc(&userTime)) / g_coreCount;
            time = fileTimeToUtc(&now);
            //store information with PID mapped to timing
            lastSystemTime[process.first] = systemTime;
            lastTime[process.first] = time;
            //add process to the process buffeer
            procBuffer.push_back(process.first);
        }
        //sleep 1000ms
        Sleep(REFRESH * 0.5);

        //for each process in the process buffer
        for(auto const& pID : procBuffer){
            GetSystemTimeAsFileTime(&now);
            HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, false, pID);
            if(!GetProcessTimes(hProcess, &creationTime, &exitTime, &kernalTime, &userTime)){
                CloseHandle(hProcess);
                continue;
            }
            //compare timing information from before to current timing information
            systemTime = (fileTimeToUtc(&kernalTime) + fileTimeToUtc(&userTime)) / g_coreCount;
            time = fileTimeToUtc(&now);

            systemTimeDelta = systemTime - lastSystemTime[pID];
            timeDelta = time - lastTime[pID];

            //map process usage as a percentage to its PID for later retrieval
            cpu = (systemTimeDelta * 100 + timeDelta / 2) / timeDelta;
            processUsageCPU[pID] = cpu;
        }
    }
}

void* getNet(){
    int index = 0;
    MIB_IFTABLE *netTable;
    MIB_IFROW *netRow;
    netTable = (MIB_IFTABLE*)malloc(sizeof(MIB_IFTABLE));
    DWORD dwSize = sizeof(MIB_IFTABLE);
    DWORD dwRetvalue = GetIfTable(netTable, &dwSize, false);
    QString retReason;

    DWORD inOctets;
    DWORD outOctets;

    while(1){
        if(dwRetvalue == ERROR_INSUFFICIENT_BUFFER){
            free(netTable);
            netTable  = (MIB_IFTABLE*)malloc(dwSize);
            if(netTable == NULL){
                qDebug() << "Error allocating memory";
            }
        }
        dwRetvalue = GetIfTable(netTable, &dwSize, false);

        if(dwRetvalue == NO_ERROR){
            DWORD dwEntries = netTable->dwNumEntries;
            for(int i = 0; i < dwEntries; i++){
                netRow = (MIB_IFROW*) & netTable->table[i];

                if((netRow->dwOperStatus == IF_OPER_STATUS_OPERATIONAL) && (netRow->dwInOctets > 0)){
                    inOctets = netRow->dwInOctets;
                    outOctets = netRow->dwOutOctets;
                    break;
                }
            }
        }
        Sleep(REFRESH * 0.5);
        dwRetvalue = GetIfTable(netTable, &dwSize, false);
        if(dwRetvalue == NO_ERROR){
            DWORD dwEntries = netTable->dwNumEntries;
            for(int i = netTable->dwNumEntries; i > 0; i--){
                netRow = (MIB_IFROW*) & netTable->table[i];

                if((netRow->dwOperStatus == IF_OPER_STATUS_OPERATIONAL) && (netRow->dwInOctets > 0)){
                    inOctets = (netRow->dwInOctets - inOctets) * 8 * (1000/(REFRESH * 0.5));
                    outOctets = (netRow->dwOutOctets - outOctets) * 8 * (1000/(REFRESH * 0.5));
                    printf("IN: %ld/Kbps | OUT: %ld/Kbps\n", inOctets / 1000, outOctets / 1000);
                    downloadArr[g_netIndex] = inOctets;
                    uploadArr[g_netIndex] = outOctets;
                    qDebug() << netRow->bDescr;
                    qDebug() << netRow->dwSpeed * 8 << " Bps";
                    g_netIndex++;
                    if(g_netIndex == RESOLUTION) g_netIndex = 0;
                    fflush(stdout);

                    //get NIC name
                    printf("\tDescription[%d]:\t ", i);
                    for (int j = 0; j < netRow->dwDescrLen; j++)
                        printf("%c", netRow->bDescr[j]);
                    printf("\n");
                    char str[sizeof(netRow->bDescr) + 1];
                    memcpy(str, netRow->bDescr, sizeof(netRow->bDescr));
                    str[sizeof(netRow->bDescr)] = 0;
                    g_NICname = str;


                    break;
                }
            }
        }
    }
}

void editProcess(QTreeWidgetItem* process, unsigned int pid, bool isReduc){
    int ofset = 0;
    if(isReduc) ofset = 1;
    QString val = "";
    val = QString::number(processUsageCPU[pid], 'f',1) + "%";
    QString memVal = "";
    memVal = QString::number(processUsageMEM[pid]) + " Mb";
    //qDebug() << "Mem " << memVal << ", Cpu " << val << ", pid " << pid;

    process->setText(2 - ofset,QString::number(pid));
    process->setText(7, QString::number(processThreadCount[pid]));
    process->setText(3 - (ofset),val);
    process->setText(4 - (ofset),memVal);
    double cpuMultiplier = (processUsageCPU[pid] / 100) * 100;
    double memMultiplier = ((processUsageMEM[pid] / 1000) > 1 ? 1 : (processUsageMEM[pid] / 1000)) * 100;
    double avg = (cpuMultiplier + memMultiplier) / 2;
    QString pwr;
    double pwrCol;
    if(avg < 20) { pwr = "Low"; pwrCol = 30;} else if(avg < 40) {pwr = "Medium"; pwrCol = 60;} else {pwr = "High"; pwrCol = 90;}
    process->setText(6, pwr);
    process->setForeground(1 - ofset,QColor(255, 255 - avg, 155));
    process->setForeground(2 - ofset,QColor(255, 255 - avg,  155));
    process->setForeground(3 - (ofset),QColor(255, 255 - cpuMultiplier, 155));
    process->setForeground(4 - (ofset),QColor(255, 255 - memMultiplier, 155));
    process->setForeground(6,QColor(255,255 - pwrCol,155));
    process->setForeground(7,Qt::white);
}

void getDisks(){
    std::vector<std::string> arrayOfDrives;
    char* szDrives = new char[MAX_PATH]();
    if(GetLogicalDriveStringsA(MAX_PATH,szDrives)){
        for(int i = 0; i < 100; i += 4){
            if(szDrives[i] != (char)0){
                arrayOfDrives.push_back(std::string{szDrives[i], szDrives[i+1], szDrives[i+2]});
            }
        }
    }
    for(std::string currentDrive : arrayOfDrives){
        const char *chDrive = currentDrive.c_str();
        disk newDisk;
        qDebug() << currentDrive;

        ULARGE_INTEGER FreeBytesAvailableToCaller;
        ULARGE_INTEGER TotalNumberOfBytes;
        ULARGE_INTEGER TotalNumberOfFreeBytes;

        if(GetDiskFreeSpaceExA(chDrive, &FreeBytesAvailableToCaller, &TotalNumberOfBytes, &TotalNumberOfFreeBytes)){
            newDisk.FreeBytesAvailableToCaller = FreeBytesAvailableToCaller;
            newDisk.TotalNumberOfFreeBytes = TotalNumberOfFreeBytes;
            newDisk.TotalNumberOfBytes = TotalNumberOfBytes;
            diskMap[currentDrive] = newDisk;
            qDebug() << diskMap[currentDrive].TotalNumberOfBytes.QuadPart << " " << FreeBytesAvailableToCaller.QuadPart << " " << TotalNumberOfFreeBytes.QuadPart;
            continue;
        }
        qDebug() << "Failed to find disk " << currentDrive;
    }
}

QString reduceIntToQString(int unprocessedInt){
    QString units[] = {" Kb", " Kb", " Mb", " Gb", " Tb", " Pb"};
    int buffer = unprocessedInt;
    int count = 0;
    int mod = 0;
    while(unprocessedInt > 0){
        count += 1;
        unprocessedInt /= 1000;
    }
    if(count > 0) count -= 1;

    for(int i = 0 ; i < count; i++){
        buffer /= 1000;

    }
    QString final = QString::fromStdString(std::to_string(buffer)) + units[count];

    return final;
}

//creates colored border
void plotHideAxis(QCustomPlot *plot, QColor color){
    plot->setBackground(QColor(g_pA[BACK][0],g_pA[BACK][1],g_pA[BACK][2]));
    plot->yAxis->setBasePen(QPen(color));
    plot->xAxis->setBasePen(QPen(color));
    plot->xAxis2->setVisible(true);
    plot->yAxis2->setVisible(true);
    plot->xAxis2->setBasePen(QPen(color));
    plot->yAxis2->setBasePen(QPen(color));
    plot->yAxis->setTicks(false);
    plot->xAxis->setTicks(false);
    plot->yAxis2->setTicks(false);
    plot->xAxis2->setTicks(false);
    plot->xAxis->grid()->setPen(QPen(QColor(g_pA[BACK][0],g_pA[BACK][1],g_pA[BACK][2])));
    plot->yAxis->grid()->setPen(QPen(Qt::gray, 0, Qt::DotLine));
}

//sets axis range
void plotSetAxis(QCustomPlot *plot, int yRange){
    plot->xAxis->setRange(0,RESOLUTION);
    plot->yAxis->setRange(0,yRange);
    plot->yAxis2->setRange(0,yRange);
}

//sets plot line and shading colors
void plotSetColor(QCustomPlot *plot, int r, int g, int b, int a, int plotIndex, bool doShade){
    plot->graph(plotIndex)->setPen(QPen(QColor(r, g, b)));
    if(doShade) plot->graph(plotIndex)->setBrush(QBrush(QColor(r, g, b, a)));
}

//alternative border generation
void plotDarkMode(QCustomPlot *plot){
    plot->setBackground(QColor(QColor(g_pA[BACK][0],g_pA[BACK][1],g_pA[BACK][2])));
    plot->xAxis->setBasePen(QPen(QColor(g_pA[TEXT][0],g_pA[TEXT][1],g_pA[TEXT][2])));
    plot->yAxis->setBasePen(QPen(QColor(g_pA[TEXT][0],g_pA[TEXT][1],g_pA[TEXT][2])));
    plot->xAxis->setTickLabelColor(QColor(g_pA[TEXT][0],g_pA[TEXT][1],g_pA[TEXT][2]));
    plot->yAxis->setTickLabelColor(QColor(g_pA[TEXT][0],g_pA[TEXT][1],g_pA[TEXT][2]));
}


QVector<double> xCPU(RESOLUTION), yCPU(RESOLUTION);
QVector<double> xRAM(RESOLUTION), yRAM(RESOLUTION);
QVector<double> xNETuP(RESOLUTION), yNETuP(RESOLUTION);
QVector<double> xNETdOWN(RESOLUTION), yNETdOWN(RESOLUTION);
QVector<double> xCore(RESOLUTION), yCore(RESOLUTION);




void getNetInfo(){
    system("cd");
    system("netsh wlan show int> out.txt 2>&1");
    system("ipconfig>>out.txt 2>&1");

    QFile file("out.txt");
    if(!file.open(QIODevice::ReadOnly)){
        qDebug() << "File failed to open :(";
        return;
    }
    QTextStream in(&file);
    QStringList data;
    int count = 0;
    int longCount = 0;
    while(!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(":");
        if(fields.size() > 1){
            if(longCount == 3){
                g_ipv4addr = fields[1];
                longCount++;
            }
            if(fields.size() > 2){
                QString longVal;
                for(int i = 1; i < fields.size() - 1; i++){
                    longVal = longVal + fields[i] + ":";
                }
                longVal = longVal + fields[fields.size() - 1];
                qDebug() << longVal;
                data.push_back(longVal);
                count++;
                longCount++;
                switch(longCount){
                case 1:
                    //MAC
                    g_MAC = longVal;
                case 3:
                    //IPv6
                    g_ipv6addr = longVal;
                }
                continue;
            }
            data.push_back(fields[1]);
            qDebug() << fields[1];
            count++;
        }
    }
    qDebug() << data;
    g_conntype = data[9];
    g_SSID = data[6];
    g_authtype = data[10];
    g_constrength = data[16];
    qDebug() << g_conntype << ", " << g_SSID << ", " << g_MAC << ", " << g_authtype << ", " << g_constrength << ", " << g_ipv4addr << ", " << g_ipv6addr;
    file.close();

    QString strengtype[] = {"VERY WEAK","WEAK","OK","STRONG","VERY STRONG"};
    QString strength;
    strength += g_constrength[1];
    strength += g_constrength[2];
    qDebug() << strength;
    int val = strength.toInt();
    val = val / 20;


    g_ui->PHYSADDR->setText("Physical (MAC) Addr: " + g_MAC);
    g_ui->SIGSTR->setText("Signal Strength:     " + strengtype[val] + " (" + g_constrength + ")");
    g_ui->SSID->setText("SSID:                       " + g_SSID);
    g_ui->IPV6ADDR->setText("IPv6 Address:         " + g_ipv6addr);
    g_ui->IPV4ADDR->setText("IPv4 Address:         " + g_ipv4addr);
    g_ui->CONN_TYPE->setText("Connection type:   " + g_conntype);
    g_ui->AUTHTYPE->setText("Authentication:           " + g_authtype);
}

QString g_textStyle = "";
QString g_backStyle = "";

QString toString(int in){
    QString out = QString::fromStdString(std::to_string(in));
    return out;
}

void setGlobalText(){
    g_textStyle = "color:rgb(" + toString(g_pA[TEXT][0]) + "," + toString(g_pA[TEXT][1]) + "," + toString(g_pA[TEXT][2]) + ");";
    QString style = g_backStyle + g_textStyle;
    g_ui->tab->setStyleSheet(style);
    g_ui->tab_2->setStyleSheet(style);
    g_ui->tab_3->setStyleSheet(style);
    g_ui->tab_4->setStyleSheet(style);
    g_ui->tab_6->setStyleSheet(style);
    g_ui->tab_7->setStyleSheet(style);
    g_ui->centralwidget->setStyleSheet(style);
    qDebug() << g_ui->tab_0->styleSheet();
}
void setGlobalBack(){
    g_backStyle = "background:solid rgb(" + toString(g_pA[BACK][0]) + "," + toString(g_pA[BACK][1]) + "," + toString(g_pA[BACK][2]) + ");";
    QString style = g_backStyle + g_textStyle;
    g_ui->tab->setStyleSheet(style);
    g_ui->tab_2->setStyleSheet(style);
    g_ui->tab_3->setStyleSheet(style);
    g_ui->tab_4->setStyleSheet(style);
    g_ui->tab_6->setStyleSheet(style);
    g_ui->tab_7->setStyleSheet(style);
    g_ui->centralwidget->setStyleSheet(style);
}

void setFrameBorders(){
    QString palette = toString(g_pA[TBACK][0]) + "," + toString(g_pA[TBACK][1]) + "," + toString(g_pA[TBACK][2]);
    QString paletteRed = toString(g_pA[TBACK][0] - 30) + "," + toString(g_pA[TBACK][1] - 30) + "," + toString(g_pA[TBACK][2] - 30);

    QString frameCOLOR =  "border-top: 2px solid rgba(" + palette + ", 1);\n" +
                         "border-left: 2px solid rgba(" + palette + ", 1);\n" +
                         "border-bottom: 2px solid rgba(" + paletteRed + ", 1);\n" +
                         "border-right: 2px solid rgba(" + paletteRed + ", 1);\n";

    g_ui->CPUFRAME->setStyleSheet(frameCOLOR);
    g_ui->MEMFRAME->setStyleSheet(frameCOLOR);
    g_ui->NETFRAME->setStyleSheet(frameCOLOR);
}

void setTabBack(){
    QString style = "QTabWidget\n{\n	background:rgb(" + toString(g_pA[TBACK][0]) + "," + toString(g_pA[TBACK][1]) + "," + toString(g_pA[TBACK][2]) +
                    ");\n}\n\nQTabBar::tab:selected \n{\n    background:rgb(" + toString(g_pA[TSELECT][0]) + "," + toString(g_pA[TSELECT][1]) + "," + toString(g_pA[TSELECT][2]) +
                    ");\n\n}\n\nQTabBar::tab:!selected \n{\n    background:rgb(" + toString(g_pA[TBORD][0]) + "," + toString(g_pA[TBORD][1]) + "," + toString(g_pA[TBORD][2]) +
                    ");\n}\n\nQTabBar::tab:!selected:hover \n{\n    background:rgb(" + toString(g_pA[THOVER][0]) + "," + toString(g_pA[THOVER][1]) + "," + toString(g_pA[THOVER][2]) +
                    ");\n}\n\nQTabWidget::pane\n{\n    border:3px solid rgb(" + toString(g_pA[TSELECT][0]) + "," + toString(g_pA[TSELECT][1]) + "," + toString(g_pA[TSELECT][2]) + ");\n}\n\n";
    qDebug() << style;

    QString tableStyle = "QHeaderView::section\n{\n  background-color:rgb(" + toString(g_pA[TBACK][0]) + "," + toString(g_pA[TBACK][1]) + "," + toString(g_pA[TBACK][2]) +
                         ");\n  border: 1px solid rgb(" + toString(g_pA[TSELECT][0]) + "," + toString(g_pA[TSELECT][1]) + "," + toString(g_pA[TSELECT][2]) + ");\n}";
    g_ui->SystemProcesses->setStyleSheet(tableStyle);
    g_ui->UserProcesses->setStyleSheet(tableStyle);
    g_ui->OverviewProcesses->setStyleSheet(tableStyle);
    g_ui->tab_0->setStyleSheet(style);
}


//Text[3], Background[3], c_Line[3], c_Shade[3], c_Bord[3], m_Line[3], m_Shade[3], m_Bord[3], n_Line1[3], n_Line1Shade[3], n_Line2[3], n_Bord[3], p_Max[3], p_Min[3];
//int g_paletteArr[15][3];

QCPTextElement* titleArr[3];

CuteMon::CuteMon(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CuteMon)
{
    //init ui
    ui->setupUi(this);
    g_ui = ui;
    getNetInfo();

    QFile configFile("config.txt");
    if(!configFile.open(QIODevice::ReadOnly)){
        qDebug() << "config failed to open...";
    }
    QTextStream in(&configFile);
    int c = 0;
    while(!in.atEnd()){
        QString line = in.readLine();
        QStringList fields = line.split(":");
        if(fields.size() > 1){
            QStringList cols = fields[1].split(",");
            g_pA[c][0] = cols[0].toInt();
            g_pA[c][1] = cols[1].toInt();
            g_pA[c][2] = cols[2].toInt();
            c++;
        }
    }
    configFile.close();

    setGlobalText();
    setGlobalBack();
    setFrameBorders();
    SYSTEM_INFO sysInfo;
    GetSystemInfo(&sysInfo);
    g_coreCount = sysInfo.dwNumberOfProcessors;

    //init timer
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateWindow()));
    connect(timer, SIGNAL(timeout()), this, SLOT(getProcessInfo()));

    //init threads
    std::thread procThread(getProcessUsage);
    std::thread cpuThread(getCPU);
    std::thread memThread(getMEM);
    std::thread netThread(getNet);
    std::thread coreThread(getCoreUsage);

    procThread.detach();
    cpuThread.detach();
    memThread.detach();
    netThread.detach();
    coreThread.detach();

    //init cpu and ram buffer
    for (int i=0; i<RESOLUTION; ++i)
    {
        xCPU[i] = i;
        yCPU[i] = 0;

        xRAM[i] = i;
        yRAM[i] = 0;

        xNETuP[i] = i;
        yNETuP[i] = 0;

        xNETdOWN[i] = i;
        yNETdOWN[i] = 0;

        xCore[i] = i;
        xCore[i] = 0;
    }


    //init graph plots
    g_netPlot = ui->netPlot;
    g_NETPLOT = ui->NETPLOT;
    g_cpuPlot = ui->CPUplot;
    g_ramPlot = ui->RAMplot;
    g_o_cpuPlot = ui->CPUPLOT;
    g_o_memPlot = ui->MEMPLOT;


    QCPTextElement *cpuTitle = new QCPTextElement(g_o_cpuPlot);
    cpuTitle->setText("Processor");
    titleArr[0] = cpuTitle;
    cpuTitle->setTextColor(QColor(g_pA[TEXT][0],g_pA[TEXT][1],g_pA[TEXT][2]));
    g_o_cpuPlot->plotLayout()->insertRow(0);
    g_o_cpuPlot->plotLayout()->addElement(0,0,cpuTitle);

    QCPTextElement *memTitle = new QCPTextElement(g_o_memPlot);
    titleArr[1] = memTitle;
    memTitle->setText("Memory");
    memTitle->setTextColor(QColor(g_pA[TEXT][0],g_pA[TEXT][1],g_pA[TEXT][2]));
    g_o_memPlot->plotLayout()->insertRow(0);
    g_o_memPlot->plotLayout()->addElement(0,0,memTitle);

    QCPTextElement *netTitle = new QCPTextElement(g_netPlot);
    titleArr[2] = netTitle;
    netTitle->setText("Network");
    netTitle->setTextColor(QColor(g_pA[TEXT][0],g_pA[TEXT][1],g_pA[TEXT][2]));
    g_netPlot->plotLayout()->insertRow(0);
    g_netPlot->plotLayout()->addElement(0,0,netTitle);

    g_netPlot->addGraph()->setName("Upload");;
    g_netPlot->graph(0)->setData(xNETuP,yNETuP);
    g_netPlot->addGraph()->setName("Download");;
    g_netPlot->graph(1)->setData(xNETdOWN,yNETdOWN);
    g_NETPLOT->addGraph()->setName("Upload");;
    g_NETPLOT->graph(0)->setData(xNETuP,yNETuP);
    g_NETPLOT->addGraph()->setName("Download");;
    g_NETPLOT->graph(1)->setData(xNETdOWN,yNETdOWN);

    g_cpuPlot->addGraph();
    g_cpuPlot->graph(0)->setData(xCPU, yCPU);

    int col[3] = {255,171,171};
    int step = 255 / g_coreCount;
    int raiseReduce = 1; // -1 when reducing
    int gRb = 0;
    //in order G (0)[1], R (1)[0], B (2)[2] in steps of 84
    int key = 0;

    for(int a = 0; a < g_coreCount; a++){
        QTreeWidgetItem *core = new QTreeWidgetItem;
        core->setText(0,"Core: " + QString::fromStdString(std::to_string(a)));
        core->setText(1,"0%");
        if(key == 0){
            ui->CoreTable_3->addTopLevelItem(core);
            key++;
        } else if(key == 1){
            ui->CoreTable_2->addTopLevelItem(core);
            key++;
        } else{
            ui->CoreTable->addTopLevelItem(core);
            key = 0;
        }

        coreMap[a] = core;
        int b = a + 1;
        int mult = 255 / g_coreCount;
        g_cpuPlot->addGraph();
        g_cpuPlot->graph(b)->setData(xCore,yCore);
        qDebug() << col[0] << " " << col[1] << " " << col[2];
        switch(gRb){
        case 0:
            col[1] = col[1] + (step * raiseReduce);
            if(col[1] >= 255 || col[1] <= 171){
                raiseReduce *= -1;
                gRb = 1;
            }
            g_cpuPlot->graph(b)->setPen(QPen(QColor(col[0],col[1],col[2],50)));
            continue;
        case 1:
            col[0] = col[0] + (step * raiseReduce);
            if(col[0] >= 255 || col[0] <= 171){
                raiseReduce *= -1;
                gRb = 2;
            }
            g_cpuPlot->graph(b)->setPen(QPen(QColor(col[0],col[1],col[2],50)));
            continue;
        case 2:
            col[2] = col[2] + (step * raiseReduce);
            if(col[2] >= 255 || col[2] <= 171){
                raiseReduce *= -1;
                gRb = 0;
            }
            g_cpuPlot->graph(b)->setPen(QPen(QColor(col[0],col[1],col[2], 50)));
            continue;
        }

    }

    g_ramPlot->addGraph();
    g_ramPlot->graph(0)->setData(xRAM,yRAM);
    g_o_cpuPlot->addGraph();
    g_o_cpuPlot->graph(0)->setData(xCPU,yCPU);
    g_o_memPlot->addGraph();
    g_o_memPlot->graph(0)->setData(xRAM,yRAM);



    plotSetAxis(g_netPlot, 10000);
    plotSetAxis(g_NETPLOT, 10000);
    plotSetAxis(g_cpuPlot, 100);
    plotSetAxis(g_o_cpuPlot, 100);
    plotSetAxis(g_ramPlot, 100);
    plotSetAxis(g_o_memPlot, 100);

    plotSetColor(g_netPlot,g_pA[NLINE1][0],g_pA[NLINE1][1],g_pA[NLINE1][2],20, 0, true);
    plotSetColor(g_netPlot,g_pA[NLINE2][0],g_pA[NLINE2][1],g_pA[NLINE2][2],20,1, false);
    plotSetColor(g_NETPLOT,g_pA[NLINE1][0],g_pA[NLINE1][1],g_pA[NLINE1][2],20,0,true);
    plotSetColor(g_NETPLOT,g_pA[NLINE2][0],g_pA[NLINE2][1],g_pA[NLINE2][2],20,1,false);
    plotSetColor(g_o_cpuPlot,g_pA[CLINE][0],g_pA[CLINE][1],g_pA[CLINE][2],20,0, true);
    plotSetColor(g_cpuPlot,g_pA[CLINE][0],g_pA[CLINE][1],g_pA[CLINE][2],20,0,true);
    plotSetColor(g_ramPlot,g_pA[MLINE][0],g_pA[MLINE][1],g_pA[MLINE][2],20,0,true);
    plotSetColor(g_o_memPlot,g_pA[MLINE][0],g_pA[MLINE][1],g_pA[MLINE][2],20,0,true);

    plotHideAxis(g_o_cpuPlot, QColor(g_pA[CBORD][0],g_pA[CBORD][1],g_pA[CBORD][2]));
    plotHideAxis(g_o_memPlot, QColor(g_pA[MBORD][0],g_pA[MBORD][1],g_pA[MBORD][2]));
    plotHideAxis(g_netPlot, QColor(g_pA[NBORD][0],g_pA[NBORD][1],g_pA[NBORD][2]));

    plotDarkMode(g_NETPLOT);
    plotDarkMode(g_cpuPlot);
    plotDarkMode(g_ramPlot);
    g_netPlot->setBackground(QColor(g_pA[BACK][0],g_pA[BACK][1],g_pA[BACK][2]));

    //start updateWindow and getProcessInfo
    timer->start(REFRESH);

    //init process table
    QStringList ColumnNames;
    ColumnNames << "User Processes" << "Name" << "pID"  << "CPU" << "Memory" << "Disk" << "Power usage" << "Threads" <<  "";
    QStringList SysColumnNames;
    SysColumnNames << "System Processes" << "" << "" << "" << "" << "" << "" << "" << "";
    QStringList OverviewNames;
    OverviewNames << "Name" << "pID" << "CPU" << "Memory";
    ui->UserProcesses->setColumnCount(9);
    ui->SystemProcesses->setColumnCount(9);
    ui->OverviewProcesses->setColumnCount(4);
    ui->OverviewProcesses->setHeaderLabels(OverviewNames);
    ui->UserProcesses->setHeaderLabels(ColumnNames);
    ui->SystemProcesses->setHeaderLabels(SysColumnNames);

    getDisks();

    int count = 0;
    for(auto currentDisk : diskMap){
        long int totalBytes = currentDisk.second.TotalNumberOfBytes.QuadPart;
        long int availBytes = currentDisk.second.TotalNumberOfFreeBytes.QuadPart;
        QString diskName = QString::fromStdString(currentDisk.first);
        QString totBytes = reduceIntToQString(totalBytes);
        QString avaBytes = reduceIntToQString(availBytes - totalBytes);
        qDebug() << diskName << ": " << avaBytes << "/" << totBytes;

    }

    int CPUInfo[4] = {-1};
    unsigned   nExIds, i =  0;
    char CPUBrandString[0x40];
    // Get the information associated with each extended ID.
    __cpuid(CPUInfo, 0x80000000);
    nExIds = CPUInfo[0];
    for (i=0x80000000; i<=nExIds; ++i)
    {
        __cpuid(CPUInfo, i);
        // Interpret CPU brand string
        if  (i == 0x80000002)
            memcpy(CPUBrandString, CPUInfo, sizeof(CPUInfo));
        else if  (i == 0x80000003)
            memcpy(CPUBrandString + 16, CPUInfo, sizeof(CPUInfo));
        else if  (i == 0x80000004)
            memcpy(CPUBrandString + 32, CPUInfo, sizeof(CPUInfo));
    }
    //string includes manufacturer, model and clockspeed
    qDebug() << "CPU Type: " << CPUBrandString;
    g_cpuName = CPUBrandString;
    ui->cpuName->setText(g_cpuName);
    ui->coreCount->setText(QString::fromStdString(std::to_string(g_coreCount)) + " Cores");
    ui->o_coreCount->setText(QString::fromStdString(std::to_string(g_coreCount)) + " Cores");

    ui->REDSLIDER->setValue(130);
    ui->BLUESLIDER->setValue(130);
    ui->GREENSLIDER->setValue(130);

    //Color groups:
    //GENERAL
    //Text color
    //Background
    //CPU
    //CPU line
    //CPU line shading
    //Plot border
    //MEM
    //MEM line
    //MEM line shading
    //Plot border
    //NET
    //NET line UP
    //NET line DOWN
    //NET line DOWN shading
    //Plot border
    //PROCESS
    //Process high usage
    //Process low usage
    map<QString,QTreeWidgetItem*> catMap;
    QString catStrings[] = {
        "General",          //0 root
        "Tab",              //1 root
        "Processor",        //2 root
        "Memory",           //3 root
        "Network",          //4 root
        "Processes",        //5 root
        "Text",             //6 General
        "Background",       //7 General
        "Background ",       //8 Tab
        "Unselected",       //9 Tab
        "Hover",            //10 Tab
        "Border",           //11 Tab
        "Line",             //12 Processor
        "Shading",          //13 Processor
        "Border ",          //14 Processor
        "Line  ",           //15 Memory
        "Shading   ",             //16 Memory
        "Border  ",          //17 Memory
        "Upload",           //18 Network
        "Upload Shading",           //19 Network
        "Download",   //20 Network
        "Border    ",         //21 Network
        "High Usage",       //22 Processes
        "Low Usage"         //23 Processes
    };


    int counts  = 0;
    for(auto catstring : catStrings){
        QTreeWidgetItem *itm = new QTreeWidgetItem();
        itm->setText(0, catstring);
        if(counts < 6){
            ui->catagoryTree->addTopLevelItem(itm);
            catMap[catstring] = itm;
            catSelector[catstring] = counts - 6;
        } else if(counts < 8){
            catMap[catStrings[0]]->addChild(itm);
            catMap[catstring] = itm;
            catSelector[catstring] = counts - 6;
        } else if(counts < 12){
            catMap[catStrings[1]]->addChild(itm);
            catMap[catstring] = itm;
            catSelector[catstring] = counts - 6;
        } else if(counts < 15){
            catMap[catStrings[2]]->addChild(itm);
            catMap[catstring] = itm;
            catSelector[catstring] = counts - 6;
        } else if(counts < 18){
            catMap[catStrings[3]]->addChild(itm);
            catMap[catstring] = itm;
            catSelector[catstring] = counts - 6;
        } else if(counts < 22){
            catMap[catStrings[4]]->addChild(itm);
            catMap[catstring] = itm;
            catSelector[catstring] = counts - 6;
        } else{
            catMap[catStrings[5]]->addChild(itm);
            catMap[catstring] = itm;
            catSelector[catstring] = counts - 6;
        }
        counts++;
    }

    setTabBack();

}

CuteMon::~CuteMon()
{
    delete ui;
}

void CuteMon::updateWindow()
{
    //get current start of the arrays
    int cpuStart = g_cpuIndex;
    int memStart = g_memIndex;
    int netStart = g_netIndex;
    int coreStart = coreIndex;
    int netRes = 0;
    g_peakDown = 0;
    g_peakUp = 0;


    //construct vectors containg array information such that it can be plotted as a scrolling graph


    int count = 1;

    for(int k = 0; k < g_coreCount; k++){
        for(int a = 0; a < RESOLUTION; ++a){
            xCore[a] = a;
            yCore[a] = coreArray[k][coreStart];
            if(coreStart == RESOLUTION - 1){
                coreStart = 0;
            } else coreStart++;
        }
        coreMap[k]->setText(1, QString::fromStdString(std::to_string((int)yCore[RESOLUTION - 1])) + "%");
        int multi = 255 * (yCore[RESOLUTION - 1] / 100);
        coreMap[k]->setForeground(0, QColor(255, 255 - multi, 155));
        coreMap[k]->setForeground(1, QColor(255, 255 - multi, 155));
        g_cpuPlot->graph(count)->setData(xCore,yCore);
        count++;
    }

    for (int i=0; i<RESOLUTION; ++i)
    {
        xCPU[i] = i;
        yCPU[i] = g_cpu_arr[cpuStart] + 1;
        if(cpuStart == RESOLUTION - 1){
            cpuStart = 0;
        } else{
            cpuStart++;
        }
        xRAM[i] = i;
        yRAM[i] = g_statex_arr[memStart];
        if(memStart == RESOLUTION - 1){
            memStart = 0;
        } else{
            memStart++;
        }
        xNETuP[i] = i;
        yNETuP[i] = uploadArr[netStart];
        xNETdOWN[i] = i;
        yNETdOWN[i] = downloadArr[netStart];
        if(downloadArr[netStart] > netRes) netRes = downloadArr[netStart];
        if(uploadArr[netStart] > netRes) netRes = uploadArr[netStart];
        if(downloadArr[netStart] > g_peakDown) g_peakDown = downloadArr[netStart];
        if(uploadArr[netStart] > g_peakUp) g_peakUp = uploadArr[netStart];
        if(netStart == RESOLUTION - 1){
            netStart = 0;
        } else netStart++;

    }
    unsigned int used = (unsigned int)(g_currentMemUsed / 100000000000);
    unsigned int total = (unsigned int)(g_totalMem / 1000000000);
    unsigned int avai = total - used;

    //set the display text as the current percentage
    g_ui->o_cpu_percentage->setText(QString::fromStdString(std::to_string((int)yCPU[RESOLUTION - 1])) + "%");
    //g_ui->o_core_count->setText("Cores: " + QString::fromStdString(std::to_string(g_coreCount)));
    g_ui->o_mem_percentage->setText(QString::fromStdString(std::to_string((int)yRAM[RESOLUTION - 1])) + "%");
    g_ui->o_avai_percentage->setText(QString::fromStdString(std::to_string(100 - (int)yRAM[RESOLUTION - 1])) + "%");
    g_ui->o_mem_avai->setText("Avail: " + QString::fromStdString(std::to_string(avai)) + " GiB");
    g_ui->o_mem_total->setText("Total: " + QString::fromStdString(std::to_string(total)) + " GiB");
    g_ui->o_mem_used->setText("Used:         " + QString::fromStdString(std::to_string(used))+ " GiB");

    g_ui->CPUTEXT->setText(QString::fromStdString(std::to_string((int)yCPU[RESOLUTION - 1])) + "%");
    g_ui->RAMTEXT->setText(QString::fromStdString(std::to_string((int)yRAM[RESOLUTION - 1])) + "%");
    g_ui->Avai->setText("Available:      " + QString::fromStdString(std::to_string(avai)) + " GiB");
    g_ui->ramTotal->setText("Total:              " + QString::fromStdString(std::to_string(total)) + " GiB");
    g_ui->Used->setText("Used:             " + QString::fromStdString(std::to_string(used))+ " GiB");

    g_ui->o_download_value->setText(reduceIntToQString((int)yNETdOWN[RESOLUTION-1]) + "ps");
    g_ui->o_upload_val->setText(reduceIntToQString((int)yNETuP[RESOLUTION-1]) + "ps");
    g_ui->DOWNVAL->setText(reduceIntToQString((int)yNETdOWN[RESOLUTION-1]) + "ps");
    g_ui->UPVAL->setText(reduceIntToQString((int)yNETuP[RESOLUTION-1]) + "ps");
    g_ui->o_peak_down_val->setText(reduceIntToQString(g_peakDown) + "ps");
    g_ui->o_peak_up_val->setText(reduceIntToQString(g_peakUp) + "ps");
    g_ui->netName->setText(g_NICname);

    //set the values stored within the ui graph elements to the new data
    g_netPlot->yAxis->setRange(0,netRes * 1.5);
    g_netPlot->graph(0)->setData(xNETuP,yNETuP);
    g_netPlot->graph(1)->setData(xNETdOWN,yNETdOWN);
    g_NETPLOT->yAxis->setRange(0,netRes * 1.5);
    g_NETPLOT->graph(0)->setData(xNETuP,yNETuP);
    g_NETPLOT->graph(1)->setData(xNETdOWN,yNETdOWN);
    g_ramPlot->graph(0)->setData(xRAM,yRAM);
    g_cpuPlot->graph(0)->setData(xCPU, yCPU);
    g_o_cpuPlot->graph(0)->setData(xCPU,yCPU);
    g_o_memPlot->graph(0)->setData(xRAM,yRAM);

    //update the graph ui element
    g_netPlot->replot();
    g_ramPlot->replot();
    g_cpuPlot->replot();
    g_o_cpuPlot->replot();
    g_o_memPlot->replot();
    g_NETPLOT->replot();

}

ULARGE_INTEGER lastCPU, lastSysCPU, lastUserCPU;
int numProcessors;

//uses map<unsigned int, QTreeWidgetItem*> ProcessMap;

void CuteMon::getProcessInfo(){
    HANDLE hProcessSnap;
    HANDLE hProcess;
    PROCESSENTRY32 pe32;
    DWORD dwPriorityClass;

    list<unsigned int> PIDBuffer;
    list<unsigned int> ParentPIDBuffer;
    list<QString> PNameBuffer;
    list<int> ThreadCountBuffer;

    bool isUser = false;

    hProcessSnap = CreateToolhelp32Snapshot( TH32CS_SNAPPROCESS, 0);

    pe32.dwSize = sizeof(PROCESSENTRY32);

    if(!Process32First(hProcessSnap, &pe32)){
        CloseHandle(hProcessSnap);
    }

    do{
        QString PID, PName, threadCount, parentPID, prioBase, prioClass;
        dwPriorityClass = 0;
        hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pe32.th32ProcessID);

        if(hProcess == NULL) {
            isUser = false;
            CloseHandle(hProcess);
        }else{
            isUser = true;
            dwPriorityClass = GetPriorityClass(hProcess);
            CloseHandle(hProcess);
        }

        PIDBuffer.push_back(pe32.th32ProcessID);
        PNameBuffer.push_back((QString)pe32.szExeFile);
        ThreadCountBuffer.push_back(pe32.cntThreads);
        processThreadCount[pe32.th32ProcessID] = pe32.cntThreads;
        ParentPIDBuffer.push_back(pe32.th32ParentProcessID);

        //check if the process is already in the map, and if not add it
        if(!ProcessMap.count(pe32.th32ProcessID)){
            if(ProcessMap.count(pe32.th32ParentProcessID) && (ProcessMap[pe32.th32ParentProcessID]->text(1) == (QString)pe32.szExeFile)){
                //is child
                qDebug() << "Adding sub-process: " << (QString)pe32.szExeFile << " (" << pe32.th32ProcessID << "), Child of (" << pe32.th32ParentProcessID << ")";
                AddSubProcess(ProcessMap[pe32.th32ParentProcessID],
                              pe32.th32ProcessID,
                              (QString)pe32.szExeFile,
                              isUser);
            } else{
                //is not child
                qDebug() << "Adding Process: " << (QString)pe32.szExeFile << " (" << pe32.th32ProcessID << ")";
                AddProcess(pe32.th32ProcessID,
                           (QString)pe32.szExeFile,
                           isUser);
            }
        }
    } while(Process32Next(hProcessSnap,&pe32));

    //Process Update , updates values stored within process cells each iteration
    for(auto process : ProcessMap){
        bool exists = false;
        //qDebug() << "Updating process " << process.second.uiObject->text(1);
        editProcess(process.second, process.first, false);
        if(isUserMap[process.first]){
            editProcess(OverviewMap[process.first], process.first, true);
        }
        for(unsigned int pid : PIDBuffer){
            if(process.first == pid){
                exists = true;
                break;
            }
        }
        if(!exists){
            qDebug() << "Removing process (pID): " << process.second->text(2) << ", " << process.second->text(1);
            RemoveProcess(process.second, isUserMap[process.first]);
            ProcessMap.erase(process.first);
            OverviewMap.erase(process.first);
            isUserMap.erase(process.first);
            processUsageCPU.erase(process.first);
            processUsageMEM.erase(process.first);
        }
    }
    ui->UserProcesses->sortByColumn(3, Qt::DescendingOrder);
    ui->OverviewProcesses->sortByColumn(2, Qt::DescendingOrder);
    ui->SystemProcesses->sortByColumn(3,Qt::DescendingOrder);
    CloseHandle(hProcessSnap);
}

void CuteMon::RemoveProcess(QTreeWidgetItem *process, bool isUser){
    for(int i = 0; i < process->childCount(); i++){
        RemoveProcess(process->child(i), isUser);
    }
    if(process->parent() != 0x0){
        qDebug() << "Removing child";
        process->parent()->removeChild(process);
    } else{
        list<QString> checkList;
        if(isUser){
            for(int i = 0; i < ui->UserProcesses->topLevelItemCount(); i++){
                qDebug() << "check" << ui->UserProcesses->topLevelItem(i)->text(1) << ", " << process->text(2);
                if(ui->UserProcesses->topLevelItem(i)->text(2) == process->text(2)){
                    ui->UserProcesses->takeTopLevelItem(i);
                }
            }

            for(int i = 0; i < ui->OverviewProcesses->topLevelItemCount(); i++){
                qDebug() << "check" << ui->OverviewProcesses->topLevelItem(i)->text(1) << ", " << process->text(2);
                if(ui->OverviewProcesses->topLevelItem(i)->text(1) == process->text(2)){
                    ui->OverviewProcesses->takeTopLevelItem(i);
                    return;
                }
            }

            qDebug() << "Could not find process in user list: " << process->text(2);
        } else{
            for(int i = 0; i < ui ->SystemProcesses->topLevelItemCount(); i++){
                checkList.push_back(ui->SystemProcesses->topLevelItem(i)->text(2));
                if(ui->SystemProcesses->topLevelItem(i)->text(2) == process->text(2)){
                    ui->SystemProcesses->takeTopLevelItem(i);
                    return;
                }
            }
            qDebug() << "Could not find process in system list: " << process->text(2);
        }
    }
}

void CuteMon::AddProcess(unsigned int PID, QString PName, bool isUser){
    QTreeWidgetItem *itm = new QTreeWidgetItem();
    itm->setText(1,PName);
    if(isUser){
        ui->UserProcesses->addTopLevelItem(itm);
        QTreeWidgetItem *itm2 = new QTreeWidgetItem();
        itm2->setText(0,PName);
        ui->OverviewProcesses->addTopLevelItem(itm2);
        OverviewMap[PID] = itm2;
    } else ui->SystemProcesses->addTopLevelItem(itm);

    isUserMap[PID] = isUser;
    ProcessMap[PID] = itm;
}
void CuteMon::AddSubProcess(QTreeWidgetItem *parent , unsigned int PID, QString PName, bool isUser){
    QTreeWidgetItem *itm = new QTreeWidgetItem();
    itm->setText(1,PName);
    parent->addChild(itm);

    ProcessMap[PID] = itm;
}




int g_R = 130;
int g_G = 130;
int g_B = 130;

QString R = "130";
QString G = "130";
QString B = "130";
QTreeWidgetItem *currentItem;

void CuteMon::on_REDSLIDER_valueChanged(int value)
{
    g_R = value;
    R = QString::fromStdString(std::to_string(g_R));
    ui->RED->setText("Red:    " + R);
    ui->COLOURDISPLAY->setStyleSheet("background:rgb(" + R + "," + G + "," + B + ");");
}
void CuteMon::on_GREENSLIDER_valueChanged(int value)
{
    g_G = value;
    G = QString::fromStdString(std::to_string(g_G));
    ui->COLOURDISPLAY->setStyleSheet("background:rgb(" + R + "," + G + "," + B + ");");
    ui->GREEN->setText("Green: " + G);
}
void CuteMon::on_BLUESLIDER_valueChanged(int value)
{
    g_B = value;
    B = QString::fromStdString(std::to_string(g_B));
    ui->COLOURDISPLAY->setStyleSheet("background:rgb(" + R + "," + G + "," + B + ");");
    ui->BLUE->setText("Blue:   " + B);
}
void CuteMon::on_OKBUTTON_pressed()
{
    if(currentItem != NULL){
        int itemQueried = catSelector[currentItem->text(0)];
        qDebug() << itemQueried;
        g_pA[itemQueried][0] = g_R;
        g_pA[itemQueried][1] = g_G;
        g_pA[itemQueried][2] = g_B;

        //determine what ui object needs altering and perform that alteration

        if(itemQueried == 0){
            //global text
            setGlobalText();
            plotDarkMode(g_ramPlot);
            plotDarkMode(g_cpuPlot);
            plotDarkMode(g_NETPLOT);
            g_netPlot->legend->setTextColor(QColor(g_R,g_G,g_B));
            titleArr[0]->setTextColor(QColor(g_R,g_G,g_B));
            titleArr[1]->setTextColor(QColor(g_R,g_G,g_B));
            titleArr[2]->setTextColor(QColor(g_R,g_G,g_B));

        } else if(itemQueried == 1){
            //global background
            setGlobalBack();
            plotDarkMode(g_ramPlot);
            plotDarkMode(g_cpuPlot);
            plotDarkMode(g_NETPLOT);
            plotHideAxis(g_o_cpuPlot, QColor(g_pA[CBORD][0],g_pA[CBORD][1],g_pA[CBORD][2]));
            plotHideAxis(g_o_memPlot, QColor(g_pA[MBORD][0],g_pA[MBORD][1],g_pA[MBORD][2]));
            plotHideAxis(g_netPlot, QColor(g_pA[NBORD][0],g_pA[NBORD][1],g_pA[NBORD][2]));
        } else if(itemQueried < 6){
            //tab edit
            setTabBack();
            setFrameBorders();
        } else if(itemQueried < 9){
            //cpu edit
            plotSetColor(g_o_cpuPlot,g_pA[CLINE][0],g_pA[CLINE][1],g_pA[CLINE][2],20,0, true);
            plotSetColor(g_cpuPlot,g_pA[CLINE][0],g_pA[CLINE][1],g_pA[CLINE][2],20,0,true);

            plotHideAxis(g_o_cpuPlot, QColor(g_pA[CBORD][0],g_pA[CBORD][1],g_pA[CBORD][2]));
        } else if(itemQueried < 12){
            //mem edit
            plotSetColor(g_ramPlot,g_pA[MLINE][0],g_pA[MLINE][1],g_pA[MLINE][2],20,0,true);
            plotSetColor(g_o_memPlot,g_pA[MLINE][0],g_pA[MLINE][1],g_pA[MLINE][2],20,0,true);

            plotHideAxis(g_o_memPlot, QColor(g_pA[MBORD][0],g_pA[MBORD][1],g_pA[MBORD][2]));
        } else if(itemQueried < 16){
            //net edit
            plotSetColor(g_netPlot,g_pA[NLINE1][0],g_pA[NLINE1][1],g_pA[NLINE1][2],20, 0, true);
            plotSetColor(g_netPlot,g_pA[NLINE2][0],g_pA[NLINE2][1],g_pA[NLINE2][2],20,1, false);
            plotSetColor(g_NETPLOT,g_pA[NLINE1][0],g_pA[NLINE1][1],g_pA[NLINE1][2],20,0,true);
            plotSetColor(g_NETPLOT,g_pA[NLINE2][0],g_pA[NLINE2][1],g_pA[NLINE2][2],20,1,false);

            plotHideAxis(g_netPlot, QColor(g_pA[NBORD][0],g_pA[NBORD][1],g_pA[NBORD][2]));
        } else{
            //process edit
        }


        QFile configFile("config.txt");
        if(!configFile.open(QIODevice::ReadOnly | QIODevice::Text)){
            qDebug() << "config failed to open...";
        }
        QTextStream in(&configFile);
        QStringList lines;
        while(!in.atEnd()){
            lines.push_back(in.readLine());
        }
        configFile.close();

        if(!configFile.open(QIODevice::WriteOnly | QIODevice::Text)){
            qDebug() << "Failed to write to file...";
        }

        QTextStream out(&configFile);
        for(QString line : lines){
            QString index = line[0];
            if(line[1] != " ") index += line[1];
            if(index == toString(itemQueried)){
                QStringList procLine = line.split(":");
                procLine[1] = toString(g_R) + "," + toString(g_G) + "," + toString(g_B);
                line = procLine[0] + ":" + procLine[1];
            }
            out << line << "\n";
        }
        configFile.close();
    }
}

void CuteMon::on_catagoryTree_itemClicked(QTreeWidgetItem *item, int column)
{
    if(item->parent() != 0x0){
        qDebug() << "Selected: " << item->text(column);
        ui->CURRENTSELECTED->setText("Color Edit - " + item->parent()->text(column) + " - " + item->text(column));
        currentItem = item;
        R = toString(g_pA[catSelector[currentItem->text(0)]][0]);
        G = toString(g_pA[catSelector[currentItem->text(0)]][1]);
        B = toString(g_pA[catSelector[currentItem->text(0)]][2]);
        ui->REDSLIDER->setValue(g_pA[catSelector[currentItem->text(0)]][0]);
        ui->GREENSLIDER->setValue(g_pA[catSelector[currentItem->text(0)]][1]);
        ui->BLUESLIDER->setValue(g_pA[catSelector[currentItem->text(0)]][2]);
        ui->COLOURDISPLAY->setStyleSheet("background:rgb(" + R + "," + G + "," + B + ");");
    }
}

