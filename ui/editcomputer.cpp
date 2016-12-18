#include "editcomputer.h"
#include "ui_editcomputer.h"

EditComputer::EditComputer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditComputer)
{
    ui->setupUi(this);
}

EditComputer::~EditComputer()
{
    delete ui;
}

Computer EditComputer::getComputer()
{
    return computer;
}

void EditComputer::setComputer()
{
    this->setWindowTitle("Add");
}

void EditComputer::setComputer(Computer c)
{
    computer = c;
    this->setWindowTitle("Edit");
    ui->lineEditName->setText(c.getName());
    ui->comboBoxType->setCurrentIndex(c.getType());
    ui->lineEditBuilt->setText(QString::number(c.getYearBuilt()));
}

void EditComputer::on_buttonBoxComputer_accepted()
{
    int typeID = ui->comboBoxType->currentIndex();
    int id = computer.getId();
    QString name = ui->lineEditName->text();

    computerType type = computerType(typeID);
    int built = ui->lineEditBuilt->text().toInt();

    Computer computer2(id, name, type, built);
    computer = computer2;

    this->accept();
}

void EditComputer::on_buttonBoxComputer_rejected()
{
    this->reject();
}
