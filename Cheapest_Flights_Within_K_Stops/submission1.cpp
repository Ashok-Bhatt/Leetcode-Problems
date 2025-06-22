class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        int e = flights.size();
        vector<vector<pair<int, int>>> adjList(n);
        vector<int> ans(n, INT_MAX);
        queue<pair<int, pair<int, int>>> pq;

        for (int i=0; i<e; i++){
            int u = flights[i][0], v = flights[i][1], w = flights[i][2];
            adjList[u].push_back({v, w});
        }

        ans[src] = 0;
        pq.push({src, {0, 0}});


        while (!pq.empty()){

            pair<int, pair<int, int>> top = pq.front();
            int node = top.first, stops = top.second.first, distance = top.second.second;

            pq.pop();

            if (stops <= k){
                for (auto it : adjList[node]){
                    int nextNode = it.first, nextDistance = it.second;

                    if (distance + nextDistance < ans[nextNode]){
                        ans[nextNode] = distance + nextDistance;
                        pq.push({nextNode, {stops+1, ans[nextNode]}});
                    }
                }
            }
        }

        return ans[dst] == INT_MAX ? -1 : ans[dst];
    }
};