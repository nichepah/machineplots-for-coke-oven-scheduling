#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qcustomplot.h>
#include <QTimer>
#include <QObject>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setupOvenPlot();
    void corePlot(QCustomPlot *customPlot);
    void getCokingPeriod();
    void getBalancePeriod();
    void getOverRun();
    void getLessThanMinCP();    // get coking period less than min cp; for better plotting


private slots:
  void realtimeDataSlot();

private:
    Ui::MainWindow *ui;
    double minCokingPeriod = 17;    // in hrs
    int count = 70;                 // no. of ovens
    QTimer *dataTimer;                // for repeated calls to replot

    QCPBars *cPeriodBar;
    QCPBars *bPeriodBar;
    QCPBars *oPeriodBar;


    QVector<double> ovens =   { 141, 146, 151, 156, 161, 166, 171, 176, 181, 186,
                                191, 196, 201, 206, 143, 148, 153, 158, 163, 168,
                                173, 178, 183, 188, 193, 198, 203, 208, 145, 150,
                                155, 160, 165, 170, 175, 180, 185, 190, 195, 200,
                                205, 210, 142, 147, 152, 157, 162, 167, 172, 177,
                                182, 187, 192, 197, 202, 207, 144, 149, 154, 159,
                                164, 169, 174, 179, 184, 189, 194, 199, 204, 209
                              };

    // for better plotting; avoid that translation
    QVector<double> xovens =   {   1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
                                   20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39,
                                   40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59,
                                   60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70
                               };


    // Vector: actual coking period so far in hrs, including overruns;
    QVector<double> cokingPeriod =  {
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0
                                   };

    // Vector: minCokingPeriod-cokingPeriod in hrs for those less than minCokingPeriod
    QVector<double> balancePeriod =  {
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0
                                   };

    // Vector: period over cooked in hrs
    QVector<double> overRun =       {
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0
                                   };

    // Vector: period less than minCokingPeriod; for better plotting
    QVector<double> lessThanMinCP = {
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0
                                   };

};

#endif // MAINWINDOW_H
