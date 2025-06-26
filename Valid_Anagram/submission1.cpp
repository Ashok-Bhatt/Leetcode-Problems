class Solution {
public:
    bool isAnagram(string s, string t) {
        int m = s.size(), n = t.size();
        unordered_map<char, int> occurrence;

        if (m!=n) return false;

        for (int i=0; i<n; i++){
            occurrence[s[i]]++;
            occurrence[t[i]]--;
        }

        for (int i=0; i<26; i++){
            if (occurrence[i+'a'] != 0){
                return false;
            }
        }

        return true;
    }
};