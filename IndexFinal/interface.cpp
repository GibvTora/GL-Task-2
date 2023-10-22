#include "interface.h"
#include "ui_interface.h"
#include "FileIndexer.h"
#include "SearchEngine.h"
#include <QThread>
#include <QWaitCondition>

Interface::Interface(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Interface)
{
    ui->setupUi(this);

}

Interface::~Interface()
{
    delete ui;
}

void Interface::on_StartIndexingButton_clicked()
{
    if (!startCheck)
    {
        QString indexPath = "index.xml";
        bool stopRequested = false;
        fileIndexerThread = new FileIndexerThread(indexPath, ui->indexlabel, stopRequested);
        QThread::sleep(3);
        fileIndexerThread->start();
        startCheck = true;
        ui->print->setText("Thread Started!");
    }

}

void Interface::on_PauseIndexingButton_clicked() {
    if (fileIndexerThread) {
        fileIndexerThread->pause();
        ui->print->setText("Thread Paused!");
    }
    startCheck = false;
}

void Interface::on_StopIndexingButton_clicked()
{
    if (fileIndexerThread) {
        fileIndexerThread->stop();}

    if (fileIndexerThread && fileIndexerThread->isFinished()) {
            delete fileIndexerThread;
        ui->print->setText("Thread Stoped!");
        }
    startCheck = false;
}

void Interface::on_SearchButton_clicked() {
    QString request = ui->SearchRequestLine->text();

    if (ui->ByNameRadio->isChecked()) {
        ui->print->setText("Search by name started!");
        searchThread = new SearchThread("index.xml", ui->searchlabel, request.toStdString(), 1);
    } else if (ui->ByExtensionRadio->isChecked()) {
        ui->print->setText("Search by extension started!");
        searchThread = new SearchThread("index.xml", ui->searchlabel, request.toStdString(), 2);
    } else if (ui->ByDateRadio->isChecked()) {
        ui->print->setText("Search by date started!");
        searchThread = new SearchThread("index.xml", ui->searchlabel, request.toStdString(), 3);
    } else if (ui->BySizeRadio->isChecked()) {
        ui->print->setText("Search by size started!");
        searchThread = new SearchThread("index.xml", ui->searchlabel, request.toStdString(), 4);
    } else {
        ui->indexlabel->setText("Please select a search type.");
        return;
    }

    searchThread->start();
    // Підключіть сигнал для отримання результатів
    connect(searchThread, &SearchThread::searchCompleted, this, &Interface::handleSearchResults);


}

void Interface::handleSearchResults(const std::vector<std::string>& results) {
    ui->SearchResultList->clear();
    for (const std::string& result : results) {
        QString qResult = QString::fromStdString(result);
        ui->SearchResultList->addItem(qResult);
    }
}
void Interface::on_ClearResult_clicked() {
    ui->SearchResultList->clear();
}

void Interface::on_ExitButton_clicked() {
    exit(1);
}

void Interface::on_ResumeIndexingButton_clicked()
{
    fileIndexerThread->resume();
    ui->print->setText("Thread Resumed!");
}

