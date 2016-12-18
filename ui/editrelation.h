#ifndef EDITRELATION_H
#define EDITRELATION_H

#include "models/relation.h"

#include <QDialog>
#include <QString>
#include <QTableWidget>
#include <QMessageBox>
#include <QDebug>
#include <vector>

using namespace std;

namespace Ui {
class EditRelation;
}

class EditRelation : public QDialog
{
    Q_OBJECT

public:
    explicit EditRelation(QWidget *parent = 0);
    ~EditRelation();

    void setComputerList(vector<Computer> c);
    void setScientistList(vector<Scientist> s);
    int getID(QTableWidget *table);

    Relation getRelation();
private slots:
    void on_buttonBox_accepted();

private:
    Ui::EditRelation *ui;
    Relation relation;

    vector<Computer> computers;
    vector<Scientist> scientists;
};

#endif // EDITRELATION_H
