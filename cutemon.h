#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>
#include "qcustomplot.h"
#include <QTimer>
#include <map>

QT_BEGIN_NAMESPACE
namespace Ui {
class CuteMon;
}
QT_END_NAMESPACE

class CuteMon : public QMainWindow
{
    Q_OBJECT


    void AddProcess(unsigned int PID, QString PName, bool isUser);
    void AddSubProcess(QTreeWidgetItem *parent ,unsigned int PID, QString PName, bool isUser);
    void RemoveProcess(QTreeWidgetItem *process, bool isUser);

public:
    CuteMon(QWidget *parent = nullptr);
    ~CuteMon();

    void setupCpuPlot(QCustomPlot *customPlot);
    void setupRamPlot(QCustomPlot *customPlot);
public slots:
    void updateWindow();
    void getProcessInfo();

private slots:

    void on_REDSLIDER_valueChanged(int value);

    void on_GREENSLIDER_valueChanged(int value);

    void on_BLUESLIDER_valueChanged(int value);

    void on_OKBUTTON_pressed();

    void on_catagoryTree_itemClicked(QTreeWidgetItem *item, int column);

private:
    Ui::CuteMon *ui;
    QTimer *timer;
};
#endif // MAINWINDOW_H
