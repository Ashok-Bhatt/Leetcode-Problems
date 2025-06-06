class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int m = s1.size(), n = baseStr.size(), current = 0;
        unordered_map<char, int> mapping;
        unordered_map<int, char> smallestCharacter;
        string ans = "";

        for (int i=0; i<m; i++){
            char first = s1[i], second = s2[i];
            if (mapping.find(first)==mapping.end() && mapping.find(second)==mapping.end()){
                mapping[first] = mapping[second] = current;
                current++;
            } else if (mapping.find(first)!=mapping.end() && mapping.find(second)!=mapping.end()) {
                int firstGroup = mapping[first], secondGroup = mapping[second];
                for (char j='a'; j<='z'; j++){
                    if (mapping.find(j)!=mapping.end() && mapping[j] == firstGroup){
                        mapping[j] = secondGroup;
                    }
                }
            } else if (mapping.find(first)==mapping.end()){
                mapping[first] = mapping[second];
            } else {
                mapping[second] = mapping[first];
            }
        }

        for (char i='a'; i<='z'; i++){
            if (mapping.find(i) != mapping.end() && smallestCharacter.find(mapping[i]) == smallestCharacter.end()){
                smallestCharacter[mapping[i]] = i;
            }
        }

        for (int i=0; i<n; i++){
            if (mapping.find(baseStr[i]) != mapping.end()){
                ans.push_back(smallestCharacter[mapping[baseStr[i]]]);
            } else {
                ans.push_back(baseStr[i]);
            }
        }

        return ans;
    }
};