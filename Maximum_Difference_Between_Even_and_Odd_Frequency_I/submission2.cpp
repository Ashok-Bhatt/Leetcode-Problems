class Solution {
public:
    int maxDifference(string s) {
        int freq[26] = {0};
        int mini = INT_MAX, maxi = INT_MIN;
        for (int i=0; i<s.size(); i++){
            freq[s[i]-'a']++;
        }

        for (int i=0; i<26; i++){
            if (freq[i] != 0){
                 if (freq[i]%2==0){
                    mini = min(mini, freq[i]);
                } else {
                    maxi = max(maxi, freq[i]);
                }   
            }
        }

        return maxi-mini;
    }
};