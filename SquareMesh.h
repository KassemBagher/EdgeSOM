//
// Created by Kassem Bagher on 2019-04-16.
//

#ifndef EDGESOM_SQUAREMESH_H
#define EDGESOM_SQUAREMESH_H


#include "WeightFunction.h"
#include "HelperFunctions.h"
#include "cmath"

class SquareMesh : public WeightFunction {

private:
    int calculateN(int clusters);

public:
    SquareMesh();

    std::vector<std::vector<double>> weights(std::vector<std::vector<double>> &data, int clusters) override;

    int mapSize(int clusters) override;
};


#endif //EDGESOM_SQUAREMESH_H
