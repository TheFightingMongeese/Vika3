/********************************************************************************
** Form generated from reading UI file 'editscientist.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITSCIENTIST_H
#define UI_EDITSCIENTIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_EditScientist
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *EditScientist)
    {
        if (EditScientist->objectName().isEmpty())
            EditScientist->setObjectName(QStringLiteral("EditScientist"));
        EditScientist->resize(400, 300);
        buttonBox = new QDialogButtonBox(EditScientist);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(290, 20, 81, 241));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(EditScientist);
        QObject::connect(buttonBox, SIGNAL(accepted()), EditScientist, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), EditScientist, SLOT(reject()));

        QMetaObject::connectSlotsByName(EditScientist);
    } // setupUi

    void retranslateUi(QDialog *EditScientist)
    {
        EditScientist->setWindowTitle(QApplication::translate("EditScientist", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class EditScientist: public Ui_EditScientist {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITSCIENTIST_H
