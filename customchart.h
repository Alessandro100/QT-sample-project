#ifndef CUSTOMCHART_H
#define CUSTOMCHART_H
#include <QtCharts>

QT_CHARTS_USE_NAMESPACE

class CustomChart
{
public:
    CustomChart();
    QtCharts::QChartView * getChart();
};

#endif // CUSTOMCHART_H
