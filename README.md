# EdgeSOM: Distributed Hierarchical Edge-driven IoT Data Analytics Framework
*A distributed and hierarchical MEC-based data analytics framework*

## What is EdgeSOM?
EdgeSOM is a distributed and hierarchical MEC-based data analytics framework. The framework uses the combination of an enhanced Self-organising Map (SOM)
and a Hierarchical Agglomerative Clustering (HAC) algorithm for distributed data clustering. EdgeSOM is fully distributed, such that MEC servers do not require a synchronisation server to cluster the data initially. EdgeSOM significantly reduces the network traffic of the aggregated IoT raw data to the cloud while achieving highly accurate analysis results.

Our paper describes the motivation, architecture and evaluation of EdgeSOM ([COMCOM'21](https://www.sciencedirect.com/science/article/pii/S0140366421000906))

## EdgeSOM simulation
This repository contains a simulation code for EdgeSOM architecture and does not contain a full end-to-end implementation. The code simulates the EdgeSOM architecture and supports multiple layers of clustering. Yet, the code performs a fully distributed clustering using an enhanced self-organising map (SOM) and Hierarchical Agglomerative Clustering (HAC) algorithm, as described in [our paper](https://www.sciencedirect.com/science/article/pii/S0140366421000906).

## How to run EdgeSOM
The quickest and easiest way to use EdgeSOM is to run the sample code, which can be found in the ``main.cpp`` file.
The main steps involved in the sample code are as follows:

Loading the dataste using the ``DataManager`` helper class, which will load a CSV into a 2D vector.
```cpp
DataManager dm("../sample_dataset.csv");
vector<vector<double>> data = dm.getData();
```
Creating a new MEC servers layer by creating a new (``ServersLayer``) object.
```cpp
ServersLayer serversLayer1 = ServersLayer::builder()
  .setClusters(10)
  .setNeighborhoodSize(0)
  .setLearningRate(1)
  .setEpochs(50)
  .setServers(2)
  .setWeightFunction(new SquareMesh())
  .build();
```
Creating a merging layer by creating a new (``MergingLayer``) object
```cpp
MergingLayer mergingLayer = MergingLayer::builder()
  .setClusters(10)
  .setNeighborhoodSize(0)
  .setLearningRate(1)
  .setEpochs(50)
  .setWeightFunction(new SquareMesh())
  .build();
```

Creating a layers manager (``LayersManager``) object and passing the servers and merging layers to it.
```cpp
LayersManager layersManager;
layersManager.addServerLayer(serversLayer1); // adding the servers layer
layersManager.setMergingLayer(mergingLayer); // adding the merging layer
```

Executing the EdgeSOM (distributed clustering) by calling the ``run()`` function in the layers manager
```cpp
// runs the simulated architicure and returns the final clusters
vector<vector<double>> clusters = layersManager.run(data);
```

When EdgeSOM is executed, the following steps will take place:
1. The first server layer will receive the dataset file and partition it among the servers. For example, if the number of servers is set to 2 (by invoking ``.setServers(2)``) then the dataset will be partitioned into 2 batches.
2. If there are any other servers layers, they will be executed in the same order they were added.
3. After all servers layers are executed, the merging layer will be executed, and the final results will be sent back to the user.
4. Note that the output of each layer will be sent to the next layer and partitioned in each layer accordingly.
