class Solution {
public:
    int getMaxPossibleGap(int block, int index1, int index2, vector<pair<int, int>> &gaps, priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq, int n){
        int ans = 0;
        while (!pq.empty()){
            pair<int, int> top = pq.top();
            int value = top.first, index = top.second;
            pq.pop();
            if (index!=index1 && index!=index2 && value>=block){
                ans = max(ans, block);
            }
        }
        return ans;
    }

    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size(), ans = 0;
        vector<pair<int, int>> gaps(n+1, {startTime[0], 0});
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (int i=0; i<n; i++){
            if (i==n-1){
                gaps[i+1] = {eventTime - endTime[i], i+1};
            } else {
                gaps[i+1] = {startTime[i+1] - endTime[i], i+1};
            }
        }

        for (int i=0; i<=n; i++){
            if (pq.size() < 3){
                pq.push(gaps[i]);
            } else if (pq.top().first < gaps[i].first){
                pq.pop();
                pq.push(gaps[i]);
            }
        }

        for (int i=0; i<n; i++){
            int temp = gaps[i].first + gaps[i+1].first + getMaxPossibleGap(endTime[i]-startTime[i], gaps[i].second, gaps[i+1].second, gaps, pq, n);
            ans = max(ans, temp);
        }

        return ans;
    }
};