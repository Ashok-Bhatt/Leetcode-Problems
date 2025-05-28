class Solution {
public:
    void getPSE(vector<int> &pse, vector<int> &nums, int n){
        stack<int> st;
        for (int i=0; i<n; i++){
            while (!st.empty() && nums[st.top()]>=nums[i]){
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

    void getNSEE(vector<int> &nsee, vector<int> &nums, int n){
        stack<int> st;
        for (int i=n-1; i>=0; i--){
            while (!st.empty() && nums[st.top()]>nums[i]){
                st.pop();
            }

            if (st.empty()){
                nsee[i] = n;
            } else {
                nsee[i] = st.top();
            }

            st.push(i);
        }
    }

    void getPGE(vector<int> &pge, vector<int> &nums, int n){
        stack<int> st;
        for (int i=0; i<n; i++){
            while (!st.empty() && nums[st.top()]<=nums[i]){
                st.pop();
            }

            if (st.empty()){
                pge[i] = -1;
            } else {
                pge[i] = st.top();
            }

            st.push(i);
        }
    }

    void getNGEE(vector<int> &ngee, vector<int> &nums, int n){
        stack<int> st;
        for (int i=n-1; i>=0; i--){
            while (!st.empty() && nums[st.top()]<nums[i]){
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
    
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> pse(n), nsee(n), pge(n), ngee(n);
        long long ans = 0;

        getPSE(pse, nums, n);
        getNSEE(nsee, nums, n);
        getPGE(pge, nums, n);
        getNGEE(ngee, nums, n);

        for (int i=0; i<n; i++){
            ans = ans - ( (long long)nums[i] * (i-pse[i]) * (nsee[i]-i) );
            ans = ans + ( (long long)nums[i] * (i-pge[i]) * (ngee[i]-i) );
        }

        return ans;
    }
};