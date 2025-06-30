class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size(), i = 0, j = 0, ans = 0;
        unordered_map<char, int> occurrences;
        while (j<n){
            occurrences[s[j]]++;
            if (occurrences.size() == 3){
                ans = ans + n - j;
            }

            while (occurrences.size() == 3){
                occurrences[s[i]]--;
                if (occurrences[s[i]] == 0){
                    occurrences.erase(s[i]);
                }
                i++;
                if (occurrences.size() == 3){
                    ans = ans + n - j;
                }
            }
            j++;
        }

        return ans;
    }
};