//
// Created by Kassem Bagher on 2019-04-16.
//

#include <iostream>
#include <fstream>
#include "DataManager.h"

DataManager::DataManager() = default;

DataManager::DataManager(string fileName) {
    loadData(fileName);
}

vector<vector<double>> DataManager::getData() {
    return data;
}

void DataManager::splitData(vector<vector<double>> &dataFrom, vector<vector<vector<double>>> &dataTo, int splits) {


    unsigned long fileSize = dataFrom.size() / splits;
    unsigned long lastFile = (fileSize * (splits - 1));
    lastFile = dataFrom.size() - lastFile;

    for (int x = 0; x < splits; x++) {
        if (x < splits - 1) {
            vector<vector<double>>::const_iterator first = dataFrom.begin() + (x * fileSize);
            vector<vector<double>>::const_iterator last = dataFrom.begin() + (x * fileSize) + fileSize;
            vector<vector<double>> newVec(first, last);
            dataTo.push_back(newVec);
        } else {
            vector<vector<double>>::const_iterator first = dataFrom.begin() + (x * fileSize);
            vector<vector<double>>::const_iterator last = dataFrom.begin() + (x * fileSize) + lastFile;
            vector<vector<double>> newVec(first, last);
            dataTo.push_back(newVec);
        }
    }
}

void DataManager::loadData(const string& fileName) {
    ifstream myReadFile;
    myReadFile.open(fileName);
    string line;
    size_t pos = 0;

    if (myReadFile.is_open()) {
        while (!myReadFile.eof()) {
            myReadFile >> line;
            // x
            pos = line.find(',');
            double x = stod(line.substr(0, pos));
            line.erase(0, pos + 1);
            // y
            pos = line.find(',');
            double y = stod(line.substr(0, pos));
            line.erase(0, pos + 1);
            // store data
            data.push_back({x, y});
        }
    } else {
        cout << "can't find the file " << fileName;
    }
    myReadFile.close();
}

DataManager::~DataManager() = default;
