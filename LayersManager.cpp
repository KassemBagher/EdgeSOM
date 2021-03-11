//
// Created by Kassem Bagher on 2019-04-16.
//

#include <iostream>
#include <iomanip>
#include "LayersManager.h"

void LayersManager::addServerLayer(ServersLayer layer) {
    serversLayers.push_back(layer);
}

void LayersManager::setMergingLayer(MergingLayer layer) {
    mergingLayer = layer;
}

vector<vector<double>> LayersManager::run(vector<vector<double>> &data) {
    vector<vector<double>> clusters = data;
    for (auto l:serversLayers) {
        vector<vector<double>> tmpClusters = l.clusterData(clusters);
        clusters = tmpClusters;
    }
    mergingLayer.merge(clusters);
    return clusters;
}