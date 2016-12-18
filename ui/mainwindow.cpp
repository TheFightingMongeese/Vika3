#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "numberwidgetitem.h"
#include "utilities/utils.h"
#include <iostream>
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
        scientists = _scientistService.searchForScientists(filter);
    }

    QTableWidget *table = ui->tableWidgetScientists;
    table->clear();

    QStringList tableHeader;
    tableHeader << "ID" << "Name" << "Gender" << "Year born" << "Year of death";
    table->setColumnCount(tableHeader.size());
    table->setRowCount(scientists.size());
    table->setHorizontalHeaderLabels(tableHeader);

    if(scientists.size() > 0)
    {
        for(unsigned int i = 0; i < scientists.size(); i++)
        {
            Scientist s = scientists.at(i);
            QString scientistID = QString::number(s.getId());
            QString name = s.getName();
            QString sexType = utils::sexToString(s.getSex());
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
}
void MainWindow::displayComputerTable(QString filter)
{
    std::vector<Computer> computers;

    if(filter.isEmpty())
    {
        computers = _computerService.getAllComputers("name", true);
    }
    else
    {
        computers = _computerService.searchForComputers(filter);
    }

    QTableWidget *table = ui->tableWidgetComputers;
    table->clear();

    QStringList tableHeader;
    tableHeader << "ID" << "Name" << "Type" << "Year of build";
    table->setColumnCount(tableHeader.size());
    table->setRowCount(computers.size());
    table->setHorizontalHeaderLabels(tableHeader);

    if(computers.size() > 0)
    {
        for(unsigned int i = 0; i < computers.size(); i++)
        {
            Computer c = computers.at(i);
            QString computerID = QString::number(c.getId());
            QString name = c.getName();
            QString type = c.getTypeAsString();
            QString yearBuilt = QString::number(c.getYearBuilt());

            qDebug() << computerID << name;

            table->setItem(i, 0, new NumberWidgetItem(computerID));
            table->setItem(i, 1, new QTableWidgetItem(name));
            table->setItem(i, 2, new QTableWidgetItem(type));
            table->setItem(i, 3, new QTableWidgetItem(yearBuilt));

        }
     }
}

void MainWindow::displayRelationsTable(QString filter)
{

    std::vector<Relation> relations;

    if(filter.isEmpty())
    {

        relations = _linkService.GetAllLinks();
    }
    else
    {

    }

    QTableWidget *table = ui->tableWidgetRelations;
    table->clear();

    QStringList tableHeader;
    tableHeader << "ID" << "Scientist" << "ID" << "Computer";
    table->setColumnCount(tableHeader.size());
    table->setRowCount(relations.size());
    table->setHorizontalHeaderLabels(tableHeader);

    if(relations.size() > 0)
    {
        for(unsigned int i = 0; i < relations.size(); i++)
        {
            Relation r = relations.at(i);

            QString scientistID = QString::number(r.getScientist().getId());
            QString scientistName = r.getScientist().getName();
            QString computerID = QString::number(r.getComputer().getId());
            QString computerName = r.getComputer().getName();


            table->setItem(i, 0, new QTableWidgetItem(scientistID));
            table->setItem(i, 1, new QTableWidgetItem(scientistName));
            table->setItem(i, 2, new QTableWidgetItem(computerID));
            table->setItem(i, 3, new QTableWidgetItem(computerName));
        }
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
    case 2:
        displayRelationsTable();
        break;
    }

}

void MainWindow::on_btnAddScientist_clicked()
{
    EditScientist *addScientist = new EditScientist();
    addScientist->setScientist();

    if(addScientist->exec())
    {
        qDebug() << addScientist->getScientist().getName();
        _scientistService.addScientist(addScientist->getScientist());
        displayScientistTable();
    }
    delete addScientist;
}

void MainWindow::on_SearchScientist_textEdited(const QString &filter)
{
    displayScientistTable(filter);
}

void MainWindow::on_SearchComputers_textEdited(const QString &filter)
{
    displayComputerTable(filter);
}

void MainWindow::on_tableWidgetScientists_itemDoubleClicked(QTableWidgetItem *item)
{
    QTableWidget *table = ui->tableWidgetScientists;
    int rowID = item->row();

    int id = table->item(rowID, 0)->text().toInt();
    QString name = table->item(rowID, 1)->text();
    sexType gender = sexType(table->item(rowID, 2)->text().toInt());
    int birth = table->item(rowID, 3)->text().toInt();
    int death = table->item(rowID, 4)->text().toInt();

    Scientist s(id, name, gender, birth, death);
    EditScientist *editScientist = new EditScientist();
    editScientist->setScientist(s);

    if(editScientist->exec())
    {
        Scientist sci = editScientist->getScientist();

        _scientistService.updateScientist(sci);
        displayScientistTable();
    }
    delete editScientist;
}

void MainWindow::on_tableWidgetComputers_itemDoubleClicked(QTableWidgetItem *item)
{
    QTableWidget *table = ui->tableWidgetComputers;
    int rowID = item->row();

    int id = table->item(rowID, 0)->text().toInt();
    QString name = table->item(rowID, 1)->text();
    computerType type = computerType(table->item(rowID, 2)->text().toInt());
    int built = table->item(rowID, 3)->text().toInt();

    Computer c(id, name, type, built);
    EditComputer *editComputer = new EditComputer();
    editComputer->setComputer(c);

    if(editComputer->exec())
    {
        Computer comp = editComputer->getComputer();

        _computerService.updateComputer(comp);
        displayComputerTable();
    }
    delete editComputer;
}



void MainWindow::on_btnAddComputer_clicked()
{
    EditComputer *addComputer = new EditComputer();
    addComputer->setComputer();

    if(addComputer->exec())
    {
        qDebug() << addComputer->getComputer().getName();
        _computerService.addComputer(addComputer->getComputer());
        displayComputerTable();
    }
}

void MainWindow::on_tableWidgetRelations_activated()
{
    displayRelationsTable();
}


void MainWindow::on_BtnAddRelation_clicked()
{
    EditRelation *addRelation = new EditRelation();
    vector<Computer> computers = _computerService.getAllComputers("name", true);
    addRelation->setComputerList(computers);
    vector<Scientist> scientists = _scientistService.getAllScientists("name", true);
    addRelation->setScientistList(scientists);

    if(addRelation->exec())
    {
        Relation r = addRelation->getRelation();

        QString scientistID = QString::number(r.getScientist().getId());
        QString computerID = QString::number(r.getComputer().getId());

        _linkService.addLink(scientistID, computerID);
        displayRelationsTable();
    }
    else
    {
        qDebug() << "SOBS!";
    }

    delete addRelation;
}

void MainWindow::on_pushButton_clicked()
{
    QTableWidget *table = ui->tableWidgetRelations;
    int rowCount = table->rowCount();
    QString scientistID = 0;
    QString computerID = 0;

    for(int i = 0; i < rowCount; i++)
    {
        QTableWidgetItem *scientist = table->item(i, 0);
        QTableWidgetItem *computer = table->item(i, 2);

        if(scientist->isSelected())
        {
            scientistID = scientist->text();
            computerID = computer->text();
        }
    }

    if(scientistID.toInt() == 0 || computerID.toInt() == 0)
    {
        QMessageBox::warning(
                    this,
                    tr("Error:"),
                    tr("You must select relation to delete!"));

    }
    else
    {
        _linkService.removeLink(scientistID, computerID);
        displayRelationsTable();
    }
}
