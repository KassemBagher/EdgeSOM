//
// Created by Kassem Bagher on 2019-04-16.
//

#include "SquareMesh.h"


std::vector<std::vector<double>> SquareMesh::weights(std::vector<std::vector<double>> &data, int clusters) {

    int n = calculateN(clusters);

    std::vector<std::vector<double>> weights;

    double xMin = HelperFunctions::min(data, 0);
    double xMax = HelperFunctions::max(data, 0);

    double yMin = HelperFunctions::min(data, 1);
    double yMax = HelperFunctions::max(data, 1);

    double xStepSize = (xMax - xMin) / (n - 1);
    double yStepSize = (yMax - yMin) / (n - 1);


    for (int y = 0; y < n * n; y++) {
        double xPoint = xMin + (xStepSize * (double) (y % n));
        double yPoint = (yMax - (yStepSize * (double) (y / n)));
        weights.push_back({xPoint, yPoint});
    }

    return weights;
}


int SquareMesh::calculateN(int clusters) {
    return (int) ceil(sqrt(clusters * 2));
}

int SquareMesh::mapSize(int clusters) {

    return ceil(sqrt(2 * clusters));
}

SquareMesh::SquareMesh() {}



