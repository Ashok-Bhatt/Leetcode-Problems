class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size(), ans = 0, temp = 0;
        vector<int> gaps(n+1);

        gaps[0] = startTime[0];
        for (int i=0; i<n; i++){
            if (i==n-1) gaps[i+1] = eventTime-endTime[n-1];
            else gaps[i+1] = startTime[i+1]-endTime[i];
        }

        for (int i=0; i<=k; i++){
            temp = temp + gaps[i];
            ans = ans + gaps[i];
        }

        for (int i=k+1; i<=n; i++){
            temp = temp + gaps[i] - gaps[i-k-1];
            ans = max(ans, temp);
        }

        return ans;
    }
};