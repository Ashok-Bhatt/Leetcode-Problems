class Solution {
public:
    int findLowerBound(vector<int> &nums, int target, int n){
        int s = 0, e = n-1, mid;
        while (s<=e){
            mid = s + (e-s)/2;
            if (nums[mid] >= target){
                e = mid-1;
            } else {
                s = mid+1;
            }
        }
        return s;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        
        int n = nums.size();
        vector<int> ans = {-1, -1};

        if (n==0) return ans;

        int first = findLowerBound(nums, target, n), last = findLowerBound(nums, target+1, n);

        if (first<n && nums[first] == target){
            ans[0] = first;
            ans[1] = last-1;
        }

        return ans;
    }
};