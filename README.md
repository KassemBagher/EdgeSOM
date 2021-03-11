# EdgeSOM: Distributed Hierarchical Edge-driven IoT Data Analytics Framework
*A distributed and hierarchical MEC-based data analytics framework*

## What is EdgeSOM?
EdgeSOM is a distributed and hierarchical MEC-based data analytics framework. The framework uses the combination of an enhanced Self-organising Map (SOM)
and a Hierarchical Agglomerative Clustering (HAC) algorithm for distributed data clustering. EdgeSOM is fully distributed, such that MEC servers do not require a synchronisation server to cluster the data initially. EdgeSOM significantly reduces the network traffic of the aggregated IoT raw data to the cloud while achieving highly accurate analysis results.

Our papers describe the motivation, architicture and evaluation of EdgeSOM:
- [Computer Communications](https://www.sciencedirect.com/science/article/pii/S0140366421000906)

## EdgeSOM simulation
This repository contains a simulation code for EdgeSOM architecture and does not contain a full end-to-end implementation. Yet, the code provided for EdgeSOM performs a distributed clustering using an enhanced self-organising map (SOM).

## How to run EdgeSOM
The quickest and easiest way to use EdgeSOM is to run the sample code. The sample code can be found in the ``main.cpp`` file.
the main steps involved in the sample code are as follows:

Loading the dataste using the ``DataManager``
```cpp
DataManager dm("../sample_dataset.csv");
vector<vector<double>> data = dm.getData();
```
Creating a new layer of MEC servers (``ServersLayer``)
```cpp
ServersLayer serversLayer1 = ServersLayer::builder()
  .setClusters(10)
  .setNeighborhoodSize(0)
  .setLearningRate(1)
  .setEpochs(1000)
  .setServers(2)
  .setWeightFunction(new SquareMesh())
  .build();
```
Creating a merging layer (``MergingLayer``)
```cpp
MergingLayer mergingLayer = MergingLayer::builder()
  .setClusters(10)
  .setNeighborhoodSize(0)
  .setLearningRate(1)
  .setEpochs(200)
  .setWeightFunction(new SquareMesh())
  .build();
```

Creating a layers manager (``LayersManager``) and passing the layers to the layer manager
```cpp
LayersManager layersManager;
layersManager.addServerLayer(serversLayer1); // adding the servers layer
layersManager.setMergingLayer(mergingLayer); // adding the merging layer
```
Executing the distributed clustering by calling the ``run()`` function in the layers manager
```cpp
// runs the simulated architicure and returns the final clusters
vector<vector<double>> clusters = layersManager.run(data);
```
