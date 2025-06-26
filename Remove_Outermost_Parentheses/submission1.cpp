class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size(), current = 0;
        string ans = "";

        for (int i=0; i<n; i++){
            if (s[i] == '('){
                current++;
                if (current>1){
                    ans.push_back(s[i]);
                }
            } else {
                if (current > 1){
                    ans.push_back(s[i]);
                }
                current--;
            }
        }

        return ans;
    }
};