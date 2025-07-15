class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        
        int m = meetings.size(), ans = 0;
        priority_queue< pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>> > pq;
        vector<int> count(n, 0);

        sort(meetings.begin(), meetings.end());

        for (int i=0; i<n; i++){
            pq.push({0, i});
        }

        for (int i=0; i<m; i++){
            int start = meetings[i][0], end = meetings[i][1], gap = end - start;

            while (pq.top().first<start){
                pair<long long, int> top = pq.top();
                pq.pop();
                pq.push({start, top.second});
            }
            
            pair<long long, int> top = pq.top();
            long long topEnd = top.first;
            int topBoxNo = top.second;
            pq.pop();
            pq.push({max((long long)start, topEnd) + gap, topBoxNo});
            count[topBoxNo]++;
        }

        for (int i=0; i<n; i++){
            if (count[i] > count[ans]){
                ans = i;
            }
        }

        return ans;
    }
};