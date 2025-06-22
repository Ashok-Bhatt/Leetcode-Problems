class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        int e = times.size(), networkDelay = 0;
        vector<vector<pair<int, int>>> adjList(n);
        vector<int> ans(n, INT_MAX);
        priority_queue<pair<int, int>> pq;

        for (int i=0; i<e; i++){
            int u = times[i][0]-1, v = times[i][1]-1, w = times[i][2];
            adjList[u].push_back({v, w});
        }

        ans[k-1] = 0;
        pq.push({k-1, 0});

        while (!pq.empty()){

            pair<int, int> top = pq.top();
            int node = top.first, distance = top.second;

            pq.pop();

            for (auto it : adjList[node]){
                int nextNode = it.first, nextCost = it.second;

                if (distance + nextCost < ans[nextNode]){
                    int nextDistance = distance + nextCost;
                    ans[nextNode] = nextDistance;
                    pq.push({nextNode, nextDistance});
                }
            }
        }

        for (int i=0; i<n; i++){
            if (ans[i] == INT_MAX){
                networkDelay = -1;
                break;
            } else {
                networkDelay = max(networkDelay, ans[i]);
            }
        }

        return networkDelay;
    }
};