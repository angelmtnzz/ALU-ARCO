#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    //Botones de las operaciones matematicas
    void on_sumButton_released();

    void on_prodButton_released();

    void on_divButton_released();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
