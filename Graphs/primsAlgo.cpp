#include <iostream>
#include <vector>
#define INF 1000000000 // Representing infinity for non-connected edges

using namespace std;

int graph[][5] = {
    {0, 2, INF, 6, INF},
    {2, 0, 3, 8, 5},
    {INF, 3, 0, INF, 7},
    {6, 8, INF, 0, 9},
    {INF, 5, 7, 9, 0}
};


int near[5] = {INF, INF, INF, INF, INF};
int t[2][4];



// Function to implement Prim's algorithm
void primsAlgorithm(int n) {
    int k, u, v, min = INF;

    // Find the first minimum edge
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (graph[i][j] < min && graph[i][j] != 0) {
                min = graph[i][j];
                u = i;
                v = j;
            }
        }
    }

    // Initialize the minimum spanning tree with the first edge
    t[0][0] = u;
    t[1][0] = v;
    near[u] = near[v] = 0;

    // Update the near array
    for (int i = 0; i < n; i++) {
        if (near[i] != 0) {
            near[i] = (graph[i][u] < graph[i][v]) ? u : v;
        }
    }

    // Find the remaining edges of the minimum spanning tree
    for (int i = 1; i < n - 1; i++) {
        min = INF;

        for (int j = 0; j < n; j++) {
            if (near[j] != 0 && graph[j][near[j]] < min) {
                k = j;
                min = graph[j][near[j]];
            }
        }

        // Add the selected edge to the spanning tree
        t[0][i] = k;
        t[1][i] = near[k];
        near[k] = 0;

        // Update the near array again
        for (int j = 0; j < n; j++) {
            if (near[j] != 0 && graph[j][k] < graph[j][near[j]]) {
                near[j] = k;
            }
        }
    }

    // Display the resulting edges of the minimum spanning tree
    cout << "Edges of the Minimum Spanning Tree:" << endl;
    for (int i = 0; i < n - 1; i++) {
        cout << "(" << t[0][i] << ", " << t[1][i] << ")" << "\n";
    }
}



int main() {
    cout << "Graph (Adjacency Matrix):" << endl;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (graph[i][j] == INF)
                cout << "INF ";
            else
                cout << graph[i][j] << " ";
        }
        cout << endl;
    }

    // Call the Prim's algorithm function
    primsAlgorithm(5);

    return 0;
}
