class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size(), i = 0, j = 0;
        while (true){
            vector<pair<int, int>> neighbors = {{i-1,j}, {i+1,j}, {i,j-1}, {i,j+1}};

            bool flag = true;
            for (auto it : neighbors){
                int newI = it.first, newJ = it.second;
                if (newI>=0 && newJ>=0 && newI<m && newJ<n && mat[newI][newJ] > mat[i][j]) flag = false;
            }

            if (flag){
                vector<int> ans = {i, j};
                return ans;
            }

            for (auto it : neighbors){
                int newI = it.first, newJ = it.second;
                if (newI>=0 && newJ>=0 && newI<m && newJ<n && mat[newI][newJ] > mat[i][j]){
                    i = newI;
                    j = newJ;
                }
            }
        }
    }
};