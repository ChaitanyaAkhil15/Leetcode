// problem link : https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/0

/*
Avoiding Undefined Behavior / Overflow:
If a node hasn't been reached (i.e., its distance is still INT_MAX), adding any edge weight to INT_MAX may result in an integer overflow or produce an incorrect value.

Ensuring Correct Relaxation:
Only nodes whose distances have been updated (meaning they are reachable from the source) should be used to relax and update neighboring nodes. If you try to relax using an unreachable node, the computed distances will be invalid.

Maintaining Algorithm Integrity:
This check ensures that the algorithm only extends proper paths from the source (node 0) following the topological order. Nodes that are unreachable should never affect the final computed path lengths.

Time Complexity
Graph Construction (Building the Adjacency List and Indegree Array):
Iterating through all edges takes O(E).

Topological Sorting:
Every vertex is processed once, and each edge is considered when reducing indegrees. This step takes O(V + E).

Relaxation of Nodes:
Each node in the topological order is processed, and its outgoing edges are relaxed once. This also takes O(V + E).

Final Conversion:
Converting any INT_MAX values to -1 for unreachable nodes takes O(V).

In summary, the overall time complexity is O(V + E).

Space Complexity
Adjacency List:
Requires O(V + E) space to store all vertices and edges.

Indegree Array:
O(V) space is used.

Distance Array:
O(V) space is used.

Additional Storage (Queue and TopoSort):
Combined, the queue and the topoSort vector use up to O(V) space.

Thus, the overall space complexity is O(V + E).
*/
class Solution {
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adjList(V);
        vector<int> indegree(V, 0);
        queue<int> q;
        vector<int> topoSort;
        
        // Build the graph and compute indegree for each vertex.
        for(auto edge : edges) {
            adjList[edge[0]].push_back({edge[1], edge[2]});
            indegree[edge[1]]++;
        }
        
        // Push nodes with indegree = 0 into the queue.
        for(int i = 0; i < V; i++) {
            if(indegree[i] == 0)
                q.push(i);
        }
        
        // Prepare the topological order.
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            topoSort.push_back(node);
            
            for(auto neighbour : adjList[node]) {
                indegree[neighbour.first]--;
                if(indegree[neighbour.first] == 0)
                    q.push(neighbour.first);
            }
        }
        
        // Initialize distances with "infinity" and distance to source = 0.
        vector<int> distance(V, INT_MAX);
        distance[0] = 0;
        
        // Relax edges in topological order.
        for(int i = 0; i < V; i++) {
            int node = topoSort[i];
            if(distance[node] != INT_MAX) { // Only relax if the current node is reachable.
                for(auto neighbour : adjList[node]) {
                    distance[neighbour.first] = min(distance[neighbour.first], distance[node] + neighbour.second);
                }
            }
        }
        
        // Convert unreachable vertices distance value from INT_MAX to -1.
        for(int i = 0; i < V; i++) {
            if(distance[i] == INT_MAX)
                distance[i] = -1;
        }
        
        return distance;
    }
};