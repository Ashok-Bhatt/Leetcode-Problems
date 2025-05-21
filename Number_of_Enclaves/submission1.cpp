class Solution {
private:
    int solve(vector<vector<int>>& grid, vector<vector<bool>> &visited, int i, int j, int m, int n){

        visited[i][j] = true;
        vector<pair<int, int>> neighbors = {{i-1, j}, {i+1, j}, {i, j-1}, {i, j+1}};

        int ans = 1;
        for (auto neighbour : neighbors){
            int newX = neighbour.first, newY = neighbour.second;
            if (newX>=0 && newX<m && newY>=0 && newY<n && grid[newX][newY] && !visited[newX][newY]){
                ans = ans + solve(grid, visited, newX, newY, m, n);
            }
        }

        return ans;
    }

public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int walkable = 0, totalLand = 0;

        // Moving in the first and last row
        for (int i=0; i<n; i++){
            if (grid[0][i] && !visited[0][i]){
                walkable = walkable + solve(grid, visited, 0, i, m, n);
            }

            if (grid[m-1][i] && !visited[m-1][i]){
                walkable = walkable + solve(grid, visited, m-1, i, m, n);
            }
        }

        // Moving int first and last columns
        for (int i=0; i<m; i++){
            if (grid[i][0] && !visited[i][0]){
                walkable = walkable + solve(grid, visited, i, 0, m, n);
            }

            if (grid[i][n-1] && !visited[i][n-1]){
                walkable = walkable + solve(grid, visited, i, n-1, m, n);
            }
        }

        // Counting total ones
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (grid[i][j]){
                    totalLand++;
                }
            }
        }

        return totalLand - walkable;
    }
};