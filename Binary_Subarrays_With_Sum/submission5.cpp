class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        int n = nums.size(), ans = 0, sum = 0;
        unordered_map<int,int> occurance;

        for (int i=0; i<n; i++){

            sum = sum + nums[i];

            if (sum==goal){
                ans++;
            }

            ans = ans + occurance[sum-goal];
            occurance[sum]++;
        }

        return ans;
    }
};