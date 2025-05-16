class Solution {
private:
    int getSum(vector<int> &nums, int n){
        int sum = 0;
        for (int i=0; i<n; i++){
            sum = sum + nums[i];
        }
        return sum;
    }

    bool solve(vector<int> &nums, vector<vector<int>> &dp, int index, int current, int bias){
        if (index < 0){
            return current==0;
        } else if (dp[index][current+bias] != -1){
            return dp[index][current+bias]==0 ? false : true;
        } else {
            bool first = solve(nums, dp, index-1, current+nums[index], bias);
            bool second = solve(nums, dp, index-1, current-nums[index], bias);
            dp[index][current+bias] = (first || second) ? 1 : 0;
            return first || second;
        }
    }

public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), sum = getSum(nums, n), current = 0;
        vector<vector<int>> dp(n, vector<int>(2*sum+1, -1));
        return solve(nums, dp, n-1, current, sum);
    }
};