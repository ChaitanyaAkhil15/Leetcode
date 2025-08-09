// https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

// TC : O(V + E)
// SC : O(V + E)
/*
Let me break down exactly what our algorithm does to show why V + E captures the true complexity. During initialization, we create and initialize the visited arrays, which takes O(V) time.
In the main loop, we iterate through all V vertices to ensure we handle disconnected components. For each unvisited vertex, we start a DFS.
During the DFS traversal, each edge gets examined exactly once when we iterate through a vertex's adjacency list. This gives us the E component. Each vertex gets visited at most once and marked in our arrays, contributing to the processing time.
The key insight is that these two types of work (vertex processing and edge examination) are independent. In some graphs, vertex work dominates; in others, edge work dominates. By writing O(V + E), we accurately capture both contributions.

The adjacency list construction requires O(V + E) space, plus the O(V) space for your algorithm-specific arrays and recursion stack, giving you O(V + E) + O(V) = O(V + E) total space.
*/
class Solution {
  public:
    
    bool hasCycle(vector<vector<int>>& adjList, int v, vector<int>& visited, vector<int>& visited_in_path) {
        visited[v] = 1;
        visited_in_path[v] = 1;
        
        for(int neighbour : adjList[v]) {
            if(visited_in_path[neighbour])
                return true;
            else if(!visited[neighbour] && hasCycle(adjList, neighbour, visited, visited_in_path) == true)
                return true;
        }
        
        visited_in_path[v] = 0;
        return false;
    }
    
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adjList(V);
        
        for(auto edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
        }
        
        vector<int> visited(V, 0);
        vector<int> visited_in_path(V, 0); 
        for(int v = 0; v < V; v++) {
            if(!visited[v] && hasCycle(adjList, v, visited, visited_in_path) == true)
                return true;
        }
        
        return false;
    }
};