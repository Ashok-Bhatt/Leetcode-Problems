class Solution {
public:
    int findLower(vector<int> nums, int target){
        
        int s=0, e=nums.size()-1, mid;
        int ans = -1;

        while (s<=e){
            mid = s+(e-s)/2;
            if (nums[mid]==target){
                ans = mid;
                e = mid-1;
            }
            else if (nums[mid]>target){
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }

        return ans;
    }

    int findUpper(vector<int> nums, int target){
        
        int s=0, e=nums.size()-1, mid;
        int ans = -1;

        while (s<=e){
            mid = s+(e-s)/2;
            if (nums[mid]==target){
                ans = mid;
                s = mid+1;
            }
            else if (nums[mid]>target){
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }

        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        
        vector<int> ans(2);
        ans[0] = findLower(nums, target);
        ans[1] = findUpper(nums, target);
        return ans;
    }
};