#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>

#include "models/computer.h"
#include "models/scientist.h"
#include "services/computerservice.h"
#include "services/scientistservice.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_Tabs_currentChanged(int index);

private:
    Ui::MainWindow *ui;
    ScientistService _scientistService;
    ComputerService _computerService;

    void displayScientistTable(QString filter = "");
    void displayComputerTable();
};

#endif // MAINWINDOW_H
