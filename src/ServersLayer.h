//
// Created by Kassem Bagher on 2019-04-16.
//

#ifndef EDGESOM_SERVERSLAYER_H
#define EDGESOM_SERVERSLAYER_H

#include "WeightFunction.h"
#include "DataManager.h"
#include <vector>

class ServersLayer {
private:
    int epochs;
    int numOfServers;
    int numOfClusters;
    double neighborhoodSize;
    double learningRate=1;
public:
    ServersLayer(int numOfClusters, int epochs, int numOfServers, double neighborhoodSize, double learningRate,
                 WeightFunction *weightFunction);

    class builder;

private:
    std::vector<std::vector<double>> data = {};
    WeightFunction *weightFunction;

public:
    std::vector<std::vector<double>> clusterData(std::vector<std::vector<double>> &data);
};

class ServersLayer::builder {
public:
    builder &setEpochs(int value) {
        epochs = value;
        return *this;
    };

    builder &setNeighborhoodSize(double value) {
        neighborhoodSize = value;
        return *this;
    };

    builder &setServers(int value) {
        numOfServers = value;
        return *this;
    };

    builder &setClusters(int value) {
        numOfClusters = value;
        return *this;
    };

    builder &setLearningRate(double value) {
        learningRate = value;
        return *this;
    };

    builder &setWeightFunction(WeightFunction *value) {
        weightFunction = value;
        return *this;
    };

    ServersLayer build() const {
        return ServersLayer{numOfClusters, epochs, numOfServers, neighborhoodSize, learningRate, weightFunction};
    }

private:
    int epochs = 1;
    int numOfServers = 1;
    int numOfClusters = 1;
    double neighborhoodSize = 0;
    double learningRate = 1;
    WeightFunction *weightFunction;
};


#endif //EDGESOM_SERVERSLAYER_H
