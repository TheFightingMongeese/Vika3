#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "numberwidgetitem.h"
#include "utilities/utils.h"

#include <string>

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
        QString type = QString::fromStdString(c.getTypeAsString());
        QString yearBuilt = QString::number(c.getYearBuilt());

        qDebug() << computerID << name;

        table->setItem(i, 0, new NumberWidgetItem(computerID));
        table->setItem(i, 1, new QTableWidgetItem(name));
        table->setItem(i, 2, new QTableWidgetItem(type));
        table->setItem(i, 3, new QTableWidgetItem(yearBuilt));

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



void MainWindow::on_SearchScientist_textEdited(const QString &arg1)
{
    //QLineEdit::text();

    //ui->QLineEdit::text();

 // ui->SearchScientist->clear();

   /* for(unsigned int i = 0; i < Scientist.size();i++)
    {
        Scientist currentScientists = scientists.at(i);
        ui->displayScientistTable->addItem(QString::fromStdString(currentScientists.getName()));
    }*/
  //  QString input = ui->SearchScientist->text();
   // vector<Scientist> scientistVector;                                       byrjun sem semi virkar
    //scientistVector = _scientistService.searchForScientists("Dennis");
    //ui->tableWidgetScientists->setItem(0,1,new QTableWidgetItem(QString::fromStdString(scientistVector[0].getName())));
    // endir sem semi virkar
   // query.exec("SELECT FROM scientists WHERE name LIKE %input%");     // SQL Search skipunin

    ui->tableWidgetScientists->clearContents();

    ui->tableWidgetScientists->setRowCount(currentScientist.size());

    currentlyDisplayedScientist.clear();

    for(unsigned int i = 0; i < currentScientist.size(); ++i)
    {
        Scientist currentScience = currentScientist[i];

        std::string searchString = ui->SearchScientist->text().toStdString();

        if(currentScience.contains(searchString))
        {
            QString scientistname = QString::fromStdString(currentScience.getName());
            QString scientistsex = QString::fromStdString(currentScience.getSex());
            QString scientistborn = QString::fromStdString(std::to_string(currentScience.getYearBorn()));
            QString scientistdied = QString::fromStdString(std::to_string(currentScience.getYearDied()));


            int currentRow = currentlyDisplayedScientist.size();

            ui->tableWidgetScientists->setItem(currentRow, 0, new QTableWidgetItem(scientistname));
            ui->tableWidgetScientists->setItem(currentRow, 1, new QTableWidgetItem(scientistsex));
            ui->tableWidgetScientists->setItem(currentRow, 2, new QTableWidgetItem(scientistborn));
            ui->tableWidgetScientists->setItem(currentRow, 3, new QTableWidgetItem(scientistdied));

            currentlyDisplayedScientist.push_back(currentScience);
        }



}

/*void MainWindow::on_pushButton_clicked()
{
    /*string userinput = ui->SearchScientist->text().toStdString();

    vector<Scientist> scifie =  ScientistService.searchForScientists(userinput,"name",true);

    displayScientistTable(scifie);
}*/
}
