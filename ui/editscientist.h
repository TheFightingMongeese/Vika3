#ifndef EDITSCIENTIST_H
#define EDITSCIENTIST_H

#include <QDialog>
#include <QDebug>
#include <string>
#include "models/scientist.h"

namespace Ui {
class EditScientist;
}

class EditScientist : public QDialog
{
    Q_OBJECT

public:
    explicit EditScientist(QWidget *parent = 0);
    ~EditScientist();

    Scientist getScientist();
    void setScientist();
    void setScientist(Scientist s);

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::EditScientist *ui;
    Scientist scientist;
};

#endif // EDITSCIENTIST_H
