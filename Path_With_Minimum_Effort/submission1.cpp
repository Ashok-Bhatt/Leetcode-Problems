class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> ans(n, vector<int>(m, INT_MAX));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        pq.push({0, {0, 0}});
        ans[0][0] = 0;

        while (!pq.empty()){

            pair<int, pair<int, int>> top = pq.top();
            int distance = top.first, x = top.second.first, y = top.second.second;
            
            pq.pop();

            vector<pair<int, int>> neighbors = {{x-1, y}, {x+1, y}, {x, y-1}, {x, y+1}};

            for (auto neighbor : neighbors){
                int newX = neighbor.first, newY = neighbor.second;
                if (newX>=0 && newY>=0 && newX<n && newY<m){
                    int minDistance = max(distance, abs(heights[x][y] - heights[newX][newY]));
                    if (minDistance  < ans[newX][newY]){
                        ans[newX][newY] = minDistance;
                        pq.push({ minDistance, {newX, newY}});
                    }
                }
            } 
        }

        return ans[n-1][m-1];
    }
};