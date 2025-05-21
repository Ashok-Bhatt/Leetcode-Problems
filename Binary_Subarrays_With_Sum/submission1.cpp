class Solution {
public:
    int solve(vector<int> &nums, int n, int goal){

        if (goal < 0) return 0;

        int i = 0, j = 0, ans = 0, sum = 0;
        while (j<n){
            sum = sum + nums[j];

            if (sum <= goal){
                ans = ans + j - i + 1;
            }

            while (i<=j && sum > goal){
                sum = sum - nums[i];
                i++;
                if (sum <= goal){
                    ans = ans + j - i + 1;
                }
            }

            j++;

        }

        return ans;

    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        return solve(nums, n, goal) - solve(nums, n, goal-1);
    }
};