class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> inDegree(n, 0);
        vector<int> ans;
        queue<int> q;
        vector<vector<int>> adjList(n);

        for (int i=0; i<n; i++){
            for (auto it : graph[i]){
                inDegree[i]++;
                adjList[it].push_back(i);
            }
        }

        for (int i=0; i<n; i++){
            if (inDegree[i] == 0){
                q.push(i);
            }
        }

        while (!q.empty()){
            int front = q.front();
            ans.push_back(front);
            q.pop();

            for (auto it: adjList[front]){
                inDegree[it]--;
                if (inDegree[it] == 0){
                    q.push(it);
                }
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};