class Solution {
public:
    pair<int, long long> solve(int node, vector<int>& cost, vector<vector<int>> &adjList, vector<int> &visited, int n){

        unordered_map<long long, int> occurrence;
        long long sum = cost[node], maxi = 0;
        int totalOccurrence = 0, buffer = 0;

        for (int it : adjList[node]){
            if (!visited[it]){
                visited[it] = true;
                pair<int, long long> temp = solve(it, cost, adjList, visited, n);
                occurrence[temp.second]++;
                buffer = buffer + temp.first;
                maxi = max(maxi, temp.second);
                totalOccurrence++;
            }
        }

        // cout << node << " " << totalOccurrence-occurrence[maxi] << " " << sum + maxi << endl;

        return {totalOccurrence-occurrence[maxi]+buffer, sum+maxi};
    }
    
    int minIncrease(int n, vector<vector<int>>& edges, vector<int>& cost) {
        int e = edges.size();
        vector<vector<int>> adjList(n);
        vector<int> visited(n, false);

        for (int i=0; i<e; i++){
            int u = edges[i][0], v = edges[i][1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        visited[0] = true;
        return solve(0, cost, adjList, visited, n).first;
    }
};