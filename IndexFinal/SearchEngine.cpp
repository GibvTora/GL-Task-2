#include "SearchEngine.h"
#include "ui_interface.h"
#include "interface.h"


SearchEngine::SearchEngine(const std::string& indexPath, QLabel* searchlabel) : indexPath(indexPath), searchlabel(searchlabel) {}

SearchThread::~SearchThread() {
    if (searchEngine) {
        delete searchEngine;
        searchEngine = nullptr;
    }
}

std::vector<std::string> SearchEngine::SearchByName(const std::string& name) {
    std::vector<std::string> results = {};

    // Пошук у файлі `indexPath`
    std::ifstream indexFile(indexPath);
    std::string line;

    while (std::getline(indexFile, line)) {
        if (line.find("<name>" + name + "</name>") != std::string::npos) {
            std::string pathLine;

            while (std::getline(indexFile, pathLine)) {
                if (pathLine.find("<path>") != std::string::npos) {
                    std::string filePath = pathLine.substr(pathLine.find("<path>") + 6);
                    filePath = filePath.substr(0, filePath.find("</path>"));
                    results.push_back(filePath);
                    break;
                }
            }
        }
    }

    indexFile.close();

    if (results.empty()) {
        searchlabel->setText(QString("Search on local PC started!"));

        std::string rootPath = "C:/";

        searchInDirectory(rootPath,name,results);
    }

    return results;
}
std::vector<std::string> SearchEngine::SearchByExtension(const std::string& extension) {
    std::vector<std::string> results;
    std::ifstream indexFile(indexPath);
    std::string line;

    while (std::getline(indexFile, line)) {
        if (line.find("<name>") != std::string::npos) {
            std::string name = line.substr(line.find("<name>") + 6);
            name = name.substr(0, name.find("</name>"));

            if (name.rfind(extension) == (name.length() - extension.length())) {
                std::string pathLine;

                while (std::getline(indexFile, pathLine)) {
                    if (pathLine.find("<path>") != std::string::npos) {
                        std::string filePath = pathLine.substr(pathLine.find("<path>") + 6);
                        filePath = filePath.substr(0, filePath.find("</path>"));
                        results.push_back(filePath);
                        break;
                    }
                }
            }
        }
    }

    indexFile.close();
    return results;
}
std::vector<std::string> SearchEngine::SearchByDate(const std::string& date) {
    std::vector<std::string> results;
    std::ifstream indexFile(indexPath);
    std::string line;

    while (std::getline(indexFile, line)) {
        if (line.find("<date>" + date + "</date>") != std::string::npos) {
            std::string pathLine;

            while (std::getline(indexFile, pathLine)) {
                if (pathLine.find("<path>") != std::string::npos) {
                    std::string filePath = pathLine.substr(pathLine.find("<path>") + 6);
                    filePath = filePath.substr(0, filePath.find("</path>"));
                    results.push_back(filePath);
                    break;
                }
            }
        }
    }

    indexFile.close();
    return results;
}
std::vector<std::string> SearchEngine::SearchBySize(long long size) {
    std::vector<std::string> results;
    std::ifstream indexFile(indexPath);
    std::string line;

    while (std::getline(indexFile, line)) {
        if (line.find("<size>" + std::to_string(size) + "</size>") != std::string::npos) {
            std::string pathLine;

            while (std::getline(indexFile, pathLine)) {
                if (pathLine.find("<path>") != std::string::npos) {
                    std::string filePath = pathLine.substr(pathLine.find("<path>") + 6);
                    filePath = filePath.substr(0, filePath.find("</path>"));
                    results.push_back(filePath);
                    break;
                }
            }
        }
    }

    indexFile.close();
    return results;
}
void SearchEngine::searchInDirectory(const std::string& currentPath, const std::string& name, std::vector<std::string>& results) {
    QDir dir(QString::fromStdString(currentPath));
    QStringList files = dir.entryList(QDir::Files);
    int fileCountS = 0;
    const int batchSizeS = 30;
    for (const QString& file : files) {
        std::string filePath = dir.absoluteFilePath(file).toStdString();
        mutexS.lock();
        if (fileCountS % batchSizeS == 0) {
            searchlabel->setText(QString("Searching file: %1").arg(QString::fromStdString(filePath)));
        }
        mutexS.unlock();

        if (file.toStdString() == name) {
            results.push_back(filePath);
        }
        fileCountS++;
    }

    QStringList subdirs = dir.entryList(QDir::AllDirs | QDir::NoDotAndDotDot);
    for (const QString& subdir : subdirs) {
        searchInDirectory(dir.absoluteFilePath(subdir).toStdString(), name, results);
    }
}
