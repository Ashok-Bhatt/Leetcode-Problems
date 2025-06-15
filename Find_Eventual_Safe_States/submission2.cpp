class Solution {
public:
    bool solve(int node, vector<bool> &visited, vector<bool> &pathVisited, vector<bool> &isCycle, vector<vector<int>> &graph){

        visited[node] = true;
        pathVisited[node] = true;

        for (auto neighbour : graph[node]){
            if (pathVisited[neighbour]){
                return true;
            } else if (!visited[neighbour] && solve(neighbour, visited, pathVisited, isCycle, graph)) {
                return true;
            }
        }

        pathVisited[node] = false;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<bool> visited(n, false), pathVisited(n, false), isCycle(n, false);
        vector<int> ans;

        for (int i=0; i<n; i++){
            if (!visited[i]){
                solve(i, visited, pathVisited, isCycle, graph);
            }
        }

        for (int i=0; i<n; i++){
            if (!pathVisited[i]){
                ans.push_back(i);
            }
        }

        return ans;
    }
};