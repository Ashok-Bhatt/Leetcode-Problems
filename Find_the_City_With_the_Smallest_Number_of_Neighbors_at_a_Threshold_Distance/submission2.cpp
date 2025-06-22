class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        int e = edges.size(), ans = INT_MAX, ansIndex = 0;
        vector<vector<int>> costMatrix(n, vector<int>(n, (int)1e8));

        for (int i=0; i<n; i++){
            costMatrix[i][i] = 0;
        }

        for (int i=0; i<e; i++){
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            if (w <= distanceThreshold){
                costMatrix[u][v] = w;
                costMatrix[v][u] = w;
            }
        }

        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                for (int k=0; k<n; k++){
                    if (costMatrix[j][i]+costMatrix[i][k] < costMatrix[j][k] && costMatrix[j][i]+costMatrix[i][k] <= distanceThreshold){
                        costMatrix[j][k] = costMatrix[j][i]+costMatrix[i][k];
                    }
                }
            }
        }

        for (int i=0; i<n; i++){
            int temp = 0;
            for (int j=0; j<n; j++){
                if (costMatrix[i][j] != (int)1e8){
                    temp++;
                }
            }

            if (temp <= ans){
                ans = temp;
                ansIndex = i;
            }
        }

        return ansIndex;
    }
};