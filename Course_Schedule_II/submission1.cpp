class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        int e = prerequisites.size();
        queue<int> q;
        vector<int> inDegree(numCourses, 0);
        vector<vector<int>> adjList(numCourses);
        vector<int> ans;

        for (int i=0; i<e; i++){
            int u = prerequisites[i][0], v = prerequisites[i][1];
            adjList[v].push_back(u);
            inDegree[u]++;
        }

        for (int i=0; i<numCourses; i++){
            if (inDegree[i] == 0){
                q.push(i);
            }
        }

        while (!q.empty()){
            int front = q.front();
            q.pop();
            ans.push_back(front);

            for (auto it : adjList[front]){
                inDegree[it]--;
                if (inDegree[it] == 0){
                    q.push(it);
                }
            }
        }

        if (ans.size() == numCourses){
            return ans;
        }

        return vector<int>(0);
    }
};