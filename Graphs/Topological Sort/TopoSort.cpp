// problem link : https://www.geeksforgeeks.org/problems/topological-sort/1

// DFS Approach
// TC : O(V + E)
// SC : O(V + E) as we are building the adjacency list
/*
The intuition is that as we have to find a linear ordering where u has to come before v we know that when we use dfs
we get to the last possible node and while tracing back(backtracking) we can store those nodes, this way the nodes at the end will be at the bottom of the stack
And the hierachy is maintained
*/
class Solution {
  public:
    void dfs(int v, vector<vector<int>>& adjList, vector<int>& visited, stack<int>& st) {
        visited[v] = 1;
        
        for(int neighbour : adjList[v]) {
            if(!visited[neighbour])
                dfs(neighbour, adjList, visited, st);
        }
        
        st.push(v);
    }
    
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(V);
        vector<int> topo;
        vector<int> visited(V, 0);
        stack<int> st;
        
        for(auto edge : edges) {
            adjList[edge[0]].push_back(edge[1]);    
        }
        
        for(int v = 0; v < V; v++) {
            if(!visited[v])
                dfs(v, adjList, visited, st);
        }
        
        while(!st.empty()) {
            topo.push_back(st.top());
            st.pop();
        }
        
        return topo;
    }
};

// BFS Approach
class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
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
        
        return topo;
        
    }
};

// Explanation of BFS Approach
/*
This is a brilliant question that gets to the heart of how different algorithms can solve the same problem using completely different approaches. Let me walk you through how this BFS-based method, known as Kahn's algorithm, produces a topological ordering through a fundamentally different but equally valid strategy.

**The Core Insight: Starting with Independence**

While your DFS approach worked backwards from dependencies, this BFS approach works forwards from independence. The key insight is this: in any directed acyclic graph, there must be at least one vertex with no incoming edges - think of it as a starting point that doesn't depend on anything else.

Consider a university course prerequisite system. Some courses like "Introduction to Programming" have no prerequisites - they're your starting points. Other courses like "Advanced Algorithms" might require several prerequisites to be completed first.

**Understanding Indegree as Dependency Count**

The `indegree` array is tracking something crucial - for each vertex, how many dependencies does it currently have? When you calculate `indegree[edge[1]]++` for each edge, you're essentially asking: "How many things must happen before this vertex can be processed?"

This is like counting how many prerequisites each course has. A course with indegree 0 has no remaining prerequisites and can be taken immediately.

**The Algorithm's Logic: Removing Dependencies Step by Step**

Here's where the magic happens. The algorithm follows this reasoning:

1. **Start with the independent vertices**: Find all vertices with indegree 0 (no dependencies) and add them to your queue. These are safe to process because nothing needs to happen before them.

2. **Process and remove dependencies**: When you process a vertex (add it to your result), you're saying "this task is now complete." For every neighbor of this vertex, you decrease their indegree by 1, effectively saying "you now have one fewer dependency to worry about."

3. **Create new independence**: If any neighbor's indegree becomes 0 after this reduction, it means all its dependencies have been satisfied, so it can now be processed safely.

**A Concrete Example**

Let's trace through a simple example to see this in action. Imagine we have vertices A, B, C, D with edges: A→B, A→C, B→D, C→D.

Initially:
- A: indegree 0 (no dependencies)
- B: indegree 1 (depends on A)
- C: indegree 1 (depends on A) 
- D: indegree 2 (depends on B and C)

Step 1: Queue starts with [A] (only vertex with indegree 0)
- Process A, add to result: [A]
- Reduce indegree of A's neighbors: B becomes 0, C becomes 0
- Queue becomes [B, C]

Step 2: Process B, result: [A, B]
- Reduce indegree of B's neighbors: D becomes 1
- Queue becomes [C]

Step 3: Process C, result: [A, B, C]
- Reduce indegree of C's neighbors: D becomes 0
- Queue becomes [D]

Step 4: Process D, result: [A, B, C, D]

**Why This Guarantees a Valid Topological Order**

The beautiful property of this approach is that you never add a vertex to your result until all its dependencies have been satisfied. By the time a vertex reaches indegree 0, you're guaranteed that every vertex it depends on has already been processed and appears earlier in your result.

Think of it like a domino effect in reverse - instead of knocking things down, you're building things up, but only when their foundation is solid.

**Comparing to Your DFS Approach**

Your DFS approach was like working backwards from a goal - you'd explore as deep as possible and only mark something as "finished" when you'd handled everything it depended on. This BFS approach works forwards from the foundation - you only process something when everything it needs has been completed.

Both approaches are correct, but they represent different ways of thinking about dependencies:
- DFS: "Don't finish until everything you depend on is finished"
- BFS: "Only start when everything you need is ready"

Can you see how both philosophies lead to the same valid ordering? What questions do you have about how the indegree counting ensures we never violate the dependency constraints?
*/