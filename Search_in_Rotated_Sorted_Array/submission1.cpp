class Solution {
public:
    int findPivot(vector<int> &nums, int n){
        int s = 0, e = n-1, mid;
        while (s<e){
            mid = s + (e-s)/2;
            if (nums[mid]>nums[e]){
                s = mid+1;
            } else {
                e = mid;
            }
        }

        return s;
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size(), s = 0, e = n-1, mid;
        int pivot = findPivot(nums, n);

        while (s<=e){
            mid = s + (e-s)/2;
            if (nums[mid] == target){
                return mid;
            } else if (pivot<=mid){
                if (target < nums[mid] || target>nums[n-1]){
                    e = mid-1;
                } else {
                    s = mid+1;
                }
            } else {
                if  (target < nums[0] || target>nums[mid]){
                    s = mid + 1;
                } else {
                    e = mid - 1;
                }
            }
        }

        return -1;
    }
};