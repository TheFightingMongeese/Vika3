#ifndef EDITCOMPUTER_H
#define EDITCOMPUTER_H

#include <QDialog>
#include <QDebug>
#include <string>
#include "models/computer.h"

namespace Ui {
class EditComputer;
}

class EditComputer : public QDialog
{
    Q_OBJECT

public:
    explicit EditComputer(QWidget *parent = 0);
    ~EditComputer();

    Computer getComputer();
    void setComputer();
    void setComputer(Computer c);

private slots:
    void on_buttonBoxComputer_accepted();

    void on_buttonBoxComputer_rejected();

private:
    Ui::EditComputer *ui;
    Computer computer;
};

#endif // EDITCOMPUTER_H
