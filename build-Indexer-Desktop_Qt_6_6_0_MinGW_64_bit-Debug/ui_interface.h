/********************************************************************************
** Form generated from reading UI file 'interface.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTERFACE_H
#define UI_INTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Interface
{
public:
    QWidget *centralwidget;
    QRadioButton *ByNameRadio;
    QRadioButton *ByExtensionRadio;
    QRadioButton *ByDateRadio;
    QRadioButton *BySizeRadio;
    QPushButton *StartIndexingButton;
    QPushButton *PauseIndexingButton;
    QPushButton *StopIndexingButton;
    QPushButton *SearchButton;
    QLineEdit *SearchRequestLine;
    QListWidget *SearchResultList;
    QLabel *print;
    QPushButton *ClearResult;
    QPushButton *ExitButton;
    QPushButton *ResumeIndexingButton;
    QLabel *indexlabel;
    QLabel *searchlabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Interface)
    {
        if (Interface->objectName().isEmpty())
            Interface->setObjectName("Interface");
        Interface->resize(544, 415);
        centralwidget = new QWidget(Interface);
        centralwidget->setObjectName("centralwidget");
        ByNameRadio = new QRadioButton(centralwidget);
        ByNameRadio->setObjectName("ByNameRadio");
        ByNameRadio->setEnabled(true);
        ByNameRadio->setGeometry(QRect(0, 130, 89, 20));
        ByExtensionRadio = new QRadioButton(centralwidget);
        ByExtensionRadio->setObjectName("ByExtensionRadio");
        ByExtensionRadio->setGeometry(QRect(0, 150, 89, 20));
        ByDateRadio = new QRadioButton(centralwidget);
        ByDateRadio->setObjectName("ByDateRadio");
        ByDateRadio->setGeometry(QRect(0, 170, 89, 20));
        BySizeRadio = new QRadioButton(centralwidget);
        BySizeRadio->setObjectName("BySizeRadio");
        BySizeRadio->setGeometry(QRect(0, 190, 89, 20));
        StartIndexingButton = new QPushButton(centralwidget);
        StartIndexingButton->setObjectName("StartIndexingButton");
        StartIndexingButton->setGeometry(QRect(0, 0, 91, 24));
        PauseIndexingButton = new QPushButton(centralwidget);
        PauseIndexingButton->setObjectName("PauseIndexingButton");
        PauseIndexingButton->setGeometry(QRect(0, 20, 91, 24));
        StopIndexingButton = new QPushButton(centralwidget);
        StopIndexingButton->setObjectName("StopIndexingButton");
        StopIndexingButton->setGeometry(QRect(0, 40, 91, 24));
        SearchButton = new QPushButton(centralwidget);
        SearchButton->setObjectName("SearchButton");
        SearchButton->setGeometry(QRect(0, 90, 91, 24));
        SearchRequestLine = new QLineEdit(centralwidget);
        SearchRequestLine->setObjectName("SearchRequestLine");
        SearchRequestLine->setGeometry(QRect(0, 110, 91, 22));
        SearchResultList = new QListWidget(centralwidget);
        SearchResultList->setObjectName("SearchResultList");
        SearchResultList->setGeometry(QRect(90, 0, 451, 301));
        print = new QLabel(centralwidget);
        print->setObjectName("print");
        print->setGeometry(QRect(90, 300, 451, 16));
        ClearResult = new QPushButton(centralwidget);
        ClearResult->setObjectName("ClearResult");
        ClearResult->setGeometry(QRect(0, 210, 91, 24));
        ExitButton = new QPushButton(centralwidget);
        ExitButton->setObjectName("ExitButton");
        ExitButton->setGeometry(QRect(0, 233, 91, 101));
        ResumeIndexingButton = new QPushButton(centralwidget);
        ResumeIndexingButton->setObjectName("ResumeIndexingButton");
        ResumeIndexingButton->setGeometry(QRect(0, 60, 91, 24));
        indexlabel = new QLabel(centralwidget);
        indexlabel->setObjectName("indexlabel");
        indexlabel->setGeometry(QRect(90, 320, 451, 16));
        searchlabel = new QLabel(centralwidget);
        searchlabel->setObjectName("searchlabel");
        searchlabel->setGeometry(QRect(90, 340, 451, 16));
        Interface->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Interface);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 544, 22));
        Interface->setMenuBar(menubar);
        statusbar = new QStatusBar(Interface);
        statusbar->setObjectName("statusbar");
        Interface->setStatusBar(statusbar);

        retranslateUi(Interface);

        QMetaObject::connectSlotsByName(Interface);
    } // setupUi

    void retranslateUi(QMainWindow *Interface)
    {
        Interface->setWindowTitle(QCoreApplication::translate("Interface", "Interface", nullptr));
        ByNameRadio->setText(QCoreApplication::translate("Interface", "By Name", nullptr));
        ByExtensionRadio->setText(QCoreApplication::translate("Interface", "By Extension", nullptr));
        ByDateRadio->setText(QCoreApplication::translate("Interface", "By Date", nullptr));
        BySizeRadio->setText(QCoreApplication::translate("Interface", "By Size", nullptr));
        StartIndexingButton->setText(QCoreApplication::translate("Interface", "Start Indexing", nullptr));
        PauseIndexingButton->setText(QCoreApplication::translate("Interface", "Pause Ind", nullptr));
        StopIndexingButton->setText(QCoreApplication::translate("Interface", "Stop Ind", nullptr));
        SearchButton->setText(QCoreApplication::translate("Interface", "Search", nullptr));
        SearchRequestLine->setText(QCoreApplication::translate("Interface", "Enter request", nullptr));
        print->setText(QCoreApplication::translate("Interface", "Event", nullptr));
        ClearResult->setText(QCoreApplication::translate("Interface", "Clear", nullptr));
        ExitButton->setText(QCoreApplication::translate("Interface", "Exit", nullptr));
        ResumeIndexingButton->setText(QCoreApplication::translate("Interface", "Resume Ind", nullptr));
        indexlabel->setText(QCoreApplication::translate("Interface", "Indexing file:", nullptr));
        searchlabel->setText(QCoreApplication::translate("Interface", "Searching file:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Interface: public Ui_Interface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERFACE_H
