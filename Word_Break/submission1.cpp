class Solution {
public:
    bool isMatching(string s, string t, int n, int index){
        for (int i=0; i<n; i++){
            if (s[index+i] != t[i]){
                return false;
            }
        }
        return true;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size(), m = wordDict.size();
        vector<bool> dp(n+1, false);
        
        dp[n] = true;

        for (int i=n-1; i>=0; i--){
            int ans = false;
            for (int j=0; j<m; j++){
                if (i + wordDict[j].size() <= n && isMatching(s, wordDict[j], wordDict[j].size(), i) && dp[i+wordDict[j].size()]){
                    ans = true;
                    break;
                }
            }

            dp[i] = ans;
        }

        return dp[0];
    }
};