//
// Created by Kassem Bagher on 2019-04-16.
//

#ifndef EDGESOM_WEIGHTFUNCTION_H
#define EDGESOM_WEIGHTFUNCTION_H

#include <vector>

class WeightFunction {
public:
    WeightFunction() {}

    virtual ~WeightFunction() {}

    virtual std::vector<std::vector<double>> weights(std::vector<std::vector<double>> &data, int clusters) = 0;

    virtual int mapSize(int clusters) = 0;
};

#endif //EDGESOM_WEIGHTFUNCTION_H
