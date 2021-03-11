//
// Created by Kassem Bagher on 2019-04-16.
//

#include "ServersLayer.h"
#include "DataManager.h"
#include "SOM.h"
#include "HelperFunctions.h"

std::vector<std::vector<double>> ServersLayer::clusterData(std::vector<std::vector<double>> &data) {

    int maxServers = HelperFunctions::maxNumOfServers(data, weightFunction->mapSize(numOfClusters));
    if (numOfServers > maxServers) {
        fprintf(stderr,
                "\nPOSSIBLE INACCURATE RESULTS!\nMax Number of suggested servers based on the input data size is (%d).\n"
                "The current number of servers is set to (%d) and WILL NOT be changed.\n"
                "Data size is (%d)\n\n",
                maxServers, numOfServers, data.size());
    }
    DataManager dm;
    vector<vector<vector<double>>> partitions;
    dm.splitData(data, partitions, numOfServers);
    std::vector<std::vector<double>> clusters = {};

    for (auto p:partitions) {
        vector<vector<double>> weights = weightFunction->weights(p, numOfClusters);
        SOM som = SOM::builder()
                .setEpochs(epochs)
                .setLearningRate(learningRate)
                .setNeighborhoodSize(neighborhoodSize)
                .setNumberOfClusters(weights.size())
                .build();
        som.trainData(p, weights);

        vector<vector<double>> tmpWeights = som.getWeights();
        clusters.insert(clusters.end(), tmpWeights.begin(), tmpWeights.end());
    }
    return clusters;
}

ServersLayer::ServersLayer(int numOfClusters, int epochs, int numOfServers, double neighborhoodSize,
                           double learningRate,
                           WeightFunction *weightFunction) :
        numOfClusters(numOfClusters),
        epochs(epochs),
        numOfServers(numOfServers),
        neighborhoodSize(
                neighborhoodSize),
        learningRate(
                learningRate),
        weightFunction(
                weightFunction) {}
