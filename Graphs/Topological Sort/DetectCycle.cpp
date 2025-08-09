// problem link : https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

/*
You've hit on exactly the right insight! The connection between topological sorting and cycle detection is one of those beautiful "aha!" moments in graph algorithms. Let me walk you through why this works so elegantly.

## The Core Insight

You're absolutely correct: if we cannot form a complete linear ordering of all vertices using topological sort, then the graph must contain a cycle. This happens because topological sorting fundamentally relies on the absence of cycles to work properly.

Think about what a cycle means in a directed graph. If we have vertices A → B → C → A, then A must come before B, B must come before C, but C must also come before A. This creates an impossible contradiction when trying to arrange them in a line—there's no way to satisfy all these ordering constraints simultaneously.

## How Kahn's Algorithm Reveals Cycles

Your BFS-based topological sort (known as Kahn's algorithm) works by repeatedly removing vertices that have no incoming edges. Here's the key insight: in a directed acyclic graph (DAG), there will always be at least one vertex with no incoming edges at any point during this process, until all vertices are processed.

However, when a cycle exists, eventually you'll reach a state where all remaining unprocessed vertices have at least one incoming edge from other unprocessed vertices. At this point, your algorithm gets "stuck"—the queue becomes empty even though vertices remain unprocessed.

## Walking Through Your Code

Let me trace through how your algorithm would detect a cycle:

```cpp
// After processing all possible vertices without cycles
while(!q.empty()) {  // This loop will terminate early if there's a cycle
    int node = q.front();
    q.pop();
    topo.push_back(node);  // Add to our ordering
    
    for(int neighbour : adjList[node]) {
        indegree[neighbour]--;  // "Remove" the edge
        
        if(indegree[neighbour] == 0)
            q.push(neighbour);  // Only add if no more dependencies
    }
}
// If topo.size() < V, we have a cycle!
```

The detection happens after this loop completes. If `topo.size() < V`, it means some vertices were never added to the topological ordering because they remained trapped in cycles.

## A Concrete Example

Consider this cyclic graph:
- Vertex 0 → Vertex 1
- Vertex 1 → Vertex 2  
- Vertex 2 → Vertex 0
- Vertex 3 → Vertex 1

Initially, only vertex 3 has indegree 0, so it gets processed first. After removing vertex 3 and its edge to vertex 1, we have:
- Vertex 0: indegree 1 (from vertex 2)
- Vertex 1: indegree 1 (from vertex 0)  
- Vertex 2: indegree 1 (from vertex 1)

Now the queue is empty, but vertices 0, 1, and 2 remain unprocessed. They're stuck in a cycle where each depends on another in the cycle being processed first.

## The Mathematical Foundation

This works because of a fundamental property: every DAG has at least one vertex with indegree 0 (a source) and at least one vertex with outdegree 0 (a sink). When you remove a source vertex and its outgoing edges, the resulting graph is still a DAG with the same property.

In contrast, in any strongly connected component of a cycle, every vertex has indegree ≥ 1 relative to other vertices in that component, creating the "deadlock" situation your algorithm detects.

## Making It Complete for Cycle Detection

To explicitly use this for cycle detection, you'd simply add:

```cpp
if(topo.size() != V) {
    // Graph contains a cycle
    return {}; // or throw an exception, or return a flag
}
return topo;
```

This approach is particularly elegant because it gives you two things at once: either a valid topological ordering (proving the graph is acyclic) or definitive proof that cycles exist. The algorithm naturally "fails gracefully" in the presence of cycles, making the detection almost a byproduct of the sorting attempt.

Does this help clarify why the connection between topological sorting and cycle detection is so natural? The key insight is that cycles create contradictions in ordering requirements that topological sort inherently cannot resolve.
*/

// TC : O(V + E)
// SC : O(V + E)
class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<int> topo;
        queue<int> q;
        vector<int> indegree(V, 0);
        vector<vector<int>> adjList(V);
        
        for(auto edge : edges) {
            adjList[edge[0]].push_back(edge[1]);    
        }
        
        for(auto edge : edges) {
            indegree[edge[1]]++; // edge[1] has an incoming edge from edge[0]
        }
        
        for(int v = 0; v < V; v++) {
            if(indegree[v] == 0)
                q.push(v);
        }
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            
            for(int neighbour : adjList[node]) {
                indegree[neighbour]--;
                
                if(indegree[neighbour] == 0)
                    q.push(neighbour);
            }
        }
        
        return (topo.size() != V);
    }
};
