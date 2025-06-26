class Solution {
public:
    bool isAnagram(string s, string t) {

        if (s.size() != t.size()){
            return false;
        }

        unordered_map<char, int> mapping;
        int n = s.size();

        for (int i=0; i<n; i++){
            mapping[s[i]]++;
        }

        for (int i=0; i<n; i++){
            if (mapping.find(t[i])==mapping.end() || mapping[t[i]] == 0){
                return false;
            } else {
                mapping[t[i]]--;
            }
        }

        return true;
    }
};