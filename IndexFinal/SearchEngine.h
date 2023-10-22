#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <filesystem>
#include <fstream>

#include <QDir>
#include <QThread>
#include <QLabel>
#include <QMutex>


class SearchEngine {
public:
    SearchEngine(const std::string& indexPath, QLabel* searchlabel);


    std::vector<std::string> SearchByName(const std::string& name);
    std::vector<std::string> SearchByExtension(const std::string& extension);
    std::vector<std::string> SearchByDate(const std::string& date);
    std::vector<std::string> SearchBySize(long long size);
    void searchInDirectory(const std::string& currentPath, const std::string& name, std::vector<std::string>& results);

private:
    std::string indexPath;
    QLabel* searchlabel;
    QMutex mutexS;
};

class SearchThread : public QThread {
    Q_OBJECT

public:
    SearchThread(const std::string& indexPath, QLabel* searchlabel, const std::string& request, int SearchByCheck)
        : request(request), SearchByCheck(SearchByCheck) {
        searchEngine = new SearchEngine(indexPath,searchlabel);
    }
    ~SearchThread();
signals:
    void searchCompleted(const std::vector<std::string>& results);

protected:
    void run() override {
        std::vector<std::string> searchResults;
        if (SearchByCheck == 1) {
            searchResults = searchEngine->SearchByName(request);
        } else if (SearchByCheck == 2) {
            searchResults = searchEngine->SearchByExtension(request);
        } else if (SearchByCheck == 3) {
            searchResults = searchEngine->SearchByDate(request);
        } else if (SearchByCheck == 4) {
            searchResults = searchEngine->SearchBySize(std::stoll(request));
        } else {

            return;
        }

        emit searchCompleted(searchResults);
    }

private:

    std::string request;
    SearchEngine* searchEngine;
    std::string indexPath;
    QLabel* searchlabel;
    int SearchByCheck;
};

