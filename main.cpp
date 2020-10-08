#include "mainwindow.h"
#include "customchart.h"
#include "customlinebarchart.h"

#include <QApplication>
#include <QPushButton>
#include <QtCharts>

QT_CHARTS_USE_NAMESPACE

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget *window = new QWidget;
    QHBoxLayout *layout = new QHBoxLayout;

    CustomChart cc = CustomChart();
    CustomLineBarChart customBarChart = CustomLineBarChart();

    QChartView *chartView1 = customBarChart.getChart();
    QChartView *chartView2 = cc.getChart();

    QPalette pal = qApp->palette();
    pal.setColor(QPalette::Window, QRgb(0xffffff));
    pal.setColor(QPalette::WindowText, QRgb(0x404040));
    qApp->setPalette(pal);

    layout->addWidget(chartView1);
    layout->addWidget(chartView2);

    window->setLayout(layout);
    window->resize(1000,500);
    window->show();

    return a.exec();
}
