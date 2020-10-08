#ifndef CUSTOMLINEBARCHART_H
#define CUSTOMLINEBARCHART_H
#include <QtCharts>

QT_CHARTS_USE_NAMESPACE

class CustomLineBarChart
{
public:
    CustomLineBarChart();
    QtCharts::QChartView * getChart();
};

#endif // CUSTOMLINEBARCHART_H
