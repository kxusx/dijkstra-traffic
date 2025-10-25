#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<int>> edges = {{1,11,1}, {1,2,1},{2,3,1},{3,4,1},{5,6,2},{6,7,1},{7,8,1},{8,9,1},{9,19,1},{19,18,2},{18,10,2},{18,17,2},{17,11,1},{11,12,2},{12,13,2},{13,14,2}, {13,21,1},{21,20,2}, {14,15,1}, {20,22,1},{21,22,2}, {5,22,1}, {14,16,1}, {17,16,2} };

    unordered_map<int, vector<pair<int, int>>> graph;
    for (const auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w); 
    }

    int src=1;
}

unordered_map<int, int> dijkstra(int src, unordered_map<int, vector<pair<int, int>>>& graph) {
    unordered_map<int, int> dist;
    for (auto& node : graph) dist[node.first] = INT_MAX;
    dist[src] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d != dist[u]) continue;

        for (auto& [v, w] : graph[u]) {
            if (d + w < dist[v]) {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }

  return dist;
}