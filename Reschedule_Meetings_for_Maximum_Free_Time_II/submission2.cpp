class Solution {
typedef pair<int, int> Pair;

public:
    vector<Pair> getMaxGaps(vector<int>& startTime, vector<int> &endTime, int n, int eventTime){

        priority_queue<Pair, vector<Pair>, greater<Pair>> mini;
        vector<Pair> maxgaps;

        for (int i=0; i<n; i++){
            if (mini.size() < 3){
                if (i==0){
                    mini.push({startTime[i], i});
                } else {
                    mini.push({startTime[i]-endTime[i-1], i});
                }
            } else {
                if (mini.top().first < startTime[i]-endTime[i-1]){
                    mini.pop();
                    mini.push({startTime[i]-endTime[i-1], i});
                }
            }
        }

        if (mini.size() < 3 || mini.top().first < eventTime-endTime[n-1]){
            mini.pop();
            mini.push({eventTime - endTime[n-1], n});
        }

        while (!mini.empty()){
            Pair top = mini.top();
            maxgaps.push_back(top);
            mini.pop();
        }

        return maxgaps;
    }

    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        
        int n = startTime.size(), ans = 0;
        vector<Pair> maxgaps = getMaxGaps(startTime, endTime, n, eventTime);

        for (int i=0; i<n; i++){
            int blockSize = endTime[i] - startTime[i];
            int gap1 = (i==0) ? startTime[i] : startTime[i]-endTime[i-1];
            int gap2 = (i==n-1) ? eventTime - endTime[i] : startTime[i+1]-endTime[i];
            for (int j=0; j<maxgaps.size(); j++){
                if (i==maxgaps[j].second || i+1==maxgaps[j].second){
                    ans = max(ans, gap1+gap2);
                } else {
                    if (blockSize <= maxgaps[j].first){
                        ans = max(ans, gap1+gap2+blockSize);
                    } else {
                        ans = max(ans, gap1+gap2);
                    }
                }
            }
        }

        return ans;
    }
};