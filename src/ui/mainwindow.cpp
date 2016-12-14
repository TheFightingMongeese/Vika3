#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "numberwidgetitem.h"
#include "utilities/utils.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    displayScientistTable();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayScientistTable(QString filter)
{
    std::vector<Scientist> scientists;

    if(filter.isEmpty())
    {
        scientists = _scientistService.getAllScientists("name", true);
    }
    else
    {
        scientists = _scientistService.searchForScientists(filter.toStdString());
    }

    QTableWidget *table = ui->tableWidgetScientists;
    table->clear();

    QStringList tableHeader;
    tableHeader << "ID" << "Name" << "Gender" << "Year born" << "Year of death";
    table->setColumnCount(tableHeader.size());
    table->setRowCount(scientists.size());
    table->setHorizontalHeaderLabels(tableHeader);

    for(unsigned int i = 0; i < scientists.size(); i++)
    {
        Scientist s = scientists.at(i);
        QString scientistID = QString::number(s.getId());
        QString name = QString::fromStdString(s.getName());
        QString sexType = QString::fromStdString(utils::sexToString(s.getSex()));
        QString yearBorn = QString::number(s.getYearBorn());
        QString yearDied = QString::number(s.getYearDied());


        qDebug() << scientistID << name;

        table->setItem(i, 0, new NumberWidgetItem(scientistID));
        table->setItem(i, 1, new QTableWidgetItem(name));
        table->setItem(i, 2, new QTableWidgetItem(sexType));
        table->setItem(i, 3, new QTableWidgetItem(yearBorn));
        table->setItem(i, 4, new QTableWidgetItem(yearDied));
    }
}
void MainWindow::displayComputerTable()
{
    std::vector<Computer> computers = _computerService.getAllComputers("name", true);

    QTableWidget *table = ui->tableWidgetComputers;
    table->clear();

    QStringList tableHeader;
    tableHeader << "ID" << "Name" << "Type" << "Year of build";
    table->setColumnCount(tableHeader.size());
    table->setRowCount(computers.size());
    table->setHorizontalHeaderLabels(tableHeader);

    for(unsigned int i = 0; i < computers.size(); i++)
    {
        Computer c = computers.at(i);
        QString computerID = QString::number(c.getId());
        QString name = QString::fromStdString(c.getName());

        qDebug() << computerID << name;

        table->setItem(i, 0, new NumberWidgetItem(computerID));
        table->setItem(i, 1, new QTableWidgetItem(name));
    }
}

void MainWindow::on_Tabs_currentChanged(int index)
{
    switch(index)
    {
    case 0:
        displayScientistTable();
        break;
    case 1:
        displayComputerTable();
        break;
    }

}


