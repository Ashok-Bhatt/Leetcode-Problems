class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size(), ans = 0, i = 0, j = 0, buffer = 1;

        while (j<n){
            
            while (j<n && (nums[j] == 1 || buffer)){
                if (nums[j] == 0){
                    buffer = 0;
                }
                j++;
            }

            ans = max(ans, j-i-1);

            while (i<j && !buffer){
                if (nums[i] == 0){
                    buffer = 1;
                }
                i++;
            }
        }

        return ans;
    }
};