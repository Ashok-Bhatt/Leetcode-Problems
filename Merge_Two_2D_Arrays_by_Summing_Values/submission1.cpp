class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int n =nums1.size(), m = nums2.size(), i = 0, j = 0;
        vector<vector<int>> ans;

        while (i<n || j<m){
            if (i<n && j<m){
                if (nums1[i][0] == nums2[j][0]){
                    ans.push_back({nums1[i][0], nums1[i][1] + nums2[j][1]});
                    i++;
                    j++;
                } else if (nums1[i][0] < nums2[j][0]){
                    ans.push_back(nums1[i]);
                    i++;
                } else {
                    ans.push_back(nums2[j]);
                    j++;
                }
            } else if (i < n){
                ans.push_back(nums1[i]);
                i++;
            } else {
                ans.push_back(nums2[j]);
                j++;
            }
        }

        return ans;
    }
};