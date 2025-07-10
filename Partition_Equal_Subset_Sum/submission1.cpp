class Solution {
public:
    int getSum(vector<int> &nums, int n){
        int ans = 0;
        for (int i=0; i<n; i++){
            ans = ans + nums[i];
        }
        return ans;
    }

    bool solve(vector<int> &nums, vector<vector<int>> &dp, int index, int currentSum, int totalSum){
        if (index==-1){
            return currentSum==0;
        } else if (dp[index][currentSum+totalSum] != -1){
            return dp[index][currentSum+totalSum]==0 ? false : true;
        } else {
            bool ans = solve(nums, dp, index-1, currentSum-nums[index], totalSum) || solve(nums, dp, index-1, currentSum+nums[index], totalSum);
            dp[index][currentSum+totalSum] = (ans) ? 1 : 0;
            return ans;
        }
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size(), sum = getSum(nums, n);
        vector<vector<int>> dp(n, vector<int>(2*sum+1, -1));
        return solve(nums, dp, n-1, 0, sum);
    }
};