class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b){
        return a[0] < b[0];
    }

    int maxEvents(vector<vector<int>>& events) {
        int n = events.size(), index = 0, start = 1, ans = 0;
        priority_queue<int, vector<int>, greater<int>> pq;

        sort(events.begin(), events.end(), cmp);

        while (!pq.empty() || index<n){
            if (index<events.size()){

                if (pq.empty()) start = max(start, events[index][0]);
                while (index<n && events[index][0]==start){
                    pq.push(events[index][1]);
                    index++;
                }
            }

            while (!pq.empty() && pq.top() < start){
                pq.pop();
            }

            if (!pq.empty()){
                ans++;
                pq.pop();
            }

            start++;
        }

        return ans;
    }
};