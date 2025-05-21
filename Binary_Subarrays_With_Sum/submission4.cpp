class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        unordered_map<int, int> occurrence;
        int n = nums.size(), count = 0, ans = 0;

        for (int i=0; i<n; i++){
            count = count + nums[i];
            if (count == goal) ans++;
            ans = ans + occurrence[count-goal];
            occurrence[count]++;
        }

        return ans;
    }
};