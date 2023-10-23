//SearchEngine.cpp
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

        searchInDirectory(rootPath,name,results,SearchType::ByName);
    }
    searchlabel->setText(QString("Search by name finished!"));
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

    if (results.empty()) {
        searchlabel->setText(QString("Search on local PC started!"));

        std::string rootPath = "C:/";

        searchInDirectory(rootPath,extension,results,SearchType::ByExtension);
    }

    searchlabel->setText(QString("Search by extension finished!"));
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

    if (results.empty()) {
        searchlabel->setText(QString("Search on local PC started!"));

        std::string rootPath = "C:/";

        searchInDirectory(rootPath,date,results,SearchType::ByDate);
    }

    searchlabel->setText(QString("Search by date finished!"));
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

    if (results.empty()) {
        searchlabel->setText(QString("Search on local PC started!"));

        std::string rootPath = "C:/";

        searchInDirectory(rootPath,std::to_string(size),results,SearchType::BySize);
    }

    searchlabel->setText(QString("Search by size finished!"));
    return results;
}

void SearchEngine::searchInDirectory(const std::string& currentPath, const std::string& searchTerm, std::vector<std::string>& results, SearchType searchType) {
    QDir dir(QString::fromStdString(currentPath));
    QStringList files = dir.entryList(QDir::Files);
    int fileCount = 0;
    const int batchSize = 5;

    for (const QString& file : files) {
        std::string filePath = dir.absoluteFilePath(file).toStdString();

        searchlabel->setText(QString("Searching file: %1").arg(QString::fromStdString(filePath)));

        bool shouldAdd = false;

        // В зависимости от типа поиска, определите, следует ли добавить этот файл в результаты
        if (searchType == SearchType::ByName) {
            shouldAdd = (file.toStdString() == searchTerm);
        } else if (searchType == SearchType::ByExtension) {
            // Проверьте расширение файла
            // Для поиска по расширению, searchTerm - это расширение (например, ".txt")
            shouldAdd = (QFileInfo(filePath.c_str()).suffix().toStdString() == searchTerm);
        } else if (searchType == SearchType::ByDate) {
            // Реализуйте поиск по дате файла
            // searchTerm - это дата в нужном формате (например, "2023-10-23")
            QDateTime fileDate = QFileInfo(filePath.c_str()).lastModified();
            QDateTime searchDate = QDateTime::fromString(QString::fromStdString(searchTerm), "yyyy-MM-dd");

            if (fileDate.date() == searchDate.date()) {
                shouldAdd = true;
            }
        } else if (searchType == SearchType::BySize) {
            // Реализуйте поиск по размеру файла
            // searchTerm - это размер в байтах
            qint64 fileSize = QFileInfo(filePath.c_str()).size();
            qint64 searchSize = std::stoll(searchTerm);

            if (fileSize == searchSize) {
                shouldAdd = true;
            }
        }

        if (shouldAdd) {
            results.push_back(filePath);
        }

        fileCount++;
        if (fileCount % batchSize == 0) {
            QCoreApplication::processEvents();  // Allow GUI updates
        }
    }

    QStringList subdirs = dir.entryList(QDir::AllDirs | QDir::NoDotAndDotDot);
    for (const QString& subdir : subdirs) {
        searchInDirectory(dir.absoluteFilePath(subdir).toStdString(), searchTerm, results, searchType);
    }
}
