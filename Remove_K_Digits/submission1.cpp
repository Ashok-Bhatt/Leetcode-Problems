class Solution {
public:
    string removeKdigits(string num, int k) {

        int n = num.size();
        stack<int> st;
        vector<int> nsee(n);

        for (int i=n-1; i>=0; i--){
            
            while (!st.empty() && num[i]<=num[st.top()]){
                st.pop();
            }

            if (st.empty()){
                nsee[i] = n;
            } else {
                nsee[i] = st.top();
            }

            st.push(i);
        }

        int i = 0;
        string ans = "";

        while (i<n){
            if (nsee[i]-i<=k){
                k = k - (nsee[i] - i);
                i = nsee[i];
            } else {
                if ((ans!="") || (ans=="" && num[i] != '0')){
                    ans.push_back(num[i]);
                }
                i++;    
            }
        }

        while (k--){
            ans.pop_back();
        }

        return (ans=="") ? "0" : ans;
    }
};