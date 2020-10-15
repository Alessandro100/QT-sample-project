#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "customchart.h"
#include "customlinebarchart.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QFileDialog>
#include <QDir>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->plot->addGraph();
    ui->excel_plot->addGraph();
    ui->plot->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle);
    ui->excel_plot->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle);
    ui->excel_plot->graph(0)->rescaleAxes();
    ui->excel_plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addPoint(double x, double y)
{
    qv_x.append(x);
    qv_y.append(y);

}

void MainWindow::clearData()
{
    qv_x.clear();
    qv_y.clear();
}

void MainWindow::plot()
{
    ui->plot->graph(0)->setData(qv_x, qv_y);
    ui->plot->replot();
    ui->plot->update();
}


void MainWindow::on_btn_add_clicked()
{
    addPoint(ui->bx_x->value(), ui->bx_y->value());
    plot();
}

void MainWindow::on_btn_clear_clicked()
{
    clearData();
    plot();
}

void MainWindow::on_MainWindow_customContextMenuRequested(const QPoint &pos)
{

}


void MainWindow::on_btn_read_clicked()
{
    QString file_name = QFileDialog::getOpenFileName(this, "Open file", QDir::homePath());

    QFile file(file_name);
    if(!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "title", "file not open");
    }

    QTextStream in(&file);
    int count = 0;
    while(!in.atEnd()) {
        QString mText = in.readLine();
        QStringList splitString = mText.split(",");
        if(count != 0) {
            qv_x_file.append(splitString.first().toDouble());
            qv_y_file.append(splitString.last().toDouble());
        }
        count ++;
    }
    ui->excel_plot->graph(0)->setData(qv_x_file, qv_y_file);
    ui->excel_plot->replot();
    ui->excel_plot->update();
}
