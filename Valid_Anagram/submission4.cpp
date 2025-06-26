class Solution {
public:
    bool isAnagram(string s, string t) {
        
        unordered_map<char, int> mapping;
        
        for (int i=0; i<s.size(); i++){
            char element = s[i];
            mapping[element]++;
        }

        for (int i=0; i<t.size(); i++){
            char element = t[i];
            mapping[element]--;
        }

        for (auto i:mapping){
            if (i.second != 0){
                return false;
            }
        }

        return true;
    }
};