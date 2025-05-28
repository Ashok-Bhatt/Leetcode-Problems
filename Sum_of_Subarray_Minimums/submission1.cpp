class Solution {
public:
    void getPSE(vector<int> &pse, vector<int> &arr, int n){
        stack<int> st;
        for (int i=0; i<n; i++){
            while (!st.empty() && arr[st.top()]>=arr[i]){
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

    void getNSEE(vector<int> &ngee, vector<int> &arr, int n){
        stack<int> st;
        for (int i=n-1; i>=0; i--){
            while (!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }

            if (st.empty()){
                ngee[i] = n;
            } else {
                ngee[i] = st.top();
            }

            st.push(i);
        }
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long long ans = 0;
        vector<int> pse(n), nsee(n);

        getPSE(pse, arr, n);
        getNSEE(nsee, arr, n);

        for (int i=0; i<n; i++){
            ans = (ans + (long long)(arr[i]) * (i-pse[i]) * (nsee[i]-i) ) % (int)(1e9+7);
        }

        return ans;
    }
};