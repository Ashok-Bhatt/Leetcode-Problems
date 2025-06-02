class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();
        queue<pair<int, int>> q;
        unordered_set<int> s1, s2;
        vector<bool> visited(n, false);

        for (int i=0; i<n; i++){
            
            if (!visited[i]){
                q.push({i, 0});
                visited[i] = true;
            }

            while (!q.empty()){

                pair<int, int> front = q.front();
                int node = front.first, setNo = front.second;
                
                if (setNo == 0){
                    s1.insert(node);
                } else {
                    s2.insert(node);
                }

                q.pop();

                for (int neighbor : graph[node]){
                    if (!visited[neighbor]){
                        q.push({neighbor, (setNo+1)%2});
                        visited[neighbor] = true;
                    }
                }
            }
        }

        for (int i=0; i<n; i++){
            for (int j : graph[i]){
                if ((s1.find(i)!=s1.end() && s1.find(j)!=s1.end()) || (s2.find(i)!=s2.end() && s2.find(j)!=s2.end())){
                    return false;
                }
            }
        }

        return true;
}
};