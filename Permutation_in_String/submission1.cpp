class Solution {
public:
    bool isPermutation(vector<int> &occurrence, vector<int> &current){
        for (int i=0; i<26; i++){
            if (occurrence[i] != current[i]){
                return false;
            }
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        
        int m = s1.size(), n = s2.size(), i = 0, j = 0;
        vector<int> occurrence(26, 0);
        vector<int> current(26, 0);

        if (m>n) return false;

        for (int i=0; i<m; i++){
            occurrence[s1[i]-'a']++;
        }

        // Creating First Window
        while (j<m){
            current[s2[j]-'a']++;
            j++;
        }

        while (j<n){
            if (isPermutation(occurrence, current)){
                return true;
            } else {
                current[s2[i]-'a']--;
                i++;
                current[s2[j]-'a']++;
                j++;
            }
        }

        return isPermutation(occurrence, current);
    }
};