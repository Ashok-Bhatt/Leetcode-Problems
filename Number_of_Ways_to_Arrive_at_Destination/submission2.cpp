class cmp{
public:
    bool operator()(pair<int, long long> &a, pair<int, long long> &b){
        return a.second > b.second;
    }
};

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        
        int totalRoads = roads.size();
        vector<vector<pair<int, long long>>> adjList(n);
        priority_queue<pair<int, long long>, vector<pair<int, long long>>, cmp> pq;
        vector<pair<long long, int>> shortest(n, {(long long)(1e18), 0});

        shortest[0] = {0, 1};

        for (int i=0; i<totalRoads; i++){
            int u = roads[i][0], v = roads[i][1];
            long long w = roads[i][2];
            adjList[u].push_back({v, w});
            adjList[v].push_back({u, w});
        }

        for (int i=0; i<adjList[0].size(); i++){
            pair<int, long long> element = adjList[0][i];
            int next = element.first;
            long long weight = element.second;
            pq.push(element);
            shortest[next] = {weight, 1};
        }

        while (!pq.empty()){
            pair<int, long long> top = pq.top();
            pq.pop();
            int current = top.first;
            long long weight = top.second;
            
            for (int i=0; i<adjList[current].size(); i++){
                pair<int, long long> element = adjList[current][i];
                int next = element.first;
                long long nextWeight = weight + element.second;
                if (nextWeight < shortest[next].first){
                    shortest[next] = {nextWeight, shortest[current].second};
                    pq.push({next, nextWeight});
                } else if (nextWeight == shortest[next].first) {
                    shortest[next].second = (shortest[next].second + shortest[current].second) % int(1e9+7);
                }
            }
        }

        return shortest[n-1].second;
    }
};