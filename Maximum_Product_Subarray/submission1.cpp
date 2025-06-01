class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(), lastNegativeIndex = -1;
        long long product = 1, ans = nums[0], lastNegativeValue = -1;

        for (int i=0; i<n; i++){

            // Resetting variables as to get max subarray no subarray should consist of 0
            if (nums[i] == 0){
                ans = max(ans, 1LL*0);   // Covering the case in which array contains alternate sequence of zeros and negative numbers
                product = 1;
                lastNegativeIndex = lastNegativeValue = -1;
            } else {
                product = product * nums[i];
                if (product < 0){
                    if (lastNegativeIndex == -1){
                        lastNegativeIndex = i;
                        lastNegativeValue = product;
                        ans = max(ans, product);
                    } else {
                        ans = max(ans, product/lastNegativeValue);
                    }
                } else {
                    ans = max(ans, product);
                }
            }
        }

        return ans;
    }
};