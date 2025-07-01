class Solution {
public:
    bool isSolution(unordered_map<char, int> &freq1, unordered_map<char, int> &freq2){

        for (int i=0; i<26; i++){
            if (freq1[i+'a']>freq2[i+'a'] || freq1[i+'A']>freq2[i+'A']){
                return false;
            }
        }

        return true;
    }

    string minWindow(string s, string t) {
        int n = s.size(), m = t.size(), i = 0, j = 0;
        unordered_map<char, int> freq1, freq2;
        int ansIndex = 0, ansLength = INT_MAX;
        string ans = "";

        for (int ptr=0; ptr<m; ptr++){
            freq1[t[ptr]]++;
        }

        while (j<n){

            freq2[s[j]]++;
            j++;

            if (isSolution(freq1, freq2) && j-i < ansLength){
                ansLength = j-i;
                ansIndex = i;
            }

            while (isSolution(freq1, freq2)){
                freq2[s[i]]--;
                if (freq2[s[i]] == 0){
                    freq2.erase(s[i]);
                }
                i++;

                if (isSolution(freq1, freq2) && j-i<ansLength){
                    ansLength = j-i;
                    ansIndex = i;
                }
            }
        }

        if (ansLength == INT_MAX) return "";

        for (int ptr=ansIndex; ptr<ansIndex+ansLength; ptr++){
            ans.push_back(s[ptr]);
        }

        return ans;
    }
};