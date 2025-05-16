class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int i=0, j=0;
        int current = nums[j];
        int length = nums.size();

        int ans = 0;

        while (j<length){
            while (j<length && nums[j]==current){
                j++;
            }

            nums[i] = nums[j-1];
            ans++;
            i++;
            if (j<length){
                current = nums[j];
            }
        }

        return ans;
    }
};