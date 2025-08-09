// problem link : https://www.geeksforgeeks.org/problems/course-schedule/1

// TC & SC same as that of topological sort using BFS
// Intuition -> same as PrerequisiteTasks problem, but the dependency is different (0, 1) 1 has to be finished before 0 : 1 -> 0
// We return any possible ordering at the end
class Solution {
  public:
    vector<int> findOrder(int n, vector<vector<int>> prerequisites) {
        vector<int> topo;
        queue<int> q;
        vector<int> indegree(n, 0);
        vector<vector<int>> adjList(n);
        
        for(auto edge : prerequisites) {
            adjList[edge[1]].push_back(edge[0]);    
        }
        
        for(auto edge : prerequisites) {
            indegree[edge[0]]++;
        }
        
        for(int v = 0; v < n; v++) {
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