class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int index = 0, n = nums.size(), count = 0;
        for (int i=0; i<n && index<n; i++){
            int temp = nums[index];
            swap(nums[i], nums[index]);
            count++;
            index++;

            while (index<n && temp == nums[index]){
                index++;
            }
        }

        return count;
    }
};