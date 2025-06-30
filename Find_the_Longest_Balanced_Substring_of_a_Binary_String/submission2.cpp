class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int n = s.size(), ans = 0, zeros = 0, ones = 0;
        for (int i=0; i<n; i++){
            if (s[i] == '0'){
                ones = 0;
                zeros++;
            } else {
                ones++;
                ans = max(ans, min(zeros, ones)*2);
                if (i+1<n && s[i+1]=='0') zeros = 0;
            }
        }
        return ans;
    }
};