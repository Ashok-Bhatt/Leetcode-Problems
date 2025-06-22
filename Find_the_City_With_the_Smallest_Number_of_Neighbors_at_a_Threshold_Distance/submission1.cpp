class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        int e = edges.size(), ans = INT_MAX, ansIndex = 0;
        vector<vector<pair<int, int>>> adjList(n);

        for (int i=0; i<e; i++){
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            adjList[u].push_back({v, w});
            adjList[v].push_back({u, w});
        }

        for (int i=0; i<n; i++){
            
            vector<int> dist(n, INT_MAX);
            priority_queue<pair<int, int>> pq;
            int count = 0;

            dist[i] = 0;
            pq.push({0, i});

            while (!pq.empty()){
                pair<int, int> top = pq.top();
                int distance = top.first, node = top.second;
                pq.pop();

                for (auto it : adjList[node]){
                    int nextDistance = distance + it.second, nextNode = it.first;
                    if (nextDistance < dist[nextNode]){
                        pq.push({nextDistance, nextNode});
                        dist[nextNode] = nextDistance;
                    }
                }
            }

            for (int j=0; j<n; j++){
                if (dist[j] <= distanceThreshold){
                    count++;
                }
            }

            if (count <= ans){
                ans = count;
                ansIndex = i;
            }
        }

        return ansIndex;
    }
};