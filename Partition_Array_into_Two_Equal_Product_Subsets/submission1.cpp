class Solution {
public:
    bool solve(vector<int> &nums, long long ans1, long long ans2, int n, long long target){
        if (ans1>target || ans2>target){
            return false;  
        } else if (n==-1){
            return ans1==ans2 && ans1==target;
        } else {
            return solve(nums, 1LL*nums[n]*ans1, ans2, n-1, target) || solve(nums, ans1, 1LL*nums[n]*ans2, n-1, target);
        }
    }
    
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        long long ans1 = 1, ans2 = 1;
        int n = nums.size();
        return solve(nums, ans1, ans2, n-1, target);
    }
};