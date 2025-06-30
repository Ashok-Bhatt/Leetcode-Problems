class Solution {
public:
    bool isFeasibleSolution(vector<int> &weights, int n, int days, int mid){
        int currentDay = 1, currentWeight = 0;
        for (int i=0; i<n; i++){
            if (weights[i] > mid){
                return false;
            } else if (currentWeight + weights[i] > mid){
                currentDay++;
                currentWeight = weights[i];
            } else {
                currentWeight = currentWeight + weights[i];
            }
        }
        return currentDay <= days;
    }

    int getSum(vector<int> &num, int n){
        int sum = 0;
        for (int i=0; i<n; i++){
            sum = sum + num[i];
        }
        return sum;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size(), s = 1, e = getSum(weights, n), mid, ans;
        while (s<=e){
            mid = s + (e-s)/2;
            if (isFeasibleSolution(weights, n, days, mid)){
                ans = mid;
                e = mid-1;
            } else {
                s = mid+1;
            }
        }
        return ans;
    }
};