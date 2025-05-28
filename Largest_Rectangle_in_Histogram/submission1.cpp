class Solution {
public:
    void getPSE(vector<int> &pse, vector<int> &heights, int n){
        stack<int> st;
        for (int i=0; i<n; i++){
            while (!st.empty() && heights[st.top()]>=heights[i]){
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

    void getNSE(vector<int> &nse, vector<int> &heights, int n){
        stack<int> st;
        for (int i=n-1; i>=0; i--){
            while (!st.empty() && heights[st.top()]>=heights[i]){
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

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), ans = 0;
        vector<int> pse(n), nse(n);

        getPSE(pse, heights, n);
        getNSE(nse, heights, n);

        for (int i=0; i<n; i++){
            ans = max(ans, heights[i]*(nse[i]-pse[i]-1));
        }

        return ans;
    }
};