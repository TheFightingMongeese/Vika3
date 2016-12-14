#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    displayTable();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayTable()
{
    std::vector<Scientist> scientists = _scientistService.getAllScientists("name", true);

    QTableWidget *table = ui->tableWidgetScientists;
    table->clear();


    QStringList tableHeader;
    tableHeader << "ID" << "Name" << "Born" << "Died" ; // << Sex
    table->setColumnCount(tableHeader.size());
    table->setRowCount(scientists.size());
    table->setHorizontalHeaderLabels(tableHeader);

    for(unsigned int i = 0; i < scientists.size(); i++)
    {
        Scientist s = scientists.at(i);
        QString scientistID = QString::number(s.getID());
        QString name = QString::fromStdString(s.getName());
        //QString sex = QString::convertEnumToQString(s.getGender());
        QString born = QString::number(s.getYearBorn());
        QString died = QString::number(s.getYearDied());
        qDebug() << scientistID << name;

        table->setItem(i, 0, new QTableWidgetItem(scientistID));
        table->setItem(i, 1, new QTableWidgetItem(name));
    }
}

