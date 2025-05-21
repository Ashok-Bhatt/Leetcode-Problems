class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), sum = 0, ans = 0;
        unordered_map<int, int> map;
        for (int i=0; i<n; i++){
            sum = sum + nums[i]%2;
            if (sum == k){
                ans++;
            }
            ans = ans + map[sum-k];
            map[sum]++;
        }

        return ans;
    }
};