//FileIndexer.h
#pragma once

#include <string>
#include <sstream>
#include <fstream>
#include <QListWidget>
#include <QMutex>
#include <QThread>
#include <QWaitCondition>
#include <QLabel>
#include <QDir>

class FileIndexer {
public:
    FileIndexer(const QString& indexPath, QLabel* indexlabel, bool &stopRequested);

    void StartIndexing();
    void PauseIndexing();
    void StopIndexing();
    bool isPaused();
    void ResumeIndexing();
    void SaveFileMetadata(const QString& name, const QDateTime& date, qint64 size, const QString& path);

private:
    std::string indexPath;
    QLabel* indexlabel;
    bool stopRequested;
    QMutex mutex;
    QWaitCondition condition;

    void IndexDirectory(const QDir& directory);
};




class FileIndexerThread : public QThread
{
public:
    FileIndexerThread(const QString &indexPath, QLabel *indexlabel, bool &stopRequested)
    {
        fileIndexer = new FileIndexer(indexPath, indexlabel, stopRequested);
    }

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
