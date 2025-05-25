class Solution {
public:
    bool isAdjacent(char x, char y){
        return abs(x-y)==1 || (x=='a' && y=='z') || (x=='z' && y=='a');
    }
    
    string resultingString(string s) {
        int n = s.size();
        stack<char> st;
        string ans;

        for (int i=0; i<n; i++){
            if (st.empty() || !isAdjacent(s[i], st.top())){
                st.push(s[i]);
            } else {
                st.pop();
            }
        }

        while (!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};