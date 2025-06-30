class Solution {
private:
    bool isMatching(string &s, int index, int n, string &word){
        int i = 0;
        while (i < word.size()){
            if ((index>=n) || (s[index+i]!=word[i])){
                return false;
            }
            i++;
        }
        return true;
    }

    bool solve(string &s, vector<int> &dp, int index, int n, vector<string>& wordDict){

        if (index == n){
            return true;
        } else if (dp[index] != -1){
            return dp[index]==0 ? false : true;
        } else {
            for (int i=0; i<wordDict.size(); i++){
                if (isMatching(s, index, n, wordDict[i])){
                    if (solve(s, dp, index + wordDict[i].size(), n, wordDict)){
                        dp[index] = 1;
                        return true;
                    }
                }
            }
            
            dp[index] = 0;
            return false;
        }
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size(), index = 0;
        vector<int> dp(n, -1);
        return solve(s, dp, index, n, wordDict);
    }
};