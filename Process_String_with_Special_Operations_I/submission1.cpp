class Solution {
public:
    string processStr(string s) {
        int n = s.size();
        string ans = "";

        for (int i=0; i<n; i++){
            if (s[i] == '*'){
                if (ans.size() > 0) ans.pop_back();
            } else if (s[i] == '#'){
                string temp = ans;
                ans = ans + temp;
            } else if (s[i] == '%'){
                 reverse(ans.begin(), ans.end());
            } else {
                ans.push_back(s[i]);
            }
        }

        return ans;
    }
};