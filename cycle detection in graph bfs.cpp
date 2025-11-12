#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;

// Problem
// You are given an *undirected* graph and *disconnected* graph G(V,E) having V vertices numbered from 0 to V-1 and E edges. Your task is
// to print its bfs traversal startingn from the 0th vertex. 
// In a *sorted* way he he

  void prepareAdjList(unordered_map<int, list<int>> &adjList, vector<pair<int, int>> edges) {
    for (int i = 0; i < edges.size(); i++) {
       int u = edges[i].first;
       int v = edges[i].second;
       adjList[u].push_back(v);
       adjList[v].push_back(u);
    }

  }


bool bfs(unordered_map<int, list<int>> &adjList, unordered_map<int, bool> &visited, unordered_map<int, int> &parent, int node) {
    queue<int> q;
    q.push(node);
    visited[node] = true;

    while (!q.empty()) {
        int frontNode = q.front();
        q.pop();; 

        for (auto adjNode: adjList[frontNode]) { 
            if (!visited[adjNode]) {
                q.push(adjNode);
                visited[adjNode] = true;
                parent[adjNode] = frontNode;
            } else if (parent[adjNode] != frontNode) {
                return true;
            }
        }
    }

    return false;
}


bool cycleDetect(int vertex, vector<pair<int, int>> &edges) {
    // Make an adjacency list first (now this is a task please make a function of this man (ok bro))
    unordered_map<int, list<int>> adjList;
    bool ans;
    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;
    

    prepareAdjList(adjList, edges);

    // traverse all components of a graph
    for (int i = 0; i < vertex; i++) {
        if (!visited[i]) {
            parent[i] = -1;
            ans = bfs(adjList, visited, parent, i);
        }
    }

    return ans;
    
}

// Time complexity -> o(v+E)
int main() {
    vector<pair<int, int>> vp = {{0,1}, {0,3}, {1,3}};
    bool ans = cycleDetect(4, vp);

   cout << ans;
    cout << endl;
    return 0;
}