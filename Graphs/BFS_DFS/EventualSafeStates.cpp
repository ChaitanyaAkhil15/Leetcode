// https://www.geeksforgeeks.org/problems/eventual-safe-states/1

// TC : O(V + E)
// SC : O(V)

/*
# Safe Nodes Algorithm - Quick Summary
Your solution uses DFS with three arrays: `visited` tracks explored nodes, `visited_in_path` detects cycles by tracking the current DFS path, and `is_safe` serves as permanent memory (-1 unknown, 0 unsafe, 1 safe).
The algorithm runs DFS only from unvisited nodes, and when it finds a cycle (neighbor already in current path), it marks that neighbor unsafe and propagates this up the recursion. After exploring all neighbors without finding cycles,
it marks the current node as safe during backtracking. This memoization approach transforms the problem from O(V × (V + E)) to optimal O(V + E) time complexity because each node's safety status is computed exactly once and reused, 
eliminating redundant explorations that would occur if you started fresh DFS from every single node.
*/
class Solution {
  public:
    bool dfs(int v, vector<int> adj[], vector<int>& visited, vector<int>& visited_in_path, vector<int>& is_safe) {
        visited[v] = 1;
        visited_in_path[v] = 1;
        
        for(int neighbour : adj[v]) {
            if(visited_in_path[neighbour]) {
                is_safe[neighbour] = 0;
                return true;
            }
            else if(!visited[neighbour] && dfs(neighbour, adj, visited, visited_in_path, is_safe) == true) {
                is_safe[neighbour] = 0;
                return true;
            }
        }
        
        visited_in_path[v] = 0;
        is_safe[v] = 1;
        return false;
    }
    
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int> safeNodes;
        vector<int> visited(V, 0);
        vector<int> visited_in_path(V, 0);
        vector<int> is_safe(V, -1);
        
        for(int v = 0; v < V; v++) {
            if(!visited[v])
                dfs(v, adj, visited, visited_in_path, is_safe);
        }
        
        for(int v = 0; v < V; v++) {
            if(is_safe[v] == 1)
                safeNodes.push_back(v);
        }
        
        return safeNodes;
    }
};
