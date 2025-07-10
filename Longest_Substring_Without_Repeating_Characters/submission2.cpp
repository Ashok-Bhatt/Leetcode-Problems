class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n = s.size(), i = 0, j = 0, ans = 0;
        vector<int> characters(256, -1);

        while (j < n){

            while (j<n && characters[s[j]] < i){
                characters[s[j]] = j;
                j++;
            }

            ans = max(ans, j-i);
            i = characters[s[j]] + 1;
            characters[s[j]] = j;
            j++;
        }

        return ans;
    }
};