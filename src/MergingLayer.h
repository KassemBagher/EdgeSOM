//
// Created by Kassem Bagher on 2019-04-16.
//

#ifndef EDGESOM_MERGINGLAYER_H
#define EDGESOM_MERGINGLAYER_H


#include "ClosestPair.h"
#include "WeightFunction.h"

class MergingLayer {
private:
    Point2D mergePoints(Point2D &p1, Point2D &p2);

    int pointIndex(std::vector<std::vector<double>> &data, Point2D p);

private:
    int epochs = 1;
    int numOfClusters = 1;
    double neighborhoodSize = 0;
    double learningRate = 1;
    WeightFunction *weightFunction;
public:
    MergingLayer(int epochs, int numOfClusters, double neighborhoodSize, double learningRate,
                 WeightFunction *weightFunction);

    MergingLayer() = default;

    class builder;

public:
    void merge(std::vector<std::vector<double>> &data);
};


class MergingLayer::builder {
public:

    builder &setEpochs(int value) {
        epochs = value;
        return *this;
    };

    builder &setNeighborhoodSize(double value) {
        neighborhoodSize = value;
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

    MergingLayer build() const {
        return MergingLayer{epochs, numOfClusters, neighborhoodSize, learningRate, weightFunction};
    }

private:
    int epochs = 1;
    int numOfClusters = 1;
    double neighborhoodSize = 0;
    double learningRate = 1;
    WeightFunction *weightFunction;
};


#endif //EDGESOM_MERGINGLAYER_H
