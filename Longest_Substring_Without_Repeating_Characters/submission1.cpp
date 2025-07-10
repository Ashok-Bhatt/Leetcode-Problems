class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n = s.size(), i=0, j=0, ans = 0;
        unordered_map<char, int> freq;

        while (j<n){
            freq[s[j]]++;
            if (freq[s[j]] <= 1) ans = max(ans, j-i+1);
            while (freq[s[j]] > 1){
                freq[s[i]]--;
                i++;
            }
            j++;
        }

        return ans;
    }
};