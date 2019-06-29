// chart_display.h
// example window to display a chart
#ifndef CHART_DISPLAY_H
#define CHART_DISPLAY_H

#include <QWidget>
// don't add QMainWindow
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>

QT_CHARTS_USE_NAMESPACE

class ChartDisplay : public QWidget
{
    Q_OBJECT

public:
    ChartDisplay(QWidget *parent = nullptr);

private:
    QChartView *chartView;
};


#endif // CHART_DISPLAY_H
