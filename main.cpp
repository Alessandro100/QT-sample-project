#include "mainwindow.h"
#include "customchart.h"

#include <QApplication>
#include <QPushButton>
#include <QtCharts>

QT_CHARTS_USE_NAMESPACE

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    CustomChart cc = CustomChart();

    QChartView *chartView = cc.getChart();

    QPalette pal = qApp->palette();
    pal.setColor(QPalette::Window, QRgb(0xffffff));
    pal.setColor(QPalette::WindowText, QRgb(0x404040));
    qApp->setPalette(pal);

    w.setCentralWidget(chartView);
    w.resize(420,300);

    w.show();
    return a.exec();
}
