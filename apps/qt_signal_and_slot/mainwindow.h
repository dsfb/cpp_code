#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPointer>
#include "formone.h"
#include "formtwo.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void showWindows();

private:
    Ui::MainWindow *ui;
    QPointer<FormOne> one;
    QPointer<FormTwo> two;
};

#endif // MAINWINDOW_H
