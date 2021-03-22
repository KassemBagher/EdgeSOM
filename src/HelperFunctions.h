//
// Created by Kassem Bagher on 2019-04-16.
//

#ifndef EDGESOM_HELPERFUNCTIONS_H
#define EDGESOM_HELPERFUNCTIONS_H

#include <vector>
#include "cmath"
#include <iostream>
#include <iomanip>


//using namespace std;

class HelperFunctions {
public:
    static double min(std::vector<std::vector<double>> &data, int column);

    static double max(std::vector<std::vector<double>> &data, int column);

    static int maxNumOfServers(std::vector<std::vector<double>> &data, int size);

    static double distance(double &x1, double &y1, double &x2, double &y2);

    static void printPoints(std::vector<std::vector<double>> &data, std::string title);

};

#endif //EDGESOM_HELPERFUNCTIONS_H
