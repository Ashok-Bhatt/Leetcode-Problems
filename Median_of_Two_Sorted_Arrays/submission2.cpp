class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int i=0, j=0;
        vector<int> nums;

        while (i<m || j<n){
            if (i<m && j<n){
                if (nums1[i] < nums2[j]){
                    nums.push_back(nums1[i]);
                    i++;
                } else {
                    nums.push_back(nums2[j]);
                    j++;
                }
            } else if (i<m){
                nums.push_back(nums1[i]);
                i++;
            } else {
                nums.push_back(nums2[j]);
                j++;
            }
        }

        if ((m+n)%2){
            return 1.0*nums[(m+n)/2];
        } else {
            return 1.0*(nums[(m+n)/2]+nums[(m+n)/2-1])/2;
        }
    }
};