//
// Created by Kassem Bagher on 2019-04-15.
//

#ifndef EDGESOM_SOM_H
#define EDGESOM_SOM_H

#include "SOM.h"
#include "cmath"
#include "cfloat"
#include <vector>
#include <set>
#include "list"

class SOM {

    // Constructors and builder
public:

    SOM();

    SOM(int epochs, double neighborhoodSize, int numberOfClusters, double learningRate);

    class builder;


    // private variables
private:
    int epochs;
    double neighborhoodSize;
    int numberOfClusters;
    double learningRate;
    std::vector<std::vector<double>> weights;
    size_t weightsSize;
    size_t inputSize;
    double *updatedWeights;
    double (*weightsArray)[2];
    double (*dataArray)[2];

    // private functions
private:

    void initData(std::vector<std::vector<double>> &inputData, std::vector<std::vector<double>> &weights);

    int smallestDistance(double &x, double &y);

    void updateWinnerClusterNode(int clusterNodeIndex, int inputIndex, double epoch);

    void updateNeighbours(int winnerNodeIndex, int neighbourIndex, int epoch);

    void getNodeNeighbours(int &winnerIndex, double &distance, std::list<int> &list);

    double pointsDistance(double &x1, double &y1, double &x2, double &y2);

    void skimWeight();

    // public functions
public:
    int getCluster(std::vector<double> &inputVector);

    std::vector<std::vector<double>> getWeights();

    void trainData(std::vector<std::vector<double>> &inputData, std::vector<std::vector<double>> weights);
};

class SOM::builder {
public:

    builder &setEpochs(int value) {
        epochs = value;
        return *this;
    };

    builder &setNeighborhoodSize(double value) {
        neighborhoodSize = value;
        return *this;
    };

    builder &setNumberOfClusters(int value) {
        numberOfClusters = value;
        return *this;
    };


    builder &setLearningRate(double value) {
        learningRate = value;
        return *this;
    };

    SOM build() const {
        return SOM{epochs, neighborhoodSize, numberOfClusters, learningRate};
    }

private:
    int epochs;
    double neighborhoodSize = 0;
    int numberOfClusters = 9;
    double learningRate = 1;
};


#endif //EDGESOM_SOM_H
