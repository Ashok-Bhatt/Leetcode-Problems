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

    bool solve(string &s, vector<vector<int>> &dp, int index, int n, vector<string>& wordDict){

        if (index == n){
            return true;
        }

        for (int i=0; i<wordDict.size(); i++){
            if (dp[index][i] != -1){
                if (dp[index][i] == 0) return false;
                else return true;
            }

            if (isMatching(s, index, n, wordDict[i])){
                if (solve(s, dp, index + wordDict[i].size(), n, wordDict)){
                    dp[index][i] = 1;
                    return true;
                } else {
                    dp[index][i] = 0;
                }
            } else {
                dp[index][i] = 0;
            }
        }

        return false;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size(), index = 0;
        vector<vector<int>> dp(n, vector<int>(wordDict.size(), -1));
        return solve(s, dp, index, n, wordDict);
    }
};