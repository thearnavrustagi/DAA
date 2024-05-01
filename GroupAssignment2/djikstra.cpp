//
// Created by Dhruv on 30-04-2024.
//

#include <iostream>

using namespace std;

#define INF 0xffffffff // A large enough value to represent infinity

class Graph {
private:
    unsigned int numVertices;
    unsigned int **adjMatrix;

public:
    Graph(unsigned int n) {
        numVertices = n;
        adjMatrix = new unsigned int*[numVertices];
        for (int i = 0; i < numVertices; ++i) {
            adjMatrix[i] = new unsigned int[numVertices];
            for (int j = 0; j < numVertices; ++j) {
                adjMatrix[i][j] = INF; // Initialize all distances as infinity
            }
        }
    }

    ~Graph() {
        for (int i = 0; i < numVertices; ++i) {
            delete[] adjMatrix[i];
        }
        delete[] adjMatrix;
    }

    void addEdge(int u, int v, unsigned int weight) {
        adjMatrix[u][v] = weight;
        adjMatrix[v][u] = weight; // If the graph is undirected
    }

    void djikstra(int src) {
        unsigned int *dist = new unsigned int[numVertices]; // Array to store the shortest distances
	int **paths = new int*[numVertices];

	for (int i=0;i<numVertices;i++) {
		paths[i] = new int[numVertices];
	}

        bool *visited = new bool[numVertices]; // Array to track visited vertices

        for (int i = 0; i < numVertices; ++i) {
            dist[i] = INF; // Initialize all distances as infinity
            visited[i] = false; // Mark all vertices as unvisited
	    for (int j=1;j<numVertices;j++) paths[i][j] = -1;
	    paths[i][0] = src;
        }

        dist[src] = 0; // Distance from source to itself is 0

        for (int i = 0; i < numVertices - 1; ++i) {
            int minVertex = findMinVertex(dist, visited);
            visited[minVertex] = true; // Mark the minimum distance vertex as visited

            // Update distances to adjacent vertices of the minimum distance vertex
            for (int j = 0; j < numVertices; ++j) {
		// basically updating the distance to node j, based on the new most minimum node
                if (!visited[j] && adjMatrix[minVertex][j] != INF &&
                    dist[minVertex] != INF &&
                    dist[minVertex] + adjMatrix[minVertex][j] < dist[j]) {
			    dist[j] = dist[minVertex] + adjMatrix[minVertex][j];
			    // goes through the minVertex path and adds it
			    int k;
			    for (k=1;paths[minVertex][k] != -1;k++) {
				    paths[j][k] = paths[minVertex][k];
			    }
			    paths[j][k] = minVertex != src ? minVertex : -1;
                }
            }
        }

	for (int i=0; i<numVertices; ++i) {
		int j=0;
		for (;paths[i][j] > -1;j++);
		paths[i][j] = i;
	}
        cout << "Vertex Distance from Source" << endl;
        for (int i = 0; i < numVertices; ++i)
            cout << i << "\t\t" << dist[i] << endl;

	cout << "Vertex Paths from Source" << endl;
	for (int i=0; i<numVertices; ++i) {
		cout << "Path from Source to " << i << ": ";
		for (int j=0;j<numVertices && paths[i][j] > -1;++j) {
			cout << paths[i][j] << ' ';
		}
		cout << endl;
	}	

        delete[] dist;
	delete[] paths;
        delete[] visited;
    }

    int findMinVertex(unsigned int *dist, bool *visited) {
        int minVertex = -1;
        for (int i = 0; i < numVertices; ++i) {
            if (!visited[i] && (minVertex == -1 || dist[i] < dist[minVertex])) {
                minVertex = i;
            }
        }
        return minVertex;
    }
};

int main() {
    int n, m;
    cout << "Enter the number of vertices: ";
    cin >> n;
    Graph g(n);

    cout << "Enter the number of edges: ";
    cin >> m;

    cout << "Enter the edges (vertex1 vertex2 weight):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        g.addEdge(u, v, weight);
    }

    cout << "Enter the source vertex: ";
    int src;
    cin >> src;
    g.djikstra(src);

    return 0;
}
