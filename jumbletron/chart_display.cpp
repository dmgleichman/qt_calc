// chart_display.c
// example displaying a line chart

#include <QtWidgets>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>

QT_CHARTS_USE_NAMESPACE

#include "chart_display.h"



ChartDisplay::ChartDisplay(QWidget *parent)
    : QWidget (parent)
{

    QLineSeries *series = new QLineSeries();
    series->append(0, 6);
    series->append(2, 4);
    series->append(3, 8);
    series->append(7, 4);
    series->append(10, 5);
    *series << QPointF(11, 1) << QPointF(13, 3) << QPointF(17, 6) << QPointF(18, 3) << QPointF(20, 2) << QPointF(22,12);

    QChart *chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(series);
    chart->createDefaultAxes();
    chart->setTitle("Doug's Simple line chart example");

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(chartView, 1, 1, 10, 10);

    setLayout(mainLayout);

    resize(400, 300);

    setWindowTitle("Chart Display");

}
