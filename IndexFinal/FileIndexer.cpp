#include "FileIndexer.h"
#include <ui_interface.h>
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <QLabel>

FileIndexer::FileIndexer(const std::string& indexPath, QLabel* indexlabel, bool &stopRequested)
    : indexPath(indexPath), indexlabel(indexlabel), stopRequested(stopRequested) // Pass the reference
{
}

FileIndexerThread::~FileIndexerThread() {
    if (fileIndexer) {
        delete fileIndexer;
        fileIndexer = nullptr;
    }
}
FileIndexer::~FileIndexer() {}

void FileIndexer::StartIndexing() {
    WIN32_FIND_DATA findFileData;
    HANDLE hFind = FindFirstFile(L"C:/*", &findFileData);

    if (hFind != INVALID_HANDLE_VALUE) {
        do {
            //Перевірка чи запитано зупинку індексації
            mutex.lock();
            if (stopRequested) {
                condition.wait(&mutex);
            }
            mutex.unlock();

            std::wstring directoryPath = L"C:/";
            if (!(findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
                std::wstring wFilePath = findFileData.cFileName;
                std::wstring wFullFilePath = directoryPath + wFilePath;
                std::string filePath(wFullFilePath.begin(), wFullFilePath.end());
                std::wstring wFileName = findFileData.cFileName;
                std::string fileName(wFileName.begin(), wFileName.end());

                FILETIME fileTime = findFileData.ftLastWriteTime;
                SYSTEMTIME sysTime;
                FileTimeToSystemTime(&fileTime, &sysTime);

                std::ostringstream oss;
                oss << sysTime.wYear << '-' << std::setw(2) << std::setfill('0') << sysTime.wMonth << '-'
                    << std::setw(2) << std::setfill('0') << sysTime.wDay;  // Remove time parts here

                const std::string formattedTime = oss.str();
                const long long fileSize = (static_cast<long long>(findFileData.nFileSizeHigh) << 32) | findFileData.nFileSizeLow;

                indexlabel->setText(QString("Indexing file: %1").arg(QString::fromStdString(fileName)));
                SaveFileMetadata(fileName, formattedTime, fileSize, filePath);

            }
            else if (findFileData.cFileName[0] != L'.' && (findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
                std::wstring wDirectoryPath = directoryPath + findFileData.cFileName;
                IndexDirectory(wDirectoryPath);
            }
        } while (FindNextFile(hFind, &findFileData) != 0);
        FindClose(hFind);
    }

    indexlabel->setText("Indexing complete.");
}
void FileIndexer::PauseIndexing() {
    mutex.lock();
    stopRequested = true;
    paused = true;
    mutex.unlock();
}
void FileIndexer::StopIndexing() {
    // Зупиняємо індексацію без можливості поновлення
    mutex.lock();
    stopRequested = true;
    mutex.unlock();
   // Зупинити індексацію
    // Розблокувати доступ до потоку
}
void FileIndexer::IndexDirectory(const std::wstring& directoryPath) {
    WIN32_FIND_DATA findFileData;
    std::wstring searchPath = directoryPath + L"\\*.*";
    HANDLE hFind = FindFirstFile(searchPath.c_str(), &findFileData);

    int fileCount = 0;
    const int batchSize = 5;

    if (hFind != INVALID_HANDLE_VALUE) {
        do {
            mutex.lock();
            if (stopRequested) {
                condition.wait(&mutex);


            }
            mutex.unlock();

            if (!(findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
                std::wstring wFilePath = findFileData.cFileName;
                std::wstring wFullFilePath = directoryPath + L"\\" + wFilePath;
                std::string filePath(wFullFilePath.begin(), wFullFilePath.end());
                std::wstring wFileName = findFileData.cFileName;
                std::string fileName(wFileName.begin(), wFileName.end());

                FILETIME fileTime = findFileData.ftLastWriteTime;
                SYSTEMTIME sysTime;
                FileTimeToSystemTime(&fileTime, &sysTime);

                std::ostringstream oss;
                oss << sysTime.wYear << '-' << std::setw(2) << std::setfill('0') << sysTime.wMonth << '-'
                    << std::setw(2) << std::setfill('0') << sysTime.wDay;

                const std::string formattedTime = oss.str();
                const long long fileSize = (static_cast<long long>(findFileData.nFileSizeHigh) << 32) | findFileData.nFileSizeLow;
                mutex.lock();
                if (fileCount % batchSize == 0) {
                    indexlabel->setText(QString("Indexing file: %1").arg(QString::fromStdString(fileName)));
                }
                mutex.unlock();
                SaveFileMetadata(fileName, formattedTime, fileSize, filePath);
                fileCount++;

            }
            else if (findFileData.cFileName[0] != L'.' && (findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
                std::wstring wDirectoryPath = directoryPath + L"\\" + findFileData.cFileName;
                IndexDirectory(wDirectoryPath);
            }
        } while (FindNextFile(hFind, &findFileData) != 0);
        FindClose(hFind);
    }

}
void FileIndexer::SaveFileMetadata(const std::string& name, const std::string& date, long long size, const std::string& path) {
    std::ofstream xmlFile(indexPath, std::ios::app);

    xmlFile << "<file>" << std::endl;
    xmlFile << "    <name>" << name << "</name>" << std::endl;
    xmlFile << "    <date>" << date << "</date>" << std::endl;
    xmlFile << "    <size>" << size << "</size>" << std::endl;
    xmlFile << "    <path>" << path << "</path>" << std::endl;
    xmlFile << "</file>" << std::endl;

    xmlFile.close();
}
void FileIndexer::ResumeIndexing() {

        mutex.lock();
        condition.wakeAll();
        stopRequested = false;
        mutex.unlock();

}
