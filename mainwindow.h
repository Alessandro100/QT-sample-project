#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void addPoint(double x, double y);
    void clearData();
    void plot();

private slots:
    void on_MainWindow_customContextMenuRequested(const QPoint &pos);

    void on_btn_add_clicked();

    void on_btn_clear_clicked();

    void on_btn_read_clicked();

private:
    Ui::MainWindow *ui;
    QVector<double> qv_x, qv_y;
    QVector<double> qv_x_file, qv_y_file;
};
#endif // MAINWINDOW_H
