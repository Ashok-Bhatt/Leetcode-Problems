class Solution {
public:
    long long minCost(int m, int n, vector<vector<int>>& waitCost) {
        vector<vector<long long>> dp(m , vector<long long>(n, 1));

        // First row
        for (int i=1; i<n; i++){
            dp[0][i] = dp[0][i-1] + (i+1);
            if (m!=1 || i!=n-1) dp[0][i] = dp[0][i] + waitCost[0][i]; 
        }

        // First column
        for (int i=1; i<m; i++){
            dp[i][0] = dp[i-1][0] + (i+1);
            if (n!=1 || i!=m-1) dp[i][0] = dp[i][0] + waitCost[i][0]; 
        }

        for (int i=1; i<m; i++){
            for (int j=1; j<n; j++){
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + (i+1)*(j+1);
                if (i!=m-1 || j!=n-1) dp[i][j] = dp[i][j] + waitCost[i][j];
            }
        }

        // for (int i=0; i<m; i++){
        //     for (int j=0; j<n; j++){
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        return dp[m-1][n-1];
    }
};