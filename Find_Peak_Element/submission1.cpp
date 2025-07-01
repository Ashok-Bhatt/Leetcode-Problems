class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size(), s = 0, e = n-1, mid;
        if (n==1) return 0;
        while (s<=e){
            mid = s + (e-s)/2;
            if (mid==0){
                if (nums[mid] > nums[mid+1]) return mid;
                else s = mid+1;
            } else if (mid==n-1){
                if (nums[mid] > nums[mid-1]) return mid;
                else e = mid-1;
            } else {
                if (nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]) return mid;
                else if (nums[mid-1]>nums[mid]) e = mid-1;
                else s = mid+1; 
            }
        }
        return 0;
    }
};