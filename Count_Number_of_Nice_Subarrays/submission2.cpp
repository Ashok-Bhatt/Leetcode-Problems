class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), i = 0, j = 0, ans = 0, sum = 0, currentSum = 0;
        unordered_map<int, int> occurrence;

        for (int i=0; i<n; i++){
            sum = sum + nums[i]%2;
            occurrence[sum] = i;
        }

        sum = 0;

        while (j < n){

            currentSum = currentSum + nums[j]%2;
            sum = sum + nums[j]%2;
            j++;

            if (currentSum == k){
                ans = ans + occurrence[sum] - j + 2;
                while (i<j && currentSum == k){
                    currentSum = currentSum - nums[i]%2;
                    i++;
                    if (i!=j && currentSum==k){
                        ans = ans + occurrence[sum] - j + 2;
                    }
                }
            } else if (currentSum > k) {
                currentSum = currentSum - nums[i]%2;
                i++;
            }
        }

        return ans;
    }
};