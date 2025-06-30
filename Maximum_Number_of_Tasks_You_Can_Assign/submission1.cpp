class Solution {
public:
    bool isFeasibleSolution(vector<int>& tasks, vector<int>& workers, int pills, int strength, int mid){

        multiset<int> sortedWorkers(workers.begin(), workers.begin()+mid);

        for (int i=mid-1; i>=0; i--){
            auto it = prev(sortedWorkers.end());

            if (*it >= tasks[i]){
                sortedWorkers.erase(it);
            } else if (pills <= 0){
                return false;
            } else{
                auto lowestFeasibleWorker = sortedWorkers.lower_bound(tasks[i]-strength);
                if (lowestFeasibleWorker == sortedWorkers.end()){
                    return false;
                } else {
                    sortedWorkers.erase(lowestFeasibleWorker);
                    pills--;
                }
            }
        }

        return true;
    }

    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int n = tasks.size(), m = workers.size(), s = 0, e = n, mid, ans = 0;

        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end(), greater<int>());

        while (s<=e){
            mid = s + (e-s)/2;
            if (mid<=m && isFeasibleSolution(tasks, workers, pills, strength, mid)){
                ans = mid;
                s = mid+1;
            } else {
                e = mid-1;
            }
        }

        return ans;
    }
};