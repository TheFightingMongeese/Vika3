/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QTabWidget *Tabs;
    QWidget *TabScientist;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *SearchScientist;
    QFormLayout *formLayout;
    QTableWidget *tableWidgetScientists;
    QWidget *TabComputer;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *SearchComputers;
    QTableWidget *tableWidgetComputers;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        Tabs = new QTabWidget(centralwidget);
        Tabs->setObjectName(QStringLiteral("Tabs"));
        TabScientist = new QWidget();
        TabScientist->setObjectName(QStringLiteral("TabScientist"));
        verticalLayout_2 = new QVBoxLayout(TabScientist);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        SearchScientist = new QLineEdit(TabScientist);
        SearchScientist->setObjectName(QStringLiteral("SearchScientist"));
        SearchScientist->setAutoFillBackground(false);

        verticalLayout_2->addWidget(SearchScientist);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));

        verticalLayout_2->addLayout(formLayout);

        tableWidgetScientists = new QTableWidget(TabScientist);
        tableWidgetScientists->setObjectName(QStringLiteral("tableWidgetScientists"));
        tableWidgetScientists->setSortingEnabled(true);

        verticalLayout_2->addWidget(tableWidgetScientists);

        Tabs->addTab(TabScientist, QString());
        TabComputer = new QWidget();
        TabComputer->setObjectName(QStringLiteral("TabComputer"));
        verticalLayout_3 = new QVBoxLayout(TabComputer);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        SearchComputers = new QLineEdit(TabComputer);
        SearchComputers->setObjectName(QStringLiteral("SearchComputers"));

        verticalLayout_3->addWidget(SearchComputers);

        tableWidgetComputers = new QTableWidget(TabComputer);
        tableWidgetComputers->setObjectName(QStringLiteral("tableWidgetComputers"));
        tableWidgetComputers->setSortingEnabled(true);

        verticalLayout_3->addWidget(tableWidgetComputers);

        Tabs->addTab(TabComputer, QString());

        verticalLayout->addWidget(Tabs);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        Tabs->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        pushButton->setText(QApplication::translate("MainWindow", "PushButton", 0));
        SearchScientist->setInputMask(QString());
        SearchScientist->setText(QString());
        SearchScientist->setPlaceholderText(QApplication::translate("MainWindow", "Search Scientists", 0));
        Tabs->setTabText(Tabs->indexOf(TabScientist), QApplication::translate("MainWindow", "Scientists", 0));
        SearchComputers->setPlaceholderText(QApplication::translate("MainWindow", "Search Computers", 0));
        Tabs->setTabText(Tabs->indexOf(TabComputer), QApplication::translate("MainWindow", "Computers", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
