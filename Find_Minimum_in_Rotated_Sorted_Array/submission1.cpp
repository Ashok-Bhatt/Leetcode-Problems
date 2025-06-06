class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int n = nums.size(), s = 0, e = n-1, mid, ans = -1;
        
        while (s<=e){
            mid = s + (e-s)/2;
            if ((mid==0 || nums[0]<=nums[mid-1]) && nums[mid]<=nums[n-1]){
                ans = nums[mid];
                e = mid-1;
            } else if (nums[mid]<=nums[n-1]){
                e = mid-1;
            } else {
                s = mid+1;
            }
        }

        return ans;
    }
};