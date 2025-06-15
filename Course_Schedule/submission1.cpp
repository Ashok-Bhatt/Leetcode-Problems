class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        int e = prerequisites.size(), count = 0;
        vector<vector<int>> adjList(numCourses);
        queue<int> q;
        vector<int> inDegree(numCourses, 0);

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
            count++;

            for (auto it : adjList[front]){
                inDegree[it]--;
                if (!inDegree[it]){
                    q.push(it);
                }
            }
        }

        return count==numCourses;
    }
};