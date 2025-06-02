class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> ans(m-k+1, vector<int>(n-k+1));

        for (int i=0; i<m-k+1; i++){
            for (int j=0; j<n-k+1; j++){
                
                vector<int> elements;
                for (int x=i; x<i+k; x++){
                    for (int y=j; y<j+k; y++){
                        elements.push_back(grid[x][y]);
                    }
                }

                sort(elements.begin(), elements.end());

                int answer = INT_MAX, last = INT_MIN;
                for (int x=0; x<k*k; x++){
                    if (last == INT_MIN){
                        last = elements[x];
                    } else if (last != elements[x]){
                        answer = min(answer, elements[x]-last);
                        last = elements[x];
                    }
                }

                if (answer == INT_MAX){
                    answer = 0;
                }

                ans[i][j] = answer;
            }
        }

        return ans;
    }
};