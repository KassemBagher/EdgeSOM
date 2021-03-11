//
// Created by Kassem Bagher on 2019-04-16.
//

#ifndef EDGESOM_LAYERSMANAGER_H
#define EDGESOM_LAYERSMANAGER_H

#include "ServersLayer.h"
#include "MergingLayer.h"

class LayersManager {
private:
    vector<ServersLayer> serversLayers = {};
    MergingLayer mergingLayer;

public:
    LayersManager() = default;

    void addServerLayer(ServersLayer layer);

    void setMergingLayer(MergingLayer layer);

    vector<vector<double>> run(vector<vector<double>> &data);
};


#endif //EDGESOM_LAYERSMANAGER_H
