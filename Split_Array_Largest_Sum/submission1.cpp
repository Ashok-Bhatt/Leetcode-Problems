class Solution {
public:
    bool isFeasibleSolution(vector<int> &nums, int n, int k, int mid){

        int subArrayNo = 1, currentSum = 0;
        for (int i=0; i<n; i++){
            if (nums[i] > mid){
                return false;
            } else if (nums[i]+currentSum > mid){
                currentSum = nums[i];
                subArrayNo++;
            } else {
                currentSum = currentSum + nums[i];
            }
        }

        return subArrayNo <= k;
    }

    int getSum(vector<int> &nums, int n){
        int ans = 0;
        for (int i=0; i<n; i++){
            ans = ans + nums[i];
        }
        return ans;
    }

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size(), sum = getSum(nums, n);
        int s = 0, e = sum, mid, ans = -1;

        while (s<=e){
            mid = s + (e-s)/2;

            if (isFeasibleSolution(nums, n, k, mid)){
                ans = mid;
                e = mid-1;
            } else {
                s = mid+1;
            }
        }

        return ans;
    }
};