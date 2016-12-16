#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include <QTableWidgetItem>

#include "ui/editscientist.h"
#include "ui/editcomputer.h"
#include "models/computer.h"
#include "models/scientist.h"
#include "services/computerservice.h"
#include "services/scientistservice.h"

using namespace std;

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

    void on_btnAddScientist_clicked();

    void on_btnAddComputer_clicked();

    void on_SearchScientist_textEdited(const QString &filter);

    void on_SearchComputers_textEdited(const QString &filter);

    void on_tableWidgetScientists_itemDoubleClicked(QTableWidgetItem *item);

    void on_tableWidgetComputers_itemDoubleClicked(QTableWidgetItem *item);

private:
    Ui::MainWindow *ui;
    ScientistService _scientistService;
    ComputerService _computerService;

    std::vector<Scientist> currentScientist;
    std::vector<Scientist> currentlyDisplayedScientist;

    std::vector<Computer> currentComputer;
    std::vector<Computer> currentlyDisplayedComputer;

    void displayScientistTable(QString filter = "");
    void displayComputerTable(QString filter = "");
};

#endif // MAINWINDOW_H
