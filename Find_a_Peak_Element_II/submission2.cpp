class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int x = 0, y = 0;
        for (int i=0; i<m; i++){
            vector<pair<int, int>> temp(n);
            for (int j=0; j<n; j++){
                temp[j] = {mat[i][j], j};
            }

            sort(temp.begin(), temp.end());
            
            if (temp[n-1].first > mat[x][y]){
                x = i;
                y = temp[n-1].second;
            }
        }

        vector<int> ans = {x, y};
        return ans;
    }
};