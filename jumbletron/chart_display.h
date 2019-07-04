// chart_display.h
// example window to display a chart
#ifndef CHART_DISPLAY_H
#define CHART_DISPLAY_H

#include <QWidget>
// don't add QMainWindow
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>

QT_CHARTS_USE_NAMESPACE

QT_BEGIN_NAMESPACE
class QPushButton;
class QLabel;
QT_END_NAMESPACE


class ChartDisplay : public QWidget
{
    Q_OBJECT

public:
    ChartDisplay(QWidget *parent = nullptr);

private slots:
    void makeNewPlot();

private:
    void displayPlot();
    void createPlot();

    QChartView *chartView;

    QChart *chart;

    QLineSeries *series;

    QLabel *panelNameLabel;

    QPushButton *makeNewPlotButton;

};


#endif // CHART_DISPLAY_H
