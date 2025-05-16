class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        long long ans = 0;
        priority_queue<pair<int, int>> pq;
        int n = grid.size(), m = grid[0].size();

        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                pq.push({grid[i][j], i});
            }
        }

        while (!pq.empty() && k){
            pair<int, int> top = pq.top();
            pq.pop();
            int value = top.first, row = top.second;
            if (limits[row] > 0){
                limits[row]--;
                ans = ans + value;
                k--;
            }
        }

        return ans;
    }
};