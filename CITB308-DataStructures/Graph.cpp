#include "Graph.h"

Graph::Graph(int V) {
	this->V = V;
	adjList.resize(V);
	adjWeightsList = new std::list<iPair>[V];
	dfs_visited.resize(V, false);

	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			adjMatr[i][j] = INF;
		}
		adjMatr[i][i] = 0;
	}
}

void Graph::addEdge(int u, int v) {
	adjList[u].push_back(v);
	//adjList[v].push_back(u); //undirected
}

void Graph::addEdge(int u, int v, int weight) {
	adjWeightsList[u].push_back(std::make_pair(v, weight));
	adjWeightsList[v].push_back(std::make_pair(u, weight)); //undirected

	adjMatr[u][v] = weight;
	adjMatr[v][u] = weight;
}

void Graph::BFS(int init) {
	std::queue<int> q;
	std::vector<bool> visited;
	visited.resize(V, false);

	visited[init] = true;
	q.push(init);

	while (!q.empty()) {
		init = q.front();
		std::cout << init << " ";
		q.pop();

		for (auto adj : adjList[init]) {
			if (!visited[adj]) {
				visited[adj] = true;
				q.push(adj);
			}
		}
	}

	//int visited[MAX];
	//int visit[MAX];
	//int initialVertex = 0;

	//visited[initialVertex] = 1;

	//for (int i = 1; i < MAX; i++)
	//{
	//	for (int j = 0; j <= MAX; j++)
	//	{
	//		if (adjMatr[initialVertex][j] != 0 && visited[j] != 1 && visit[j] != 1)
	//		{
	//			visit[j] = 1;

	//		}
	//	}
	//}
}


void Graph::DFS(int init) {
	dfs_visited[init] = true;
	std::cout << init << " ";

	std::list<int>::iterator it;
	for (it = adjList[init].begin(); it != adjList[init].end(); ++it) {
		if (!dfs_visited[*it])
			DFS(*it);
	}
}

void Graph::dijkstra(int init) {
	std::priority_queue<iPair, std::vector<iPair>, std::greater<iPair> > pq;
	std::vector<int> dist(V, INF);

	pq.push(std::make_pair(0, init));
	dist[init] = 0;

	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop();

		std::list<iPair>::iterator it;
		for (it = adjWeightsList[u].begin(); it != adjWeightsList[u].end(); ++it) {
			int v = (*it).first;
			int weight = (*it).second;

			if (dist[v] > dist[u] + weight) {
				dist[v] = dist[u] + weight;
				pq.push(std::make_pair(dist[v], v));
			}
		}
	}

	// Print shortest distances stored in dist[]
	printf("Vertex Distance from Source\n");
	for (int i = 0; i < V; ++i)
		printf("%d \t\t %d\n", i, dist[i]);

	/*int r = init, n = V;
	int v, w, min, i, j;
	for (i = 1; i <= n; i++) { U[i] = 0; p[i] = r; dist[i] = INF; }
	dist[r] = p[r] = 0;
	for (i = 1; i <= n; i++) {
		v = 0; min = INF;
		for (j = 1; j <= n; j++) if (U[j] == 0 && dist[j] < min) { v = j; min = dist[j]; }
		U[v] = 1;
		for (j = 1; j <= G[v][0]; j++) {
			w = G[v][j];
			if (U[w] == 0 && dist[v] + c[v][w] < dist[w]) {
				dist[w] = dist[v] + c[v][w]; p[w] = v;
			}
		}
	}*/
}

void Graph::floyd() {
	int path[MAX][MAX];
	int matr[MAX][MAX];
	for (int k = 0; k < MAX; k++) {
		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < MAX; j++) {
				if (adjMatr[i][j] > (adjMatr[i][k] + adjMatr[k][j])) {
					adjMatr[i][j] = adjMatr[i][k] + adjMatr[k][j];
					path[i][j] = k;
				}
			}
		}
	}

	std::cout << "The following matrix shows the shortest "
		"distances"
		" between every pair of vertices \n";
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			if (adjMatr[i][j] == INF)
				std::cout << "INF"
				<< " ";
			else
				std::cout << adjMatr[i][j] << "   ";
		}
		std::cout << std::endl;
	}
}