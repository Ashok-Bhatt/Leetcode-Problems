class Solution {
public:
    int maxDepth(string s) {
        int n = s.size(), current = 0, ans = 0;
        for (int i=0; i<n; i++){
            if (s[i] == '('){
                current++;
                ans = max(ans, current);
            } else if (s[i]==')'){
                current--;
            }
        }
        return ans;
    }
};