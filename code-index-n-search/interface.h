//interface.h
#pragma once
#include <QMainWindow>
class FileIndexerThread;
class SearchThread;

QT_BEGIN_NAMESPACE
namespace Ui { class Interface; }
QT_END_NAMESPACE

class Interface : public QMainWindow
{
    Q_OBJECT

public:
    Interface(QWidget *parent = nullptr);
    ~Interface();
    friend class FileIndexerThread;
private slots:
    void on_StartIndexingButton_clicked();
    void on_PauseIndexingButton_clicked();
    void on_StopIndexingButton_clicked();
    void on_SearchButton_clicked();
    void on_ClearResult_clicked();
    void on_ExitButton_clicked();
    void on_ResumeIndexingButton_clicked();
    void handleSearchResults(const std::vector<std::string>& results);


private:
    Ui::Interface *ui;
    bool startCheck = false;
    FileIndexerThread *fileIndexerThread = nullptr;
    SearchThread *searchThread = nullptr;
};

