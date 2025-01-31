#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QAbstractButton>
#include <QString>
#include "CalculatorModel.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    CalculatorModel model;

signals:
    void write(QString text);

public slots:
    void onExit(bool checked);
    void onAbout(bool checked);
    void onButtonClickedId(int id);
};
#endif // MAINWINDOW_H
