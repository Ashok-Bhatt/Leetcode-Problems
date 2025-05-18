class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        for (int i=0; i<n; i++){
            int sum = 0, x = nums[i];
            while (x){
                sum = sum + x%10;
                x = x / 10;
            }

            if (sum == i){
                return i;
            }
        }

        return -1;
    }
};