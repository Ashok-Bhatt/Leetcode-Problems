class Solution {
public:
    void getPSE(vector<int> &pse, vector<int> &curr, int n){
        stack<int> st;
        for (int i=0; i<n; i++){
            while (!st.empty() && curr[st.top()]>=curr[i]){
                st.pop();
            }

            if (st.empty()){
                pse[i] = -1;
            } else {
                pse[i] = st.top();
            }

            st.push(i);
        }
    }

    void getNSE(vector<int> &nse, vector<int> &curr, int n){
        stack<int> st;
        for (int i=n-1; i>=0; i--){
            while (!st.empty() && curr[st.top()]>=curr[i]){
                st.pop();
            }

            if (st.empty()){
                nse[i] = n;
            } else {
                nse[i] = st.top();
            }

            st.push(i);
        }
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), ans = 0;
        vector<int> prev(n, 0);

        for (int i=0; i<m; i++){

            vector<int> curr(n, 0);
            vector<int> pse(n), nse(n);

            for (int j=0; j<n; j++){
                if (matrix[i][j] == '1'){
                    curr[j] = 1 + prev[j];
                }
            }

            getPSE(pse, curr, n);
            getNSE(nse, curr, n);

            for (int j=0; j<n; j++){
                ans = max(ans, curr[j]*(nse[j]-pse[j]-1));
            }

            prev = curr; 
        }

        return ans;
    }
};