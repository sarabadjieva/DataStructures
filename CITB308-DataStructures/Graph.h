#pragma once
#include <vector>
#include <list>
#include <queue>
#include <iostream>
#define INF 0x3f3f3f3f

class Graph
{
private:
	typedef std::pair<int, int> iPair;
	const static int MAX = 10;
	//adjacency matrix
	// if the graph has weight -> change 1 to the corresponding weight
	// with undirected -> we assign 1 to both
	// with directed -> we assign 1 to a[i][j] if there is a edge from vertex i to j
	//  0 1 2 3
	//0 0 1 1 1 
	//1 1 0 0 0
	//2 1 0 0 0
	//3 1 0 0 0

	int adjMatr[MAX][MAX];


	/*
	graph[][] = { {0,   5,  INF, 10},
                {INF,  0,  3,  INF},
                {INF, INF, 0,   1},
                {INF, INF, INF, 0} }
	which represents the following graph
             10
      (0)——->(3)
       |     /|\
     5 |      |  1
       |      |  
      \|/     |
      (1)——->(2)
              3 */


	//adjacency list
	int V; //No. of vertices
	std::vector<std::list<int> > adjList;
	std::list<iPair>* adjWeightsList;
	std::vector<int> dfs_visited;

	//incidence matrix

	//incidence list

public:
	Graph(int V);
	void addEdge(int u, int v);
	void addEdge(int u, int v, int weight);
	void BFS(int init);
	void DFS(int init);

	//for weighted graph
	void dijkstra(int); //page 311 //page 221
	
	//for edge-weighted directed graph
	//from vertex to vertex
	void floyd(); //page 356
};

