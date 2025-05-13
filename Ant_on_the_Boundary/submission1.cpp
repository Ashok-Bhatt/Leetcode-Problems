class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        
        int ans = 0, position = 0;
        
        for (int i=0; i<nums.size(); i++){
            position = position + nums[i];
            if (position==0){
                ans++;
            }
        }
        
        return ans;
    }
};