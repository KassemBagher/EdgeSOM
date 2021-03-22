//
// Created by Kassem Bagher on 2019-04-16.
//

#include <cfloat>
#include "cmath"
#include "MergingLayer.h"
#include "iostream"
#include "SOM.h"

Point2D MergingLayer::mergePoints(Point2D &p1, Point2D &p2) {
    return {(p1.x + p2.x) / 2.0, (p1.y + p2.y) / 2.0};
}

int MergingLayer::pointIndex(std::vector<std::vector<double>> &data, Point2D p) {
    for (int i = 0; i < data.size(); ++i) {
        if (p.x == data[i][0] && p.y == data[i][1])
            return i;
    }
    return -1;
}

void MergingLayer::merge(std::vector<std::vector<double>> &data) {
    /**
     * Centroids > n.n
     * Perform final clustering before merging
     */
    int mapSize = weightFunction->mapSize(numOfClusters);
    if (data.size() > mapSize) {
        std::vector<std::vector<double>> weights = weightFunction->weights(data, numOfClusters);
        SOM som = SOM::builder()
                .setEpochs(epochs)
                .setLearningRate(learningRate)
                .setNeighborhoodSize(neighborhoodSize)
                .setNumberOfClusters(weights.size())
                .build();
        som.trainData(data, weights);
        data = som.getWeights();
    }

    // centroids = numOfClusters (k)
    if (data.size() == numOfClusters)
        return;

    /**
     * centroids > numOfClusters (k)
     * Merge the centroids until centroids = numOfClusters (k)
     */
    while (data.size() > numOfClusters) {
        ClosestPair closestPair;
        Point2D points2d[data.size()];

        for (int i = 0; i < data.size(); ++i) {
            points2d[i] = {data[i][0], data[i][1]};
        }

        Point2D p1 = Point2D();
        Point2D p2 = Point2D();

        // search closest
        int n = data.size();
        closestPair.closest(points2d, n, p1, p2);

        // merge results
        Point2D newPoint = mergePoints(p1, p2);

        // remove old points
        int pIndex = pointIndex(data, p1);
        data.erase(data.begin() + pIndex);
        pIndex = pointIndex(data, p2);
        data.erase(data.begin() + pIndex);

        // add new point
        data.push_back({newPoint.x, newPoint.y});
    }
}

MergingLayer::MergingLayer(int epochs, int numOfClusters, double neighborhoodSize, double learningRate,
                           WeightFunction *weightFunction) : epochs(epochs), numOfClusters(numOfClusters),
                                                             neighborhoodSize(neighborhoodSize),
                                                             learningRate(learningRate),
                                                             weightFunction(weightFunction) {}

