class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size(), i = 0, j = 0;
        while (true){
            int left = (j-1>=0) ? mat[i][j-1] : -1;
            int right = (j+1<n) ? mat[i][j+1] : -1;
            int up = (i-1>=0) ? mat[i-1][j] : -1;
            int down = (i+1<m) ? mat[i+1][j] : -1;
            if (mat[i][j]>left && mat[i][j]>right && mat[i][j]>up && mat[i][j]>down){
                vector<int> ans = {i, j};
                return ans;
            } else {
                int newI = i, newJ = j;
                if (j-1>=0 && mat[i][j-1] > mat[newI][newJ]){
                    newI = i;
                    newJ = j-1;
                }
                if (j+1<n && mat[i][j+1] > mat[newI][newJ]){
                    newI = i;
                    newJ = j+1;
                }
                if (i-1>=0 && mat[i-1][j] > mat[newI][newJ]){
                    newI = i-1;
                    newJ = j;
                }
                if (i+1<m && mat[i+1][j] > mat[newI][newJ]){
                    newI = i+1;
                    newJ = j;
                }
                i = newI;
                j = newJ;
            }
        }
    }
};