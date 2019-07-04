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

    series = new QLineSeries();
    series->append(0, 6);
    series->append(2, 4);
    series->append(3, 8);
    series->append(7, 4);
    series->append(10, 5);
    *series << QPointF(11, 1) << QPointF(13, 3) << QPointF(17, 6) << QPointF(18, 3) << QPointF(20, 2) << QPointF(22,12);

    chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(series);
    chart->createDefaultAxes();
    chart->setTitle("Doug's Simple line chart example");

    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    panelNameLabel = new QLabel("A Chart Example");

    makeNewPlotButton = new QPushButton("Make New Plot");

    connect(makeNewPlotButton, SIGNAL(clicked()), this, SLOT(makeNewPlot()));


    QVBoxLayout *mainLayout = new QVBoxLayout;

    mainLayout->addWidget(panelNameLabel);

    mainLayout->addWidget(makeNewPlotButton);

    mainLayout->addWidget(chartView);

    setLayout(mainLayout);

    resize(400, 300);

    setWindowTitle("Chart Display");

}

void ChartDisplay::displayPlot()
{

}

void ChartDisplay::createPlot()
{

    series->clear();
    series->append(0, 2);
    series->append(2, 1);
    series->append(3, 0);
    series->append(7, 10);
    series->append(10, 7);
    *series << QPointF(11, 3) << QPointF(13, 9) << QPointF(17, 1) << QPointF(18, 8) << QPointF(20, 6) << QPointF(22,4);

    chart->setTitle("Doug's New Chart");

}

void ChartDisplay::makeNewPlot()
{
    // make plot

    // display it
    createPlot();
}
