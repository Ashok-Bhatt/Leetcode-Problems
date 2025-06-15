class Solution {
public:
    bool solve(int node, vector<vector<int>>& graph, vector<bool> &visited, unordered_set<int> &unique){

        if (unique.find(node) != unique.end()){
            return true;
        } else if (visited[node]) {
            return false;
        }

        visited[node] = true;

        bool ans = true;
        for (auto neighbour : graph[node]){
            if (!solve(neighbour, graph, visited, unique)){
                ans = false;
                break;
            } else {
                unique.insert(neighbour);
            }
        }

        visited[node] = false;
        return ans;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        unordered_set<int> unique;
        vector<int> ans;

        // Inserting each terminal node to unique
        for (int i=0; i<n; i++){
            if (graph[i].size() == 0){
                unique.insert(i);
            }
        }

        // Now inserting the remaining nodes to unique
        for (int i=0; i<n; i++){
            vector<bool> visited(n, false);
            if (solve(i, graph, visited, unique)){
                unique.insert(i);
            }
        }

        for (auto it : unique){
            ans.push_back(it);
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};