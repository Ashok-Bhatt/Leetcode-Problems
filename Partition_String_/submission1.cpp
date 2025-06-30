class Solution {
public:
    vector<string> partitionString(string s) {
        int n = s.size(), index = 0;
        set<string> unique;
        unordered_map<int, string> mapping;
        string current = "";
        vector<string> ans;

        for (int i=0; i<n; i++){
            current.push_back(s[i]);
            if (unique.find(current) == unique.end()){
                unique.insert(current);
                mapping[index] = current;
                current = "";
                index++;
            }
        }

        
        for (int i=0; i<index; i++){
            ans.push_back(mapping[i]);
        }
        
        return ans;
    }
};