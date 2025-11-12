#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
using namespace std;


// Given an undirected and disconnected graph G(V,E), contain v vertices and e edges, the information about edges  is given using
// graph matrix  where ith edge is between graph[i][0]  and graph[i][1]. print its dfs traversal.

void dfs(int node,  unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adjList, vector<int> &component) {
    component.push_back(node);
    visited[node] = true;

    // hr connected node k liye recursive call
    for (auto i: adjList[node]) {
        if (!visited[i]) {
            dfs(i, visited, adjList, component);

        }

    }

}

void DFS(int V, int E, vector<vector<int>> &edges, vector<vector<int>> &ans) {
    // prepare adjacency list
    unordered_map<int, list<int>> adjList;

    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);

    }

    
    unordered_map<int, bool> visited;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            vector<int> component;
            dfs(i, visited, adjList, component);
            ans.push_back(component);
        }

    }

    
}


int main() {
    cout << "hello bello";

    vector<vector<int>> ans;
    vector<vector<int>> edges = {{0,2}, {0,1}, {1,2}, {3,4}};
    cout << "finally kuch aaya";

    DFS(5, 4, edges, ans);

    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    cout << "kuch to aye he he";

    return 0;
}