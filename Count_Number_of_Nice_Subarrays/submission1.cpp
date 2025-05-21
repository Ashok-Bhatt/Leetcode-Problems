class Solution {
private:
    int solve(vector<int> &nums, int n, int k){
        if (k < 0) return 0;

        int i = 0, j = 0, ans = 0, sum = 0;
        while (j<n){

            sum = sum + nums[j]%2;

            if (sum<=k){
                ans = ans + j - i + 1;
            }

            while (i<=j && sum>k){
                sum = sum - nums[i]%2;
                i++;
                if (sum<=k){
                    ans = ans + j - i + 1;
                }
            }

            j++;
        }

        return ans;
    }

public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        cout << solve(nums, n, k) << " " << solve(nums, n, k-1) << endl;
        return solve(nums, n, k) - solve(nums, n, k-1);
    }
};