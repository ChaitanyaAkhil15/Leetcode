// problem link : https://www.geeksforgeeks.org/problems/number-of-distinct-islands/1

/*Time Complexity: O(n×m×log(k))
Grid traversal: O(n×m) - we potentially visit each cell once
BFS: Each cell is visited at most once, with constant work per cell
Set operations: Each island's path is inserted into the set, which costs O(P×log(k)) where:
P is the path length (could be up to n×m in worst case)
k is the number of distinct islands (at most n×m)
Combined, this gives us O(n×m×log(k)) where k ≤ n×m.

Space Complexity: O(n×m)
Visited array: O(n×m) space
Queue for BFS: O(min(n,m)) in worst case
Path vector: O(n×m) in worst case for a single island
Set of islands: O(k×p) where k is number of distinct islands and p is average path length
The dominant factor is O(n×m), though in worst case (where every island has a unique shape and we store all coordinates), 
it could approach O((n×m)²).
Why this could happen:
Set storage: Your solution stores each island's shape as a vector of coordinate pairs in a set:

Worst case scenario:

Each island could contain up to O(n×m) cells (in extreme cases)
You could have up to O(n×m) distinct islands
Each island's path vector stores relative coordinates for every cell
Total space calculation:

Number of islands: O(n×m) in worst case
Size of each island's path vector: O(n×m) in worst case
Total: O(n×m) × O(n×m) = O((n×m)²)
*/
class Solution {
  private:
    void bfs(int src_row, int src_col, vector<vector<int>>& grid,
            vector<vector<int>>& visited, vector<pair<int, int>>& path) {
            int n = grid.size(), m = grid[0].size();
            queue<pair<int, int>> q;
            q.push({src_row, src_col});
            visited[src_row][src_col] = 1;
            path.push_back({0, 0});
            
            while(!q.empty()) {
                auto node = q.front();
                q.pop();
                
                int row = node.first;
                int col = node.second;
                int dir_rows[] = {-1, 0, 1, 0};
                int dir_cols[] = {0, 1, 0, -1};
                
                for(int dir = 0; dir < 4; dir++) {
                    int newRow = dir_rows[dir] + row;
                    int newCol = dir_cols[dir] + col;
                    
                    if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
                        grid[newRow][newCol] == 1 && !visited[newRow][newCol]) {
                        q.push({newRow, newCol});
                        visited[newRow][newCol] = 1;
                        path.push_back({newRow - src_row, newCol - src_col});
                    }
                }
            }
    }
    
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        set<vector<pair<int, int>>> islands;
        for(int row = 0; row < n; row++) {
            for(int col = 0; col < m; col++) {
                vector<pair<int, int>> path;
                if(grid[row][col] == 1 && !visited[row][col]) {
                    bfs(row, col, grid, visited, path);
                    islands.insert(path);
                }
            }
        }
        
        return islands.size();
    }
};
