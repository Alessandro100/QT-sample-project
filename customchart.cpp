#include "customchart.h"
#include <QtCharts>
#include <string>
#include <iostream>


QT_CHARTS_USE_NAMESPACE
using namespace std;

CustomChart::CustomChart()
{

}

 QtCharts::QChartView * CustomChart::getChart() {
    cout << "hi";
    QBarSet *set0 = new QBarSet("Honda");
    QBarSet *set1 = new QBarSet("Ford");
    QBarSet *set2 = new QBarSet("Subaru");
    QBarSet *set3 = new QBarSet("Suzuki");
    QBarSet *set4 = new QBarSet("Audi");

    *set0 << 2 << 3 << 5 << 1 << 5;
    *set1 << 1 << 3 << 4 << 7 << 9;
    *set2 << 3 << 5 << 6 << 9 << 5;
    *set3 << 5 << 3 << 3 << 6 << 5;
    *set4 << 4 << 2 << 6 << 1 << 3;

    QBarSeries *series = new QBarSeries();
    series->append(set0);
    series->append(set1);
    series->append(set2);
    series->append(set3);
    series->append(set4);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Cars!");
    chart->setAnimationOptions(QChart::AllAnimations);

    QStringList catergories;
    catergories << "2013" << "2014" << "2015" << "2016" << "2017";
    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis->append(catergories);
    chart->createDefaultAxes();
    chart->setAxisX(axis, series);
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    return chartView;
}
