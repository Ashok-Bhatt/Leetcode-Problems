class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size(), i = 0, j = 0, ans = 0, sum = 0, currentSum = 0;
        unordered_map<int, int> lastOccurrence;

        for (int i=0; i<n; i++){
            sum = sum + nums[i];
            lastOccurrence[sum] = i;
        }

        sum = 0;

        while (j < n){
            currentSum = currentSum + nums[j];
            sum = sum + nums[j];
            j++;

            if (currentSum == goal){
                ans = ans + lastOccurrence[sum] - j + 2;
                while (currentSum == goal && i<j){
                    currentSum = currentSum - nums[i];
                    i++;
                    if (currentSum == goal && i!=j){
                        ans = ans + lastOccurrence[sum] - j + 2;
                    }
                }
            } else if (currentSum > goal){
                currentSum = currentSum - nums[i];
                i++;
            }
        }

        return ans;
    }
};