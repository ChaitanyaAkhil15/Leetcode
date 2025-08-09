// problem link : https://www.geeksforgeeks.org/problems/prerequisite-tasks/1

// TC & SC similar to that of topological sort using BFS
// Intuition -> the tasks have to be completed in an order as there is dependency.
// If topological sorting gives us an ordering for all the tasks then it means there is no cyclic dependency
// And all tasks can be finished
class Solution {
  public:
    bool isPossible(int N, int P, vector<pair<int, int> >& prerequisites) {
        vector<int> topo;
        queue<int> q;
        vector<int> indegree(N, 0);
        vector<vector<int>> adjList(N);
        
        for(auto edge : prerequisites) {
            adjList[edge.first].push_back(edge.second);    
        }
        
        for(auto edge : prerequisites) {
            indegree[edge.second]++;
        }
        
        for(int v = 0; v < N; v++) {
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
        
        return topo.size() == N;
        
    }
};