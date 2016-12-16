#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidgetItem>
#include <vector>

#include "ui/editscientist.h"
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

    void on_SearchScientist_textEdited(const QString &arg1);



    void on_tableWidgetScientists_itemClicked(QTableWidgetItem *item);

private:
    Ui::MainWindow *ui;
    ScientistService _scientistService;
    ComputerService _computerService;

    std::vector<Scientist> currentScientist;
    std::vector<Scientist> currentlyDisplayedScientist;

    void displayScientistTable(QString filter = "");
    void displayComputerTable();
};

#endif // MAINWINDOW_H
