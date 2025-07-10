class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {
        int e = edges.size();
        vector<vector<pair<int, pair<int, int>>>> adjList(n);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> minDist(n, INT_MAX);

        for (int i=0; i<e; i++){
            int u = edges[i][0], v = edges[i][1], start = edges[i][2], end = edges[i][3];
            adjList[u].push_back({v, {start, end}});
        }

        minDist[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()){
            pair<int, int> top = pq.top();
            int distance = top.first, node = top.second;
            pq.pop();

            for (auto it : adjList[node]){
                int nextNode = it.first, start = it.second.first, end = it.second.second;
                if (distance<=end){
                    int nextDistance = max(distance+1, start+1);
                    if (nextDistance < minDist[nextNode]){
                        minDist[nextNode] = nextDistance;
                        pq.push({nextDistance, nextNode});
                    }
                }
            }
        }

        return minDist[n-1]==INT_MAX ? -1 : minDist[n-1];
    }
};