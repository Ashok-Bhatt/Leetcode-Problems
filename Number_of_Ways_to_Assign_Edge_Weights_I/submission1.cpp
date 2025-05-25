class Solution {
public:
    long long solve(vector<vector<int>> &dp, int n, int currentSum){
        if (n==0){
            return currentSum;
        } else if (dp[n][currentSum] != -1){
            return dp[n][currentSum];
        } else {
            int oneWay = solve(dp, n-1, (currentSum+1)%2);
            int twoWay = solve(dp, n-1, currentSum);
            return dp[n][currentSum] = (oneWay + twoWay) % int(1e9+7);
        }
    }
    
    pair<int, int> solve(vector<vector<int>> &adjList, vector<int> &path, int currentNode, int parent){

        if (adjList[currentNode].size() == 0){
            return {currentNode, 0};
        }

        int maxDepth = 0, maxDepthNode = 0;
        for (auto child : adjList[currentNode]){
            if (child != parent){
                pair<int, int> temp = solve(adjList, path, child, currentNode);
                if (temp.second+1 > maxDepth){
                    maxDepth = temp.second+1;
                    maxDepthNode = temp.first;
                    path[currentNode] = child;
                }
            }
        }

        return {maxDepthNode, maxDepth};
    }
    
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int e = edges.size();
        vector<vector<int>> adjList(e+1);
        vector<int> path(e+1);

        for (int i=0; i<e; i++){
            int u = edges[i][0]-1, v = edges[i][1]-1;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        pair<int, int> temp = solve(adjList, path, 0, -1);
        int maxDepthNode = temp.first;
        int maxDepth = temp.second;

        vector<vector<int>> dp(maxDepth, vector<int>(2, -1));
        return (solve(dp, maxDepth-1, 1) + solve(dp, maxDepth-1, 0))%int(1e9 + 7);
    }
};