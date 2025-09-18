#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dijkstra(int V, vector<vector<pair<int,int>>> &adj, int src) {
        // V = number of vertices
        // adj = adjacency list (node -> {neighbor, weight})
        // src = source node

        vector<int> dist(V, INT_MAX); // distance array
        dist[src] = 0;

        // Min-heap: {distance, node}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, src});

        while(!pq.empty()){
            int d = pq.top().first;   // current distance
            int u = pq.top().second;  // current node
            pq.pop();

            // If this distance is already larger than known, skip
            if(d > dist[u]) continue;

            // Explore neighbors
            for(auto &edge : adj[u]){
                int v = edge.first;   // neighbor
                int w = edge.second;  // weight

                if(dist[u] + w < dist[v]){
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist;
    }
};

int main() {
    int V = 5; // number of vertices (0 to 4)
    vector<vector<pair<int,int>>> adj(V);

    // Example graph:
    // 0--4--1
    // 0--2--2
    // 1--5--2
    // 1--10-3
    // 2--3--3

    adj[0].push_back({1, 4});
    adj[0].push_back({2, 2});
    adj[1].push_back({0, 4});
    adj[1].push_back({2, 5});
    adj[1].push_back({3, 10});
    adj[2].push_back({0, 2});
    adj[2].push_back({1, 5});
    adj[2].push_back({3, 3});
    adj[3].push_back({1, 10});
    adj[3].push_back({2, 3});

    Solution obj;
    vector<int> dist = obj.dijkstra(V, adj, 0); // source = 0

    cout << "Shortest distances from source 0:" << endl;
    for(int i=0; i<V; i++){
        cout << "Node " << i << " -> " << dist[i] << endl;
    }

    return 0;
}
