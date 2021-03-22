//
// Created by Kassem Bagher on 2019-04-16.
//

#ifndef EDGESOM_DATAMANAGER_H
#define EDGESOM_DATAMANAGER_H

#include <string>
#include <vector>

using namespace std;

class DataManager {
private:
    vector<vector<double>> data;

    void loadData(const string &fileName);

public:
    DataManager();

    DataManager(string fileName);

    ~DataManager();      // destructor

    vector<vector<double>> getData();

    void splitData(vector<vector<double>> &dataFrom, vector<vector<vector<double>>> &dataTo, int splits);
};


#endif //EDGESOM_DATAMANAGER_H
