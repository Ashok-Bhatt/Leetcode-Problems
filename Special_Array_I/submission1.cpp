class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size();
        for (int i=0; i<=n-2; i++){
            if ((nums[i]+nums[i+1])%2==0) return false;
        }
        return true;
    }
};