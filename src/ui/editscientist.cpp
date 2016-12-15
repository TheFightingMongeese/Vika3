#include "editscientist.h"
#include "ui_editscientist.h"

EditScientist::EditScientist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditScientist)
{
    ui->setupUi(this);
}

EditScientist::~EditScientist()
{
    delete ui;
}

Scientist EditScientist::getScientist()
{
    return scientist;
}

void EditScientist::setScientist(Scientist s)
{
    scientist = s;

    ui->lineEditName->setText(QString::fromStdString(s.getName()));
}

void EditScientist::on_buttonBox_accepted()
{
    std::string name = ui->lineEditName->text().toStdString();
    sexType gender = sexType(0);
    //QLineEdit birth = ui->lineEditBirth->int().toStdString();
    //death = ui->lineEditDeath->int();
    int birth = 1000 ;
    int death = 2000;

    Scientist scientist2(name, gender, birth, death);
    scientist = scientist2;

    this->accept();
}

void EditScientist::on_buttonBox_rejected()
{
    this->reject();
}
