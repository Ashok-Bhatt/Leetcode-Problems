class cmp{
    public:
    bool operator()(pair<int, long long> &x, pair<int, long long> &y){
        return x.second > y.second;
    }
};

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        
        int e = roads.size();
        vector<pair<long long, long long>> ans(n, {(long long)(1e18), 1});
        priority_queue<pair<int, long long>, vector<pair<int, long long>>, cmp> pq;
        vector<vector<pair<int, int>>> adjList(n);

        for (int i=0; i<e; i++){
            int u = roads[i][0], v = roads[i][1];
            long long w = roads[i][2];
            adjList[u].push_back({v, w});
            adjList[v].push_back({u, w});
        }

        ans[0] = {0, 1};
        pq.push({0, 0});

        while (!pq.empty()){

            pair<int, long long> top = pq.top();
            int node = top.first;
            long long distance = top.second;

            pq.pop();

            for (auto it : adjList[node]){
                
                int nextNode = it.first;
                long long nextCost = it.second;

                if (distance + nextCost < ans[nextNode].first){
                    ans[nextNode] = {distance + nextCost, ans[node].second}; 
                    pq.push({nextNode, distance + nextCost});
                } else if (distance + nextCost == ans[nextNode].first){
                    ans[nextNode].second = (ans[nextNode].second + ans[node].second) % int(1e9+7);
                }
            }
        }

        return ans[n-1].second;
    }
};