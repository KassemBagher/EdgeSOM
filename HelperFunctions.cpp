//
// Created by Kassem Bagher on 2019-04-16.
//

#include "HelperFunctions.h"

double HelperFunctions::min(std::vector<std::vector<double>> &data, int column) {
    double min = data[0][column];

    for (int x = 0; x < data.size(); x++) {
        if (data[x][column] < min)
            min = data[x][column];
    }
    return min;
}


double HelperFunctions::max(std::vector<std::vector<double>> &data, int column) {
    double min = data[0][column];

    for (int x = 0; x < data.size(); x++) {
        if (data[x][column] > min)
            min = data[x][column];
    }
    return min;
}

int HelperFunctions::maxNumOfServers(std::vector<std::vector<double>> &data, int size) {
    return floor(data.size() / (pow(size, 2) * 2));
}


double HelperFunctions::distance(double &x1, double &y1, double &x2, double &y2) {
    double distance = 0.0;
    distance += pow(x1 - x2, 2);
    distance += pow(y1 - y2, 2);
    return sqrt(distance);
}


double HelperFunctions::printPoints(std::vector<std::vector<double>> &data, std::string title) {
    std::cout << "===== "<< title <<" BEGIN ====" << std::endl;
    for (int i = 0; i < data.size(); ++i) {
        std::cout << std::setprecision(15) << data[i][0] << "," << data[i][1] << std::endl;
    }
    std::cout << "===== "<< title <<" END ====" << std::endl;
}
