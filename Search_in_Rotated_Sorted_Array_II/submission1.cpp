class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size(), s = 0, e = n-1, mid;
        while (s<=e){
            mid = s + (e-s)/2;
            if (nums[mid] == target){
                return true;
            } else if (nums[s]==nums[mid] && nums[mid]==nums[e]){
                s++;
                e--;
            } else if (nums[s] <= nums[mid]){
                if (nums[s] <= target && target < nums[mid]){
                    e = mid-1;
                } else {
                    s = mid+1;
                }
            } else {
                if (nums[mid] < target && target <= nums[e]){
                    s = mid+1;
                } else {
                    e = mid-1;
                }
            }
        }
        return false;
    }
};