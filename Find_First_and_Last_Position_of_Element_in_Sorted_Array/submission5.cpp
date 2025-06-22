class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        vector<int> ans(2,-1);
        int i=0, j=nums.size()-1, mid;

        // Empty array
        if (j==-1){
            return ans;
        }

        // Finding left occurance
        while (i<j){
            mid = i+(j-i)/2;
            if (nums[mid]>=target){
                j = mid;
            }
            else{
                i = mid+1;
            }
        }

        if (nums[i]!=target){
            return ans;
        }

        // Finding right Occurance if left one exists
        ans[0] = i;
        j = nums.size()-1;

        while (i<=j){
            mid = i+(j-i)/2;
            if (nums[mid]<=target){
                i = mid+1;
            }
            else{
                j = mid-1;
            }
        }
        ans[1] = j;

        return ans;
    }
};