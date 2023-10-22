#pragma once

#include <string>
#include <sstream>
#include <fstream>
#include <QListWidget>
#include <QMutex>
#include <QThread>
#include <QWaitCondition>
#include <QLabel>

class FileIndexer {
public:
    FileIndexer(const std::string& indexPath, QLabel* indexlabel, bool &stopRequested);
    ~FileIndexer();

    void StartIndexing();
    void PauseIndexing();
    void StopIndexing();
    bool isPaused();
    void ResumeIndexing();
    void SaveFileMetadata(const std::string& name, const std::string& date, long long size, const std::string& path);

private:
    std::string indexPath;
    QListWidget* statusList;
    QLabel* indexlabel;
    void IndexDirectory(const std::wstring& directoryPath);
    bool stopRequested;
    bool paused;
    QMutex mutex;
    QWaitCondition condition;
};

class FileIndexerThread : public QThread
{
public:
    FileIndexerThread(const QString &indexPath, QLabel *indexlabel, bool &stopRequested)
    {
        fileIndexer = new FileIndexer(indexPath.toStdString(), indexlabel, stopRequested);
    }
    ~FileIndexerThread();
    void run() override
    {
        if (fileIndexer)
        {
            fileIndexer->StartIndexing();
        }
    }

    void pause()
    {
        if (fileIndexer)
        {
            fileIndexer->PauseIndexing();
        }
    }

    void stop()
    {
        if (fileIndexer)
        {
            fileIndexer->StopIndexing();
        }
    }

    void resume()
    {
        if (fileIndexer) {
            fileIndexer->ResumeIndexing();
        }
    }

private:
    QString indexPath;
    QLabel *indexlabel;
    FileIndexer *fileIndexer;
    bool stopRequested;
};
