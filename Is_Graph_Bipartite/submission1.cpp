class Solution {
public:
    bool solve(vector<vector<int>>& graph, int node, vector<int> &color, int nodeColor){

        for (auto neighbour : graph[node]){
            if (color[neighbour] == nodeColor){
                return false;
            }
        }

        color[node] = nodeColor;

        for (auto neighbour : graph[node]){
            if (color[neighbour]==-1 && !solve(graph, neighbour, color, (nodeColor+1)%2 )){
                return false;
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<int> color(n, -1);

        for (int i=0; i<n; i++){
            if (color[i] == -1){
                if (!solve(graph, i, color, 0)){
                    return false;
                }
            }
        }

        return true;
    }
};