class Solution {
public:
    int findLowerBound(vector<int> nums, int n, int target){
        int s = 0, e = n-1;
        while (s<=e){
            int mid = s + (e-s)/2;
            if (nums[mid] >= target){
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }

        return s;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if (n==0) return {-1,-1};

        int x = findLowerBound(nums, n, target);
        if (x==n || nums[x]!=target){
            return {-1, -1};
        } else {
            int y = findLowerBound(nums, n, target+1);
            return {x, y-1};
        }
    }
};