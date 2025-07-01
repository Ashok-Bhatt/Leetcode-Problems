class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size(), s = 0, e = n-1, mid;
        while (s<=e){
            cout << s <<  " " << e << endl;
            mid = s + (e-s)/2;
            if ((mid+1>=n || nums[mid]>nums[mid+1]) && (mid-1<0 || nums[mid]>nums[mid-1])){
                return mid;
            } else if (mid+1<n && nums[mid]<nums[mid+1]){
                s = mid+1;
            } else {
                e = mid-1;
            }
        }

        return -1;
    }
};