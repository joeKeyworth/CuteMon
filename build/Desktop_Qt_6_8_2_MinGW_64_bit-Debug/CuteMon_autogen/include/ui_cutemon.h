/********************************************************************************
** Form generated from reading UI file 'cutemon.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUTEMON_H
#define UI_CUTEMON_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CuteMon
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTabWidget *tab_0;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_4;
    QFrame *CPUFRAME;
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout_7;
    QFrame *frame_8;
    QGridLayout *gridLayout_2;
    QCustomPlot *CPUPLOT;
    QFrame *line;
    QFrame *frame_7;
    QVBoxLayout *verticalLayout_12;
    QLabel *o_cpuName;
    QLabel *o_coreCount;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_3;
    QLabel *o_cpu_percentage;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_16;
    QHBoxLayout *horizontalLayout_2;
    QFrame *MEMFRAME;
    QHBoxLayout *horizontalLayout_3;
    QFrame *frame_9;
    QGridLayout *gridLayout_3;
    QCustomPlot *MEMPLOT;
    QFrame *line_2;
    QFrame *frame_6;
    QVBoxLayout *verticalLayout_11;
    QLabel *o_mem_total;
    QLabel *o_mem_used;
    QLabel *o_mem_percentage;
    QLabel *o_mem_avai;
    QLabel *o_avai_percentage;
    QSpacerItem *verticalSpacer;
    QFrame *NETFRAME;
    QHBoxLayout *horizontalLayout_4;
    QFrame *frame_10;
    QGridLayout *gridLayout_4;
    QCustomPlot *netPlot;
    QFrame *line_3;
    QFrame *frame_5;
    QVBoxLayout *verticalLayout_9;
    QLabel *o_download;
    QLabel *o_download_value;
    QLabel *o_peak_download;
    QLabel *o_peak_down_val;
    QSpacerItem *verticalSpacer_3;
    QLabel *o_upload;
    QLabel *o_upload_val;
    QLabel *o_peak_upload;
    QLabel *o_peak_up_val;
    QTreeWidget *OverviewProcesses;
    QWidget *tab;
    QVBoxLayout *verticalLayout_8;
    QLabel *CPU;
    QVBoxLayout *verticalLayout_6;
    QCustomPlot *CPUplot;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_13;
    QLabel *cpuName;
    QLabel *coreCount;
    QSpacerItem *verticalSpacer_5;
    QLabel *CPUTEXT;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_8;
    QTreeWidget *CoreTable_3;
    QTreeWidget *CoreTable_2;
    QTreeWidget *CoreTable;
    QWidget *tab_2;
    QFormLayout *formLayout_4;
    QVBoxLayout *verticalLayout_14;
    QLabel *label;
    QCustomPlot *RAMplot;
    QHBoxLayout *horizontalLayout_9;
    QVBoxLayout *verticalLayout_15;
    QLabel *RAM;
    QLabel *RAMTEXT;
    QLabel *ramTotal;
    QLabel *Avai;
    QLabel *Used;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *verticalSpacer_6;
    QWidget *tab_4;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_10;
    QLabel *label_2;
    QCustomPlot *NETPLOT;
    QHBoxLayout *horizontalLayout_11;
    QVBoxLayout *verticalLayout_17;
    QLabel *netName;
    QLabel *SSID;
    QLabel *CONN_TYPE;
    QLabel *IPV4ADDR;
    QLabel *IPV6ADDR;
    QLabel *SIGSTR;
    QSpacerItem *verticalSpacer_7;
    QVBoxLayout *verticalLayout_19;
    QLabel *AUTHTYPE;
    QLabel *PHYSADDR;
    QSpacerItem *verticalSpacer_9;
    QVBoxLayout *verticalLayout_18;
    QLabel *label_10;
    QLabel *UPVAL;
    QLabel *label_12;
    QLabel *DOWNVAL;
    QSpacerItem *verticalSpacer_8;
    QWidget *tab_6;
    QVBoxLayout *verticalLayout;
    QTreeWidget *UserProcesses;
    QTreeWidget *SystemProcesses;
    QWidget *tab_7;
    QVBoxLayout *verticalLayout_20;
    QHBoxLayout *horizontalLayout_12;
    QTreeWidget *catagoryTree;
    QVBoxLayout *verticalLayout_21;
    QLabel *CURRENTSELECTED;
    QFormLayout *formLayout;
    QLabel *RED;
    QSlider *REDSLIDER;
    QLabel *GREEN;
    QSlider *GREENSLIDER;
    QLabel *BLUE;
    QSlider *BLUESLIDER;
    QFrame *COLOURDISPLAY;
    QHBoxLayout *horizontalLayout_13;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *OKBUTTON;
    QFrame *line_4;
    QSpacerItem *verticalSpacer_10;

    void setupUi(QMainWindow *CuteMon)
    {
        if (CuteMon->objectName().isEmpty())
            CuteMon->setObjectName("CuteMon");
        CuteMon->resize(966, 705);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CuteMon->sizePolicy().hasHeightForWidth());
        CuteMon->setSizePolicy(sizePolicy);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(40, 40, 40, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(18, 18, 18, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush1);
        QBrush brush3(QColor(63, 63, 63, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush3);
        QBrush brush4(QColor(87, 87, 87, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush4);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush5(QColor(21, 21, 21, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush5);
        QBrush brush6(QColor(234, 152, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Highlight, brush6);
        QBrush brush7(QColor(170, 0, 255, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Link, brush7);
        QBrush brush8(QColor(170, 85, 255, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::LinkVisited, brush8);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush3);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush3);
        QBrush brush9(QColor(98, 75, 158, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Accent, brush9);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Highlight, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Link, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::LinkVisited, brush8);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Accent, brush9);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush5);
        QBrush brush10(QColor(170, 170, 255, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Highlight, brush10);
        palette.setBrush(QPalette::Disabled, QPalette::Link, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::LinkVisited, brush8);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Accent, brush9);
        CuteMon->setPalette(palette);
        QIcon icon;
        icon.addFile(QString::fromUtf8("CuteMon.ico"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        CuteMon->setWindowIcon(icon);
        CuteMon->setStyleSheet(QString::fromUtf8("background-color:rgb(40, 40, 40)"));
        centralwidget = new QWidget(CuteMon);
        centralwidget->setObjectName("centralwidget");
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush3);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush4);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush5);
        palette1.setBrush(QPalette::Active, QPalette::Highlight, brush6);
        palette1.setBrush(QPalette::Active, QPalette::Link, brush7);
        palette1.setBrush(QPalette::Active, QPalette::LinkVisited, brush8);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush3);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush3);
        palette1.setBrush(QPalette::Active, QPalette::Accent, brush9);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush5);
        palette1.setBrush(QPalette::Inactive, QPalette::Highlight, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::Link, brush7);
        palette1.setBrush(QPalette::Inactive, QPalette::LinkVisited, brush8);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Accent, brush9);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush5);
        palette1.setBrush(QPalette::Disabled, QPalette::Highlight, brush10);
        palette1.setBrush(QPalette::Disabled, QPalette::Link, brush7);
        palette1.setBrush(QPalette::Disabled, QPalette::LinkVisited, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Accent, brush9);
        centralwidget->setPalette(palette1);
        centralwidget->setStyleSheet(QString::fromUtf8(""));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        tab_0 = new QTabWidget(centralwidget);
        tab_0->setObjectName("tab_0");
        sizePolicy.setHeightForWidth(tab_0->sizePolicy().hasHeightForWidth());
        tab_0->setSizePolicy(sizePolicy);
        tab_0->setAcceptDrops(false);
        tab_0->setAutoFillBackground(false);
        tab_0->setStyleSheet(QString::fromUtf8(""));
        tab_0->setTabShape(QTabWidget::TabShape::Rounded);
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        tab_3->setStyleSheet(QString::fromUtf8("color:white;"));
        verticalLayout_3 = new QVBoxLayout(tab_3);
        verticalLayout_3->setObjectName("verticalLayout_3");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(-1, -1, 0, -1);
        CPUFRAME = new QFrame(tab_3);
        CPUFRAME->setObjectName("CPUFRAME");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(CPUFRAME->sizePolicy().hasHeightForWidth());
        CPUFRAME->setSizePolicy(sizePolicy1);
        CPUFRAME->setStyleSheet(QString::fromUtf8(" border-top: 2px solid rgba(111,131,199, 1);\n"
" border-left: 2px solid rgba(111,131,199, 1);\n"
" border-bottom: 2px solid rgba(61,81,149, 1);\n"
" border-right: 2px solid rgba(61,81,149, 1);\n"
""));
        CPUFRAME->setFrameShape(QFrame::Shape::StyledPanel);
        CPUFRAME->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_7 = new QHBoxLayout(CPUFRAME);
        horizontalLayout_7->setSpacing(0);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName("verticalLayout_7");

        horizontalLayout_7->addLayout(verticalLayout_7);

        frame_8 = new QFrame(CPUFRAME);
        frame_8->setObjectName("frame_8");
        frame_8->setStyleSheet(QString::fromUtf8("border: none;"));
        frame_8->setFrameShape(QFrame::Shape::StyledPanel);
        frame_8->setFrameShadow(QFrame::Shadow::Sunken);
        gridLayout_2 = new QGridLayout(frame_8);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setSizeConstraint(QLayout::SizeConstraint::SetNoConstraint);
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        CPUPLOT = new QCustomPlot(frame_8);
        CPUPLOT->setObjectName("CPUPLOT");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(CPUPLOT->sizePolicy().hasHeightForWidth());
        CPUPLOT->setSizePolicy(sizePolicy2);
        CPUPLOT->setStyleSheet(QString::fromUtf8("border: none;"));

        gridLayout_2->addWidget(CPUPLOT, 0, 0, 1, 1);


        horizontalLayout_7->addWidget(frame_8);

        line = new QFrame(CPUFRAME);
        line->setObjectName("line");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(line->sizePolicy().hasHeightForWidth());
        line->setSizePolicy(sizePolicy3);
        line->setStyleSheet(QString::fromUtf8("border-top:none; border-bottom:none; border-left:none;"));
        line->setFrameShadow(QFrame::Shadow::Sunken);
        line->setLineWidth(1);
        line->setFrameShape(QFrame::Shape::VLine);

        horizontalLayout_7->addWidget(line);

        frame_7 = new QFrame(CPUFRAME);
        frame_7->setObjectName("frame_7");
        sizePolicy.setHeightForWidth(frame_7->sizePolicy().hasHeightForWidth());
        frame_7->setSizePolicy(sizePolicy);
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush11(QColor(255, 255, 255, 128));
        brush11.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Active, QPalette::PlaceholderText, brush11);
#endif
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush11);
#endif
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush11);
#endif
        frame_7->setPalette(palette2);
        frame_7->setStyleSheet(QString::fromUtf8("border: none;"));
        frame_7->setFrameShape(QFrame::Shape::StyledPanel);
        frame_7->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_12 = new QVBoxLayout(frame_7);
        verticalLayout_12->setObjectName("verticalLayout_12");
        o_cpuName = new QLabel(frame_7);
        o_cpuName->setObjectName("o_cpuName");
        QFont font;
        font.setPointSize(11);
        o_cpuName->setFont(font);
        o_cpuName->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout_12->addWidget(o_cpuName);

        o_coreCount = new QLabel(frame_7);
        o_coreCount->setObjectName("o_coreCount");
        o_coreCount->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout_12->addWidget(o_coreCount);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_12->addItem(verticalSpacer_2);

        label_3 = new QLabel(frame_7);
        label_3->setObjectName("label_3");
        label_3->setFont(font);

        verticalLayout_12->addWidget(label_3);

        o_cpu_percentage = new QLabel(frame_7);
        o_cpu_percentage->setObjectName("o_cpu_percentage");
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(o_cpu_percentage->sizePolicy().hasHeightForWidth());
        o_cpu_percentage->setSizePolicy(sizePolicy4);
        o_cpu_percentage->setMinimumSize(QSize(100, 0));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Active, QPalette::PlaceholderText, brush11);
#endif
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush11);
#endif
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush11);
#endif
        o_cpu_percentage->setPalette(palette3);
        o_cpu_percentage->setFont(font);
        o_cpu_percentage->setStyleSheet(QString::fromUtf8("border:none;"));
        o_cpu_percentage->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout_12->addWidget(o_cpu_percentage);


        horizontalLayout_7->addWidget(frame_7);


        verticalLayout_4->addWidget(CPUFRAME);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        verticalLayout_16 = new QVBoxLayout();
        verticalLayout_16->setObjectName("verticalLayout_16");
        verticalLayout_16->setSizeConstraint(QLayout::SizeConstraint::SetDefaultConstraint);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        MEMFRAME = new QFrame(tab_3);
        MEMFRAME->setObjectName("MEMFRAME");
        QSizePolicy sizePolicy5(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Expanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(MEMFRAME->sizePolicy().hasHeightForWidth());
        MEMFRAME->setSizePolicy(sizePolicy5);
        MEMFRAME->setMinimumSize(QSize(0, 0));
        MEMFRAME->setStyleSheet(QString::fromUtf8(" border-top: 2px solid rgba(255,185,185, 1);\n"
" border-left: 2px solid rgba(255,185,185, 1);\n"
" border-right: 2px solid rgba(205,135,135, 1);\n"
" border-bottom: 2px solid rgba(205,135,135, 1);"));
        MEMFRAME->setFrameShape(QFrame::Shape::StyledPanel);
        MEMFRAME->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_3 = new QHBoxLayout(MEMFRAME);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        frame_9 = new QFrame(MEMFRAME);
        frame_9->setObjectName("frame_9");
        frame_9->setStyleSheet(QString::fromUtf8("border: none;"));
        frame_9->setFrameShape(QFrame::Shape::StyledPanel);
        frame_9->setFrameShadow(QFrame::Shadow::Raised);
        gridLayout_3 = new QGridLayout(frame_9);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        MEMPLOT = new QCustomPlot(frame_9);
        MEMPLOT->setObjectName("MEMPLOT");
        sizePolicy5.setHeightForWidth(MEMPLOT->sizePolicy().hasHeightForWidth());
        MEMPLOT->setSizePolicy(sizePolicy5);

        gridLayout_3->addWidget(MEMPLOT, 0, 0, 1, 1);


        horizontalLayout_3->addWidget(frame_9);

        line_2 = new QFrame(MEMFRAME);
        line_2->setObjectName("line_2");
        QSizePolicy sizePolicy6(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Expanding);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(line_2->sizePolicy().hasHeightForWidth());
        line_2->setSizePolicy(sizePolicy6);
        line_2->setStyleSheet(QString::fromUtf8("border-top:none; border-bottom:none; border-left:none;"));
        line_2->setFrameShape(QFrame::Shape::VLine);
        line_2->setFrameShadow(QFrame::Shadow::Sunken);

        horizontalLayout_3->addWidget(line_2);

        frame_6 = new QFrame(MEMFRAME);
        frame_6->setObjectName("frame_6");
        sizePolicy6.setHeightForWidth(frame_6->sizePolicy().hasHeightForWidth());
        frame_6->setSizePolicy(sizePolicy6);
        frame_6->setStyleSheet(QString::fromUtf8("border: none;"));
        frame_6->setFrameShape(QFrame::Shape::StyledPanel);
        frame_6->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_11 = new QVBoxLayout(frame_6);
        verticalLayout_11->setObjectName("verticalLayout_11");
        o_mem_total = new QLabel(frame_6);
        o_mem_total->setObjectName("o_mem_total");
        QSizePolicy sizePolicy7(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Preferred);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(o_mem_total->sizePolicy().hasHeightForWidth());
        o_mem_total->setSizePolicy(sizePolicy7);
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Active, QPalette::PlaceholderText, brush11);
#endif
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush11);
#endif
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush11);
#endif
        o_mem_total->setPalette(palette4);
        o_mem_total->setFont(font);
        o_mem_total->setStyleSheet(QString::fromUtf8("border: none;"));
        o_mem_total->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout_11->addWidget(o_mem_total);

        o_mem_used = new QLabel(frame_6);
        o_mem_used->setObjectName("o_mem_used");
        o_mem_used->setFont(font);
        o_mem_used->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout_11->addWidget(o_mem_used);

        o_mem_percentage = new QLabel(frame_6);
        o_mem_percentage->setObjectName("o_mem_percentage");
        sizePolicy4.setHeightForWidth(o_mem_percentage->sizePolicy().hasHeightForWidth());
        o_mem_percentage->setSizePolicy(sizePolicy4);
        o_mem_percentage->setMinimumSize(QSize(0, 0));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette5.setBrush(QPalette::Active, QPalette::Text, brush);
        palette5.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette5.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette5.setBrush(QPalette::Active, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Active, QPalette::PlaceholderText, brush11);
#endif
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush11);
#endif
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush11);
#endif
        o_mem_percentage->setPalette(palette5);
        o_mem_percentage->setFont(font);
        o_mem_percentage->setStyleSheet(QString::fromUtf8("border: none;"));
        o_mem_percentage->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout_11->addWidget(o_mem_percentage);

        o_mem_avai = new QLabel(frame_6);
        o_mem_avai->setObjectName("o_mem_avai");
        o_mem_avai->setFont(font);

        verticalLayout_11->addWidget(o_mem_avai);

        o_avai_percentage = new QLabel(frame_6);
        o_avai_percentage->setObjectName("o_avai_percentage");
        o_avai_percentage->setFont(font);
        o_avai_percentage->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout_11->addWidget(o_avai_percentage);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_11->addItem(verticalSpacer);


        horizontalLayout_3->addWidget(frame_6);


        horizontalLayout_2->addWidget(MEMFRAME);

        horizontalLayout_2->setStretch(0, 5);

        verticalLayout_16->addLayout(horizontalLayout_2);

        NETFRAME = new QFrame(tab_3);
        NETFRAME->setObjectName("NETFRAME");
        sizePolicy5.setHeightForWidth(NETFRAME->sizePolicy().hasHeightForWidth());
        NETFRAME->setSizePolicy(sizePolicy5);
        NETFRAME->setMinimumSize(QSize(0, 0));
        NETFRAME->setStyleSheet(QString::fromUtf8("border-top:2px solid rgba(199,111,111, 1);\n"
"border-left:2px solid rgba(199,111,111, 1);\n"
"border-bottom:2px solid rgba(149,61,61, 1);\n"
"border-right:2px solid rgba(149,61,61, 1);\n"
""));
        NETFRAME->setFrameShape(QFrame::Shape::StyledPanel);
        NETFRAME->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_4 = new QHBoxLayout(NETFRAME);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        frame_10 = new QFrame(NETFRAME);
        frame_10->setObjectName("frame_10");
        frame_10->setStyleSheet(QString::fromUtf8("border: none;"));
        frame_10->setFrameShape(QFrame::Shape::StyledPanel);
        frame_10->setFrameShadow(QFrame::Shadow::Raised);
        gridLayout_4 = new QGridLayout(frame_10);
        gridLayout_4->setSpacing(0);
        gridLayout_4->setObjectName("gridLayout_4");
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        netPlot = new QCustomPlot(frame_10);
        netPlot->setObjectName("netPlot");
        sizePolicy5.setHeightForWidth(netPlot->sizePolicy().hasHeightForWidth());
        netPlot->setSizePolicy(sizePolicy5);
        netPlot->setStyleSheet(QString::fromUtf8("border: none;"));

        gridLayout_4->addWidget(netPlot, 0, 0, 1, 1);


        horizontalLayout_4->addWidget(frame_10);

        line_3 = new QFrame(NETFRAME);
        line_3->setObjectName("line_3");
        line_3->setEnabled(true);
        QSizePolicy sizePolicy8(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Expanding);
        sizePolicy8.setHorizontalStretch(1);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(line_3->sizePolicy().hasHeightForWidth());
        line_3->setSizePolicy(sizePolicy8);
        line_3->setMinimumSize(QSize(1, 0));
        line_3->setStyleSheet(QString::fromUtf8("border-top:none; border-bottom:none; border-left:none;"));
        line_3->setFrameShadow(QFrame::Shadow::Plain);
        line_3->setLineWidth(0);
        line_3->setFrameShape(QFrame::Shape::VLine);

        horizontalLayout_4->addWidget(line_3);

        frame_5 = new QFrame(NETFRAME);
        frame_5->setObjectName("frame_5");
        sizePolicy6.setHeightForWidth(frame_5->sizePolicy().hasHeightForWidth());
        frame_5->setSizePolicy(sizePolicy6);
        frame_5->setStyleSheet(QString::fromUtf8("border: none;"));
        frame_5->setFrameShape(QFrame::Shape::StyledPanel);
        frame_5->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_9 = new QVBoxLayout(frame_5);
        verticalLayout_9->setObjectName("verticalLayout_9");
        o_download = new QLabel(frame_5);
        o_download->setObjectName("o_download");
        sizePolicy7.setHeightForWidth(o_download->sizePolicy().hasHeightForWidth());
        o_download->setSizePolicy(sizePolicy7);
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette6.setBrush(QPalette::Active, QPalette::Text, brush);
        palette6.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette6.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette6.setBrush(QPalette::Active, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette6.setBrush(QPalette::Active, QPalette::PlaceholderText, brush11);
#endif
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette6.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush11);
#endif
        palette6.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette6.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush11);
#endif
        o_download->setPalette(palette6);
        o_download->setFont(font);
        o_download->setStyleSheet(QString::fromUtf8("border: none;"));
        o_download->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_9->addWidget(o_download);

        o_download_value = new QLabel(frame_5);
        o_download_value->setObjectName("o_download_value");
        o_download_value->setTextFormat(Qt::TextFormat::AutoText);
        o_download_value->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout_9->addWidget(o_download_value);

        o_peak_download = new QLabel(frame_5);
        o_peak_download->setObjectName("o_peak_download");
        sizePolicy4.setHeightForWidth(o_peak_download->sizePolicy().hasHeightForWidth());
        o_peak_download->setSizePolicy(sizePolicy4);
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette7.setBrush(QPalette::Active, QPalette::Text, brush);
        palette7.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette7.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette7.setBrush(QPalette::Active, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette7.setBrush(QPalette::Active, QPalette::PlaceholderText, brush11);
#endif
        palette7.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette7.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette7.setBrush(QPalette::Inactive, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette7.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush11);
#endif
        palette7.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette7.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette7.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette7.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush11);
#endif
        o_peak_download->setPalette(palette7);
        o_peak_download->setFont(font);
        o_peak_download->setStyleSheet(QString::fromUtf8("border: none;"));
        o_peak_download->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout_9->addWidget(o_peak_download);

        o_peak_down_val = new QLabel(frame_5);
        o_peak_down_val->setObjectName("o_peak_down_val");
        o_peak_down_val->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout_9->addWidget(o_peak_down_val);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_9->addItem(verticalSpacer_3);

        o_upload = new QLabel(frame_5);
        o_upload->setObjectName("o_upload");
        sizePolicy4.setHeightForWidth(o_upload->sizePolicy().hasHeightForWidth());
        o_upload->setSizePolicy(sizePolicy4);
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette8.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette8.setBrush(QPalette::Active, QPalette::Text, brush);
        palette8.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette8.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette8.setBrush(QPalette::Active, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette8.setBrush(QPalette::Active, QPalette::PlaceholderText, brush11);
#endif
        palette8.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette8.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette8.setBrush(QPalette::Inactive, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette8.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush11);
#endif
        palette8.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette8.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette8.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette8.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette8.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette8.setBrush(QPalette::Disabled, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette8.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush11);
#endif
        o_upload->setPalette(palette8);
        o_upload->setFont(font);
        o_upload->setStyleSheet(QString::fromUtf8("border: none;"));
        o_upload->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout_9->addWidget(o_upload);

        o_upload_val = new QLabel(frame_5);
        o_upload_val->setObjectName("o_upload_val");
        o_upload_val->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout_9->addWidget(o_upload_val);

        o_peak_upload = new QLabel(frame_5);
        o_peak_upload->setObjectName("o_peak_upload");
        o_peak_upload->setFont(font);
        o_peak_upload->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout_9->addWidget(o_peak_upload);

        o_peak_up_val = new QLabel(frame_5);
        o_peak_up_val->setObjectName("o_peak_up_val");
        o_peak_up_val->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout_9->addWidget(o_peak_up_val);

        verticalLayout_9->setStretch(0, 1);
        verticalLayout_9->setStretch(1, 1);
        verticalLayout_9->setStretch(2, 1);
        verticalLayout_9->setStretch(3, 1);
        verticalLayout_9->setStretch(4, 1);
        verticalLayout_9->setStretch(5, 1);
        verticalLayout_9->setStretch(6, 1);
        verticalLayout_9->setStretch(7, 1);
        verticalLayout_9->setStretch(8, 1);

        horizontalLayout_4->addWidget(frame_5);


        verticalLayout_16->addWidget(NETFRAME);

        verticalLayout_16->setStretch(0, 2);
        verticalLayout_16->setStretch(1, 3);

        horizontalLayout_6->addLayout(verticalLayout_16);

        OverviewProcesses = new QTreeWidget(tab_3);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(3, QString::fromUtf8("4"));
        __qtreewidgetitem->setText(2, QString::fromUtf8("3"));
        __qtreewidgetitem->setText(1, QString::fromUtf8("2"));
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        OverviewProcesses->setHeaderItem(__qtreewidgetitem);
        OverviewProcesses->setObjectName("OverviewProcesses");
        OverviewProcesses->setEnabled(true);
        sizePolicy.setHeightForWidth(OverviewProcesses->sizePolicy().hasHeightForWidth());
        OverviewProcesses->setSizePolicy(sizePolicy);
        OverviewProcesses->setMinimumSize(QSize(0, 0));
        QPalette palette9;
        palette9.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette9.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette9.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette9.setBrush(QPalette::Active, QPalette::Midlight, brush1);
        palette9.setBrush(QPalette::Active, QPalette::Dark, brush3);
        palette9.setBrush(QPalette::Active, QPalette::Mid, brush4);
        palette9.setBrush(QPalette::Active, QPalette::Text, brush);
        palette9.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette9.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette9.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette9.setBrush(QPalette::Active, QPalette::Shadow, brush5);
        palette9.setBrush(QPalette::Active, QPalette::Highlight, brush6);
        palette9.setBrush(QPalette::Active, QPalette::Link, brush7);
        palette9.setBrush(QPalette::Active, QPalette::LinkVisited, brush8);
        palette9.setBrush(QPalette::Active, QPalette::AlternateBase, brush3);
        palette9.setBrush(QPalette::Active, QPalette::ToolTipBase, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette9.setBrush(QPalette::Active, QPalette::PlaceholderText, brush11);
#endif
        palette9.setBrush(QPalette::Active, QPalette::Accent, brush9);
        palette9.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette9.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette9.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
        palette9.setBrush(QPalette::Inactive, QPalette::Dark, brush3);
        palette9.setBrush(QPalette::Inactive, QPalette::Mid, brush4);
        palette9.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette9.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette9.setBrush(QPalette::Inactive, QPalette::Shadow, brush5);
        palette9.setBrush(QPalette::Inactive, QPalette::Highlight, brush6);
        palette9.setBrush(QPalette::Inactive, QPalette::Link, brush7);
        palette9.setBrush(QPalette::Inactive, QPalette::LinkVisited, brush8);
        palette9.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush3);
        palette9.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette9.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush11);
#endif
        palette9.setBrush(QPalette::Inactive, QPalette::Accent, brush9);
        palette9.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette9.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette9.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette9.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
        palette9.setBrush(QPalette::Disabled, QPalette::Dark, brush3);
        palette9.setBrush(QPalette::Disabled, QPalette::Mid, brush4);
        palette9.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette9.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        palette9.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette9.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette9.setBrush(QPalette::Disabled, QPalette::Shadow, brush5);
        palette9.setBrush(QPalette::Disabled, QPalette::Highlight, brush10);
        palette9.setBrush(QPalette::Disabled, QPalette::Link, brush7);
        palette9.setBrush(QPalette::Disabled, QPalette::LinkVisited, brush8);
        palette9.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush3);
        palette9.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette9.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush11);
#endif
        palette9.setBrush(QPalette::Disabled, QPalette::Accent, brush9);
        OverviewProcesses->setPalette(palette9);
        QFont font1;
        font1.setPointSize(10);
        OverviewProcesses->setFont(font1);
        OverviewProcesses->setAutoFillBackground(false);
        OverviewProcesses->setStyleSheet(QString::fromUtf8(" border: 1px solid black; "));
        OverviewProcesses->setFrameShape(QFrame::Shape::StyledPanel);
        OverviewProcesses->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        OverviewProcesses->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        OverviewProcesses->setSizeAdjustPolicy(QAbstractScrollArea::SizeAdjustPolicy::AdjustIgnored);
        OverviewProcesses->setAutoScroll(true);
        OverviewProcesses->setIndentation(0);
        OverviewProcesses->setRootIsDecorated(true);
        OverviewProcesses->setSortingEnabled(false);
        OverviewProcesses->setHeaderHidden(false);
        OverviewProcesses->setColumnCount(4);
        OverviewProcesses->header()->setVisible(true);
        OverviewProcesses->header()->setCascadingSectionResizes(false);
        OverviewProcesses->header()->setMinimumSectionSize(32);
        OverviewProcesses->header()->setDefaultSectionSize(100);
        OverviewProcesses->header()->setHighlightSections(true);
        OverviewProcesses->header()->setProperty("showSortIndicator", QVariant(false));
        OverviewProcesses->header()->setStretchLastSection(true);

        horizontalLayout_6->addWidget(OverviewProcesses);

        horizontalLayout_6->setStretch(0, 5);
        horizontalLayout_6->setStretch(1, 4);

        verticalLayout_4->addLayout(horizontalLayout_6);

        verticalLayout_4->setStretch(0, 3);
        verticalLayout_4->setStretch(1, 6);

        horizontalLayout->addLayout(verticalLayout_4);


        verticalLayout_3->addLayout(horizontalLayout);

        tab_0->addTab(tab_3, QString());
        tab = new QWidget();
        tab->setObjectName("tab");
        verticalLayout_8 = new QVBoxLayout(tab);
        verticalLayout_8->setObjectName("verticalLayout_8");
        CPU = new QLabel(tab);
        CPU->setObjectName("CPU");
        QFont font2;
        font2.setPointSize(22);
        CPU->setFont(font2);
        CPU->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_8->addWidget(CPU);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        CPUplot = new QCustomPlot(tab);
        CPUplot->setObjectName("CPUplot");
        sizePolicy2.setHeightForWidth(CPUplot->sizePolicy().hasHeightForWidth());
        CPUplot->setSizePolicy(sizePolicy2);

        verticalLayout_6->addWidget(CPUplot);


        verticalLayout_8->addLayout(verticalLayout_6);

        frame_2 = new QFrame(tab);
        frame_2->setObjectName("frame_2");
        sizePolicy.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy);
        frame_2->setFont(font);
        frame_2->setStyleSheet(QString::fromUtf8(""));
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_5 = new QHBoxLayout(frame_2);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setObjectName("verticalLayout_13");
        cpuName = new QLabel(frame_2);
        cpuName->setObjectName("cpuName");
        QFont font3;
        font3.setPointSize(13);
        cpuName->setFont(font3);

        verticalLayout_13->addWidget(cpuName);

        coreCount = new QLabel(frame_2);
        coreCount->setObjectName("coreCount");
        coreCount->setFont(font);

        verticalLayout_13->addWidget(coreCount);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_13->addItem(verticalSpacer_5);

        CPUTEXT = new QLabel(frame_2);
        CPUTEXT->setObjectName("CPUTEXT");
        CPUTEXT->setFont(font2);

        verticalLayout_13->addWidget(CPUTEXT);


        horizontalLayout_5->addLayout(verticalLayout_13);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_4 = new QLabel(frame_2);
        label_4->setObjectName("label_4");
        QFont font4;
        font4.setPointSize(12);
        label_4->setFont(font4);

        verticalLayout_2->addWidget(label_4);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        CoreTable_3 = new QTreeWidget(frame_2);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem();
        __qtreewidgetitem1->setText(1, QString::fromUtf8("2"));
        __qtreewidgetitem1->setText(0, QString::fromUtf8("1"));
        CoreTable_3->setHeaderItem(__qtreewidgetitem1);
        CoreTable_3->setObjectName("CoreTable_3");
        sizePolicy6.setHeightForWidth(CoreTable_3->sizePolicy().hasHeightForWidth());
        CoreTable_3->setSizePolicy(sizePolicy6);
        CoreTable_3->setMinimumSize(QSize(130, 100));
        CoreTable_3->setFont(font);
        CoreTable_3->setStyleSheet(QString::fromUtf8("border:none;"));
        CoreTable_3->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        CoreTable_3->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        CoreTable_3->setColumnCount(2);
        CoreTable_3->header()->setVisible(false);

        horizontalLayout_8->addWidget(CoreTable_3);

        CoreTable_2 = new QTreeWidget(frame_2);
        QTreeWidgetItem *__qtreewidgetitem2 = new QTreeWidgetItem();
        __qtreewidgetitem2->setText(1, QString::fromUtf8("2"));
        __qtreewidgetitem2->setText(0, QString::fromUtf8("1"));
        CoreTable_2->setHeaderItem(__qtreewidgetitem2);
        CoreTable_2->setObjectName("CoreTable_2");
        sizePolicy6.setHeightForWidth(CoreTable_2->sizePolicy().hasHeightForWidth());
        CoreTable_2->setSizePolicy(sizePolicy6);
        CoreTable_2->setMinimumSize(QSize(130, 100));
        CoreTable_2->setFont(font);
        CoreTable_2->setAutoFillBackground(false);
        CoreTable_2->setStyleSheet(QString::fromUtf8("border:none;"));
        CoreTable_2->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        CoreTable_2->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        CoreTable_2->setColumnCount(2);
        CoreTable_2->header()->setVisible(false);

        horizontalLayout_8->addWidget(CoreTable_2);

        CoreTable = new QTreeWidget(frame_2);
        QTreeWidgetItem *__qtreewidgetitem3 = new QTreeWidgetItem();
        __qtreewidgetitem3->setText(1, QString::fromUtf8("2"));
        __qtreewidgetitem3->setText(0, QString::fromUtf8("1"));
        CoreTable->setHeaderItem(__qtreewidgetitem3);
        CoreTable->setObjectName("CoreTable");
        sizePolicy6.setHeightForWidth(CoreTable->sizePolicy().hasHeightForWidth());
        CoreTable->setSizePolicy(sizePolicy6);
        CoreTable->setMinimumSize(QSize(130, 100));
        CoreTable->setFont(font);
        CoreTable->setStyleSheet(QString::fromUtf8("border:none;"));
        CoreTable->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        CoreTable->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        CoreTable->setColumnCount(2);
        CoreTable->header()->setVisible(false);

        horizontalLayout_8->addWidget(CoreTable);


        verticalLayout_2->addLayout(horizontalLayout_8);


        horizontalLayout_5->addLayout(verticalLayout_2);

        horizontalLayout_5->setStretch(0, 4);
        horizontalLayout_5->setStretch(1, 5);
        horizontalLayout_5->setStretch(2, 7);

        verticalLayout_8->addWidget(frame_2);

        verticalLayout_8->setStretch(1, 7);
        verticalLayout_8->setStretch(2, 2);
        tab_0->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        tab_2->setStyleSheet(QString::fromUtf8(""));
        formLayout_4 = new QFormLayout(tab_2);
        formLayout_4->setObjectName("formLayout_4");
        verticalLayout_14 = new QVBoxLayout();
        verticalLayout_14->setObjectName("verticalLayout_14");
        label = new QLabel(tab_2);
        label->setObjectName("label");
        label->setFont(font2);

        verticalLayout_14->addWidget(label);

        RAMplot = new QCustomPlot(tab_2);
        RAMplot->setObjectName("RAMplot");
        sizePolicy2.setHeightForWidth(RAMplot->sizePolicy().hasHeightForWidth());
        RAMplot->setSizePolicy(sizePolicy2);

        verticalLayout_14->addWidget(RAMplot);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        verticalLayout_15 = new QVBoxLayout();
        verticalLayout_15->setObjectName("verticalLayout_15");
        RAM = new QLabel(tab_2);
        RAM->setObjectName("RAM");
        RAM->setFont(font4);

        verticalLayout_15->addWidget(RAM);

        RAMTEXT = new QLabel(tab_2);
        RAMTEXT->setObjectName("RAMTEXT");
        QFont font5;
        font5.setPointSize(23);
        RAMTEXT->setFont(font5);

        verticalLayout_15->addWidget(RAMTEXT);

        ramTotal = new QLabel(tab_2);
        ramTotal->setObjectName("ramTotal");
        ramTotal->setFont(font4);
        ramTotal->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        ramTotal->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout_15->addWidget(ramTotal);

        Avai = new QLabel(tab_2);
        Avai->setObjectName("Avai");
        Avai->setFont(font4);

        verticalLayout_15->addWidget(Avai);

        Used = new QLabel(tab_2);
        Used->setObjectName("Used");
        Used->setFont(font4);

        verticalLayout_15->addWidget(Used);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_15->addItem(verticalSpacer_4);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_15->addItem(verticalSpacer_6);


        horizontalLayout_9->addLayout(verticalLayout_15);


        verticalLayout_14->addLayout(horizontalLayout_9);

        verticalLayout_14->setStretch(1, 7);
        verticalLayout_14->setStretch(2, 2);

        formLayout_4->setLayout(0, QFormLayout::FieldRole, verticalLayout_14);

        tab_0->addTab(tab_2, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName("tab_4");
        tab_4->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_5 = new QVBoxLayout(tab_4);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName("verticalLayout_10");
        label_2 = new QLabel(tab_4);
        label_2->setObjectName("label_2");
        label_2->setFont(font2);

        verticalLayout_10->addWidget(label_2);

        NETPLOT = new QCustomPlot(tab_4);
        NETPLOT->setObjectName("NETPLOT");

        verticalLayout_10->addWidget(NETPLOT);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        verticalLayout_17 = new QVBoxLayout();
        verticalLayout_17->setObjectName("verticalLayout_17");
        netName = new QLabel(tab_4);
        netName->setObjectName("netName");
        netName->setFont(font3);

        verticalLayout_17->addWidget(netName);

        SSID = new QLabel(tab_4);
        SSID->setObjectName("SSID");
        SSID->setFont(font);

        verticalLayout_17->addWidget(SSID);

        CONN_TYPE = new QLabel(tab_4);
        CONN_TYPE->setObjectName("CONN_TYPE");
        CONN_TYPE->setFont(font);

        verticalLayout_17->addWidget(CONN_TYPE);

        IPV4ADDR = new QLabel(tab_4);
        IPV4ADDR->setObjectName("IPV4ADDR");
        IPV4ADDR->setFont(font);

        verticalLayout_17->addWidget(IPV4ADDR);

        IPV6ADDR = new QLabel(tab_4);
        IPV6ADDR->setObjectName("IPV6ADDR");
        IPV6ADDR->setFont(font);

        verticalLayout_17->addWidget(IPV6ADDR);

        SIGSTR = new QLabel(tab_4);
        SIGSTR->setObjectName("SIGSTR");
        SIGSTR->setFont(font);

        verticalLayout_17->addWidget(SIGSTR);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_17->addItem(verticalSpacer_7);


        horizontalLayout_11->addLayout(verticalLayout_17);

        verticalLayout_19 = new QVBoxLayout();
        verticalLayout_19->setObjectName("verticalLayout_19");
        AUTHTYPE = new QLabel(tab_4);
        AUTHTYPE->setObjectName("AUTHTYPE");
        AUTHTYPE->setFont(font);

        verticalLayout_19->addWidget(AUTHTYPE);

        PHYSADDR = new QLabel(tab_4);
        PHYSADDR->setObjectName("PHYSADDR");
        PHYSADDR->setFont(font);

        verticalLayout_19->addWidget(PHYSADDR);

        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_19->addItem(verticalSpacer_9);


        horizontalLayout_11->addLayout(verticalLayout_19);

        verticalLayout_18 = new QVBoxLayout();
        verticalLayout_18->setObjectName("verticalLayout_18");
        label_10 = new QLabel(tab_4);
        label_10->setObjectName("label_10");
        label_10->setFont(font);

        verticalLayout_18->addWidget(label_10);

        UPVAL = new QLabel(tab_4);
        UPVAL->setObjectName("UPVAL");
        QFont font6;
        font6.setPointSize(17);
        UPVAL->setFont(font6);

        verticalLayout_18->addWidget(UPVAL);

        label_12 = new QLabel(tab_4);
        label_12->setObjectName("label_12");
        label_12->setFont(font);

        verticalLayout_18->addWidget(label_12);

        DOWNVAL = new QLabel(tab_4);
        DOWNVAL->setObjectName("DOWNVAL");
        DOWNVAL->setFont(font6);

        verticalLayout_18->addWidget(DOWNVAL);

        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_18->addItem(verticalSpacer_8);


        horizontalLayout_11->addLayout(verticalLayout_18);


        verticalLayout_10->addLayout(horizontalLayout_11);

        verticalLayout_10->setStretch(0, 1);
        verticalLayout_10->setStretch(1, 8);
        verticalLayout_10->setStretch(2, 2);

        verticalLayout_5->addLayout(verticalLayout_10);

        tab_0->addTab(tab_4, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName("tab_6");
        verticalLayout = new QVBoxLayout(tab_6);
        verticalLayout->setObjectName("verticalLayout");
        UserProcesses = new QTreeWidget(tab_6);
        QTreeWidgetItem *__qtreewidgetitem4 = new QTreeWidgetItem();
        __qtreewidgetitem4->setText(0, QString::fromUtf8("1"));
        UserProcesses->setHeaderItem(__qtreewidgetitem4);
        UserProcesses->setObjectName("UserProcesses");
        UserProcesses->setStyleSheet(QString::fromUtf8(""));
        UserProcesses->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        UserProcesses->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);

        verticalLayout->addWidget(UserProcesses);

        SystemProcesses = new QTreeWidget(tab_6);
        QTreeWidgetItem *__qtreewidgetitem5 = new QTreeWidgetItem();
        __qtreewidgetitem5->setText(0, QString::fromUtf8("1"));
        SystemProcesses->setHeaderItem(__qtreewidgetitem5);
        SystemProcesses->setObjectName("SystemProcesses");
        SystemProcesses->setStyleSheet(QString::fromUtf8("border:none; "));
        SystemProcesses->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        SystemProcesses->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);

        verticalLayout->addWidget(SystemProcesses);

        tab_0->addTab(tab_6, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName("tab_7");
        verticalLayout_20 = new QVBoxLayout(tab_7);
        verticalLayout_20->setObjectName("verticalLayout_20");
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName("horizontalLayout_12");
        catagoryTree = new QTreeWidget(tab_7);
        QTreeWidgetItem *__qtreewidgetitem6 = new QTreeWidgetItem();
        __qtreewidgetitem6->setText(0, QString::fromUtf8("1"));
        catagoryTree->setHeaderItem(__qtreewidgetitem6);
        catagoryTree->setObjectName("catagoryTree");
        catagoryTree->setStyleSheet(QString::fromUtf8(""));
        catagoryTree->setColumnCount(1);
        catagoryTree->header()->setVisible(false);
        catagoryTree->header()->setCascadingSectionResizes(true);

        horizontalLayout_12->addWidget(catagoryTree);

        verticalLayout_21 = new QVBoxLayout();
        verticalLayout_21->setObjectName("verticalLayout_21");
        CURRENTSELECTED = new QLabel(tab_7);
        CURRENTSELECTED->setObjectName("CURRENTSELECTED");
        QFont font7;
        font7.setPointSize(15);
        CURRENTSELECTED->setFont(font7);
        CURRENTSELECTED->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_21->addWidget(CURRENTSELECTED);

        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        RED = new QLabel(tab_7);
        RED->setObjectName("RED");
        RED->setStyleSheet(QString::fromUtf8(""));

        formLayout->setWidget(0, QFormLayout::LabelRole, RED);

        REDSLIDER = new QSlider(tab_7);
        REDSLIDER->setObjectName("REDSLIDER");
        REDSLIDER->setMaximum(255);
        REDSLIDER->setOrientation(Qt::Orientation::Horizontal);

        formLayout->setWidget(0, QFormLayout::FieldRole, REDSLIDER);

        GREEN = new QLabel(tab_7);
        GREEN->setObjectName("GREEN");
        GREEN->setStyleSheet(QString::fromUtf8(""));

        formLayout->setWidget(1, QFormLayout::LabelRole, GREEN);

        GREENSLIDER = new QSlider(tab_7);
        GREENSLIDER->setObjectName("GREENSLIDER");
        GREENSLIDER->setMaximum(255);
        GREENSLIDER->setOrientation(Qt::Orientation::Horizontal);

        formLayout->setWidget(1, QFormLayout::FieldRole, GREENSLIDER);

        BLUE = new QLabel(tab_7);
        BLUE->setObjectName("BLUE");
        BLUE->setStyleSheet(QString::fromUtf8(""));

        formLayout->setWidget(2, QFormLayout::LabelRole, BLUE);

        BLUESLIDER = new QSlider(tab_7);
        BLUESLIDER->setObjectName("BLUESLIDER");
        BLUESLIDER->setMaximum(255);
        BLUESLIDER->setOrientation(Qt::Orientation::Horizontal);

        formLayout->setWidget(2, QFormLayout::FieldRole, BLUESLIDER);


        verticalLayout_21->addLayout(formLayout);

        COLOURDISPLAY = new QFrame(tab_7);
        COLOURDISPLAY->setObjectName("COLOURDISPLAY");
        COLOURDISPLAY->setStyleSheet(QString::fromUtf8("background:rgb(130, 130, 130);"));
        COLOURDISPLAY->setFrameShape(QFrame::Shape::StyledPanel);
        COLOURDISPLAY->setFrameShadow(QFrame::Shadow::Raised);

        verticalLayout_21->addWidget(COLOURDISPLAY);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName("horizontalLayout_13");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_2);

        OKBUTTON = new QPushButton(tab_7);
        OKBUTTON->setObjectName("OKBUTTON");
        OKBUTTON->setStyleSheet(QString::fromUtf8("background: white;"));

        horizontalLayout_13->addWidget(OKBUTTON);


        verticalLayout_21->addLayout(horizontalLayout_13);

        line_4 = new QFrame(tab_7);
        line_4->setObjectName("line_4");
        line_4->setStyleSheet(QString::fromUtf8("background: solid white;"));
        line_4->setFrameShape(QFrame::Shape::HLine);
        line_4->setFrameShadow(QFrame::Shadow::Sunken);

        verticalLayout_21->addWidget(line_4);

        verticalSpacer_10 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_21->addItem(verticalSpacer_10);

        verticalLayout_21->setStretch(2, 1);
        verticalLayout_21->setStretch(5, 1);

        horizontalLayout_12->addLayout(verticalLayout_21);


        verticalLayout_20->addLayout(horizontalLayout_12);

        tab_0->addTab(tab_7, QString());

        gridLayout->addWidget(tab_0, 0, 0, 1, 1);

        CuteMon->setCentralWidget(centralwidget);

        retranslateUi(CuteMon);

        tab_0->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(CuteMon);
    } // setupUi

    void retranslateUi(QMainWindow *CuteMon)
    {
        CuteMon->setWindowTitle(QCoreApplication::translate("CuteMon", "CuteMon", nullptr));
        o_cpuName->setText(QCoreApplication::translate("CuteMon", "Ryzen 5 5500", nullptr));
        o_coreCount->setText(QCoreApplication::translate("CuteMon", "12 Cores", nullptr));
        label_3->setText(QCoreApplication::translate("CuteMon", "Usage", nullptr));
        o_cpu_percentage->setText(QCoreApplication::translate("CuteMon", "%", nullptr));
        o_mem_total->setText(QCoreApplication::translate("CuteMon", "Total", nullptr));
        o_mem_used->setText(QCoreApplication::translate("CuteMon", "Used", nullptr));
        o_mem_percentage->setText(QCoreApplication::translate("CuteMon", "%", nullptr));
        o_mem_avai->setText(QCoreApplication::translate("CuteMon", "Avai", nullptr));
        o_avai_percentage->setText(QCoreApplication::translate("CuteMon", "%", nullptr));
        o_download->setText(QCoreApplication::translate("CuteMon", "Download", nullptr));
        o_download_value->setText(QCoreApplication::translate("CuteMon", "50Kbps", nullptr));
        o_peak_download->setText(QCoreApplication::translate("CuteMon", "Peak", nullptr));
        o_peak_down_val->setText(QCoreApplication::translate("CuteMon", "100kbps", nullptr));
        o_upload->setText(QCoreApplication::translate("CuteMon", "Upload", nullptr));
        o_upload_val->setText(QCoreApplication::translate("CuteMon", "10Kpbs", nullptr));
        o_peak_upload->setText(QCoreApplication::translate("CuteMon", "Peak", nullptr));
        o_peak_up_val->setText(QCoreApplication::translate("CuteMon", "20Kpbs", nullptr));
        tab_0->setTabText(tab_0->indexOf(tab_3), QCoreApplication::translate("CuteMon", "Overview", nullptr));
        CPU->setText(QCoreApplication::translate("CuteMon", "CPU", nullptr));
        cpuName->setText(QCoreApplication::translate("CuteMon", "Ryzen 5 5500", nullptr));
        coreCount->setText(QCoreApplication::translate("CuteMon", "12 Cores", nullptr));
        CPUTEXT->setText(QCoreApplication::translate("CuteMon", "%", nullptr));
        label_4->setText(QCoreApplication::translate("CuteMon", "Core usage", nullptr));
        tab_0->setTabText(tab_0->indexOf(tab), QCoreApplication::translate("CuteMon", "CPU", nullptr));
        label->setText(QCoreApplication::translate("CuteMon", "Memory", nullptr));
        RAM->setText(QCoreApplication::translate("CuteMon", "Usage", nullptr));
        RAMTEXT->setText(QCoreApplication::translate("CuteMon", "%", nullptr));
        ramTotal->setText(QCoreApplication::translate("CuteMon", "Total:              32 Gb", nullptr));
        Avai->setText(QCoreApplication::translate("CuteMon", "Available:      12 Gb", nullptr));
        Used->setText(QCoreApplication::translate("CuteMon", "Used:             20Gb", nullptr));
        tab_0->setTabText(tab_0->indexOf(tab_2), QCoreApplication::translate("CuteMon", "Memory", nullptr));
        label_2->setText(QCoreApplication::translate("CuteMon", "Network", nullptr));
        netName->setText(QCoreApplication::translate("CuteMon", "Intel AX 1300 WiFi", nullptr));
        SSID->setText(QCoreApplication::translate("CuteMon", "SSID:                        BT-R7CK87", nullptr));
        CONN_TYPE->setText(QCoreApplication::translate("CuteMon", "Connection type:  903.22bd", nullptr));
        IPV4ADDR->setText(QCoreApplication::translate("CuteMon", "IPv4 Address:         203.179.2.332", nullptr));
        IPV6ADDR->setText(QCoreApplication::translate("CuteMon", "IPv6 Address:         3b11:34d8:f54:9812:058c:9de", nullptr));
        SIGSTR->setText(QCoreApplication::translate("CuteMon", "Signal Strength:    VERYWEAK | WEAK | OK | STRONG | VERYSTRONG", nullptr));
        AUTHTYPE->setText(QCoreApplication::translate("CuteMon", "Authentication:           WPA2-PERSONAL", nullptr));
        PHYSADDR->setText(QCoreApplication::translate("CuteMon", "Physical (MAC) Addr: 12:34:56:78", nullptr));
        label_10->setText(QCoreApplication::translate("CuteMon", "Upload", nullptr));
        UPVAL->setText(QCoreApplication::translate("CuteMon", "12 Kbps", nullptr));
        label_12->setText(QCoreApplication::translate("CuteMon", "Download", nullptr));
        DOWNVAL->setText(QCoreApplication::translate("CuteMon", "30 Mbps", nullptr));
        tab_0->setTabText(tab_0->indexOf(tab_4), QCoreApplication::translate("CuteMon", "Network", nullptr));
        tab_0->setTabText(tab_0->indexOf(tab_6), QCoreApplication::translate("CuteMon", "Processes", nullptr));
        CURRENTSELECTED->setText(QCoreApplication::translate("CuteMon", "Color Edit - None selected", nullptr));
        RED->setText(QCoreApplication::translate("CuteMon", "Red:    130", nullptr));
        GREEN->setText(QCoreApplication::translate("CuteMon", "Green: 130", nullptr));
        BLUE->setText(QCoreApplication::translate("CuteMon", "Blue:   130", nullptr));
        OKBUTTON->setText(QCoreApplication::translate("CuteMon", "Save", nullptr));
        tab_0->setTabText(tab_0->indexOf(tab_7), QCoreApplication::translate("CuteMon", "Options", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CuteMon: public Ui_CuteMon {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUTEMON_H
