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
