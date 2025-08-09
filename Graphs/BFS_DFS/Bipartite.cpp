// problem link : https://www.geeksforgeeks.org/problems/bipartite-graph/1
// https://leetcode.com/problems/is-graph-bipartite/description/

/*
    Solution using BFS
    TC : O(V + 2E) → O(V + E)
    SC : O(V + E)
    Adjacency List: O(V + E)

    V lists containing a total of 2E elements (each edge appears twice)
    Queue for BFS: O(V)

    In worst case, could contain all vertices
    Visited Array: O(V)

    One entry per vertex
    Color Array: O(V)

    One entry per vertex
*/
class Solution {
  public:
    bool bfs(int src, vector<vector<int>>& adjList, vector<int>& visited, vector<int>& color) {
        queue<int> q;
        q.push(src);
        visited[src] = 1;
        color[src] = 0;
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            
            for(int neighbour : adjList[node]) {
                if(color[neighbour] == -1) {
                    q.push(neighbour);
                    visited[neighbour] = 1;
                    color[neighbour] = !color[node];
                }
                else if(color[neighbour] == color[node])
                    return false;
            }
        }
    }
    
    bool isBipartite(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adjList(V);
        
        for(auto edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        
        vector<int> color(V, -1);
        vector<int> visited(V, 0);
        
        for(int v = 0; v < V; v++) {
            if(!visited[v]){
                if(bfs(v, adjList, visited, color) == false)
                    return false;
            }
        }
        
        return true;
    }
};

/*

*/
class Solution {
  public:
    bool dfs(int src, vector<vector<int>>& adjList, vector<int>& visited, vector<int>& color) {
        visited[src] = 1;
        
        for(int neighbour : adjList[src]) {
            if(color[neighbour] == -1) {
                color[neighbour] = !color[src];
                if(dfs(neighbour, adjList, visited, color) == false)
                    return false;
            }
            else if(color[neighbour] == color[src])
                return false;
        }
           
        return true;
    }
    
    bool isBipartite(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adjList(V);
        
        for(auto edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        
        vector<int> color(V, -1);
        vector<int> visited(V, 0);
        
        for(int v = 0; v < V; v++) {
            if(!visited[v]){
                if(dfs(v, adjList, visited, color) == false)
                    return false;
            }
        }
        
        return true;
    }
};