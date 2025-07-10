class Solution {
public:
    double solve(vector<int> &nums1, vector<int> &nums2, int n, int m, int index){
        
        int s = 0, e = n-1, mid, ans = INT_MAX;
        if (m==0) return nums1[index];

        while (s<=e){
            mid = s + (e-s)/2;
            auto lb = lower_bound(nums2.begin(), nums2.end(), nums1[mid]+1);
            int smallerElements = (lb==nums2.end()) ? m : distance(nums2.begin(), lb);
            if (smallerElements+mid==index){
                ans = nums1[mid];
                break;
            } else if (smallerElements+mid>index){
                if (index-mid>=0){
                    ans = nums2[index-mid];
                }
                e = mid-1;
            } else {
                s = mid+1;
            }
        }

        return (ans==INT_MAX) ? nums2[0] : ans;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();

        if (n>=m){
            if ((n+m)%2==0){
                return (solve(nums1, nums2, n, m, (n+m)/2-1) + solve(nums1, nums2, n, m, (n+m)/2) ) / 2;
            }else{
                return solve(nums1, nums2, n, m, (n+m)/2);
            }
        } else {
            if ((n+m)%2==0){
                return (solve(nums2, nums1, m, n, (n+m)/2-1) + solve(nums2, nums1, m, n, (n+m)/2) ) / 2;
            }else{
                return solve(nums2, nums1, m, n, (n+m)/2);
            }
        }
    }
};