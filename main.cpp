
#include <iostream>
#include "DataManager.h"
#include "SquareMesh.h"
#include "ServersLayer.h"
#include "LayersManager.h"
#include <time.h>


using namespace std;

int main() {

    // load 2D data for clustering
    /**
     * Load a 2D data using the DataManager class
     * The data will be loaded into a 2D vector
     * The CSV data should be formatted a follows
     *  x,y
     *  x,y
     *  x,y
     */
    DataManager dm("../sample_dataset.csv");
    vector<vector<double>> data = dm.getData();

    /**
     * The Servers Layer will simulate multiple server (i.e., MEC or Cloud server node)
     *
     * For example, if you are planing to simulate 3 MEC layers, tou will have to create
     * 3 objects and pass them to the LayersManager.
     *
     * The LayersManager manager will be responsible for clustering the data in each layer
     * and passing the output of each layer to the next one.
     */
    ServersLayer serversLayer1 = ServersLayer::builder()
            .setClusters(10)
            .setNeighborhoodSize(0)
            .setLearningRate(1)
            .setEpochs(1000)
            .setServers(2)
            .setWeightFunction(new SquareMesh())
            .build();

    /**
     * The merging layer will perform final clustering on the intermediate centroids and
     * merge the results to produce the final number of clusters.
     *
     * Note tha the merging layer should be the last layer added to the LayersManager.
     *
     */
    MergingLayer mergingLayer = MergingLayer::builder()
            .setClusters(10)
            .setNeighborhoodSize(0)
            .setLearningRate(1)
            .setEpochs(200)
            .setWeightFunction(new SquareMesh())
            .build();

    /**
     * The LayersManager is responsible for executing all layers in sequential.
     * The output of each layer will be sent to the next layer, including th merging layer.
     */
    LayersManager layersManager;
    layersManager.addServerLayer(serversLayer1); // adding the servers layer
    layersManager.setMergingLayer(mergingLayer); // adding the merging layer


    /**
     * Execute all layers and measure the execution time
     */
    clock_t tStart = clock();
    vector<vector<double>> clusters = layersManager.run(data);
    printf("Overall time: %.2fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);

    /**
     * Print out the final clusters
     */
    for (int i = 0; i < clusters.size(); ++i) {
        cout << clusters[i][0] << "," << clusters[i][1] << endl;
    }
}
