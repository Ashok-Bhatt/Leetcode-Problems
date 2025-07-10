class Solution {
public:
    bool solve(vector<int> &nums, vector<vector<int>> &dp, int n, int sum){
        if (sum < 0){
            return false;
        } else if (n==-1){
            return sum==0;
        } else if (dp[n][sum] != -1){
            return dp[n][sum];
        } else {
            return dp[n][sum] = solve(nums, dp, n-1, sum) || solve(nums, dp, n-1, sum-nums[n]);
        }
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        for (int i=0; i<n; i++){
            sum = sum + nums[i];
        }

        if (sum & 1){
            return false; 
        }

        vector<vector<int>> dp(n, vector<int>(sum/2+1, -1));
        return solve(nums, dp, n-1, sum/2);
    }
};