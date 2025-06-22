class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ans(n, vector<int>(n, INT_MAX));
        queue<pair<pair<int, int>, int>> pq;

        if (grid[0][0] == 0){
            pq.push({{0, 0}, 1});
            ans[0][0] = 1;
        }

        while (!pq.empty()){
            
            pair<pair<int, int>, int> top = pq.front();
            int x = top.first.first, y = top.first.second, distance = top.second;

            pq.pop();

            vector<pair<int, int>> neighbors = {{x-1, y}, {x+1, y}, {x, y-1}, {x, y+1}, {x-1,y-1}, {x+1,y-1}, {x-1,y+1}, {x+1,y+1}};
            for (auto neighbor : neighbors){
                int newX = neighbor.first, newY = neighbor.second;
                if (newX>=0 && newX<n && newY>=0 && newY<n && grid[newX][newY]==0 && distance+1<ans[newX][newY]){
                    pq.push({{newX, newY}, distance+1});
                    ans[newX][newY] = min(ans[newX][newY], distance+1);
                    if (newX==n-1 && newY==n-1){
                        return ans[newX][newY];
                    }
                }
            }
        }

        return ans[n-1][n-1]==INT_MAX ? -1 : ans[n-1][n-1];
    }
};