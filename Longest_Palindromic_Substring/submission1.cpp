class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(), ansIndex = 0, ansSize = 1;
        string ans = "";

        for (int i=0; i<n; i++){
            int l, r;

            // Odd Length Palimdrome
            l = i, r = i;
            while (l>=0 && r<n && s[l]==s[r]){
                if (r-l+1>ansSize){
                    ansIndex = l;
                    ansSize = r-l+1;
                }
                l--;
                r++;
            }

            // Even Length Palimdrome
            l = i, r = i+1;
            while (l>=0 && r<n && s[l]==s[r]){
                if (r-l+1>ansSize){
                    ansIndex = l;
                    ansSize = r-l+1;
                }
                l--;
                r++;
            }
        }

        for (int i=ansIndex; i<ansIndex+ansSize; i++){
            ans.push_back(s[i]);
        }

        return ans;
    }
};