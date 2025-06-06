class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size(), s = 0, e = n-1, mid;
        while (s<e){
            mid = s + (e-s)/2;
            if (nums[mid] > nums[e]){
                s = mid + 1;
            } else {
                e = mid;
            }
        }

        return nums[s];
    }
};