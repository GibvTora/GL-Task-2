//FileIndexer.cpp
#include "FileIndexer.h"
#include <QDir>
#include <QFileInfo>
#include <QCoreApplication>
#include <QXmlStreamWriter>

FileIndexer::FileIndexer(const QString& indexPath, QLabel* indexlabel, bool &stopRequested)
    : indexPath(indexPath.toStdString()), indexlabel(indexlabel), stopRequested(stopRequested) {
    // Constructor implementation
}


void FileIndexer::StartIndexing() {
    QDir rootDir("C:/");

    if (!rootDir.exists()) {
        indexlabel->setText("Invalid root directory.");
        return;
    }

    indexlabel->setText("Indexing started...");

    IndexDirectory(rootDir);

    indexlabel->setText("Indexing complete.");
}

void FileIndexer::PauseIndexing() {
    mutex.lock();
    stopRequested = true;
    mutex.unlock();
}

void FileIndexer::StopIndexing() {
    mutex.lock();
    stopRequested = true;
    mutex.unlock();
}

void FileIndexer::IndexDirectory(const QDir& directory) {
    const int batchSize = 5;
    int fileCount = 0;

    QFileInfoList entries = directory.entryInfoList(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot);
    for (const QFileInfo& entry : entries) {

        if (stopRequested) {
            mutex.lock();
            condition.wait(&mutex);
            mutex.unlock();
        }


        if (entry.isDir()) {
            QDir subDir(entry.filePath());
            IndexDirectory(subDir);
        } else if (entry.isFile()) {
            const QString fileName = entry.fileName();
            const QString filePath = entry.filePath();
            const QDateTime fileDateTime = entry.lastModified();
            const qint64 fileSize = entry.size();

            indexlabel->setText(QString("Indexing file: %1").arg(fileName));
            SaveFileMetadata(fileName, fileDateTime, fileSize, filePath);

            fileCount++;
            if (fileCount % batchSize == 0) {
                QCoreApplication::processEvents();  // Allow GUI updates
            }
        }
    }
}

void FileIndexer::SaveFileMetadata(const QString& name, const QDateTime& date, qint64 size, const QString& path) {
    QFile xmlFile("index.xml");

    if (!xmlFile.open(QIODevice::Append | QIODevice::Text))
        return;

    QXmlStreamWriter xmlWriter(&xmlFile);
    xmlWriter.setAutoFormatting(true);

    xmlWriter.writeStartElement("file");
    xmlWriter.writeTextElement("name", name);
    xmlWriter.writeTextElement("date", date.toString("yyyy-MM-dd"));
    xmlWriter.writeTextElement("size", QString::number(size));
    xmlWriter.writeTextElement("path", path);
    xmlWriter.writeEndElement();  // </file>

    xmlFile.close();
}

void FileIndexer::ResumeIndexing() {
    mutex.lock();
    stopRequested = false;
    condition.wakeAll();
    mutex.unlock();
}
