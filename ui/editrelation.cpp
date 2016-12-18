#include "editrelation.h"
#include "ui_editrelation.h"


EditRelation::EditRelation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditRelation)
{
    ui->setupUi(this);
}

EditRelation::~EditRelation()
{
    delete ui;
}

void EditRelation::setComputerList(vector<Computer> c)
{
    computers = c;

    int rowCount = computers.size();
    QTableWidget *table = ui->tableWidgetComputersLink;
    table->clear();
    QStringList tableHeader;
    tableHeader << "ID" << "Name";
    table->setColumnCount(2);
    table->setRowCount(rowCount);
    table->setHorizontalHeaderLabels(tableHeader);

    for(int i = 0; i < rowCount; i++)
    {
        Computer comp = computers[i];
        QString id = QString::number(comp.getId());
        QString name = comp.getName();

        table->setItem(i, 0, new QTableWidgetItem(id));
        table->setItem(i, 1, new QTableWidgetItem(name));
    }
}

void EditRelation::setScientistList(vector<Scientist> s)
{
    scientists = s;

    int rowCount = scientists.size();
    QTableWidget *table = ui->tableWidgetScientistsLink;
    table->clear();
    QStringList tableHeader;
    tableHeader << "ID" << "Name";
    table->setColumnCount(2);
    table->setRowCount(rowCount);
    table->setHorizontalHeaderLabels(tableHeader);

    for(int i = 0; i < rowCount; i++)
    {
        Scientist sci = scientists[i];
        QString id = QString::number(sci.getId());
        QString name = sci.getName();

        table->setItem(i, 0, new QTableWidgetItem(id));
        table->setItem(i, 1, new QTableWidgetItem(name));
    }
}

int EditRelation::getID(QTableWidget *table)
{
    int rowCount = table->rowCount();
    int returnID = 0;

    for(int i = 0; i < rowCount; i++)
    {
        QTableWidgetItem *item = table->item(i, 0);

        if(item->isSelected())
        {
            returnID = item->text().toInt();
        }
    }

    return returnID;
}

Relation EditRelation::getRelation()
{
    return relation;
}

void EditRelation::on_buttonBox_accepted()
{
    QTableWidget *tableSci = ui->tableWidgetScientistsLink;
    QTableWidget *tableComp = ui->tableWidgetComputersLink;

    int scientistID = getID(tableSci);
    int computerID = getID(tableComp);

    if(scientistID == 0 || computerID == 0)
    {
        QMessageBox::warning(
                    this,
                    tr("Error:"),
                    tr("You must select computer and scientist!"));

        this->reject();
    }
    else
    {
        relation.setComputerID(computerID);
        relation.setScientistID(scientistID);

        this->accept();
    }
}
