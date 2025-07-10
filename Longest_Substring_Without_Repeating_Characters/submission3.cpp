class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n = s.size(), i = 0, j = 0, ans = 0;
        unordered_map<char, bool> characters;

        while (j<n){

            while (j<n && characters[s[j]]==0){
                characters[s[j]] = 1;
                j++;
            }

            ans = max(ans, j-i);

            while (j<n && characters[s[j]]!=0){
                characters[s[i]] = 0;
                i++;
            }
        }

        return ans;
    }
};