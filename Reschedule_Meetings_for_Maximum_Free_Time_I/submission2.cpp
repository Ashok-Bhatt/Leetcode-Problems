class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {

        vector<int> gap;
        int n = startTime.size(), ans = 0, sum = 0;

        // Setting the gap vector
        gap.push_back(startTime[0]);
        for (int i=0; i<n-1; i++){
            gap.push_back(startTime[i+1]-endTime[i]);
        }
        gap.push_back(eventTime-endTime[n-1]);

        // Creating first window
        for (int i=0; i<k+1; i++){
            sum = sum + gap[i];
        }
        ans = sum;

        // Processing remaining windows
        int i = 0, j = k;
        while (j < n){
            sum = sum - gap[i++];
            sum = sum + gap[++j];
            ans = max(ans, sum);
        }

        return ans;
        
    }
};