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

void EditScientist::setScientist()
{
    this->setWindowTitle("Add");
}

void EditScientist::setScientist(Scientist s)
{
    scientist = s;
    this->setWindowTitle("Edit");
    ui->lineEditName->setText(s.getName());
    ui->comboBoxGender->setCurrentIndex(s.getSex());
    ui->lineEditBirth->setText(QString::number(s.getYearBorn()));
    ui->lineEditDeath->setText(QString::number(s.getYearDied()));
}

void EditScientist::on_buttonBox_accepted()
{
    int genderID = ui->comboBoxGender->currentIndex();
    QString name = ui->lineEditName->text();

    sexType gender = sexType(genderID);
    int birth = ui->lineEditBirth->text().toInt();
    int death = ui->lineEditDeath->text().toInt();

    Scientist scientist2(name, gender, birth, death);
    scientist = scientist2;

    this->accept();
}

void EditScientist::on_buttonBox_rejected()
{
    this->reject();
}
