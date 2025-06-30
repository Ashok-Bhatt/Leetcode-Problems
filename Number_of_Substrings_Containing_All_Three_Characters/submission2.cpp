class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size(), i = 0, j = 0, ans = 0;
        unordered_map<char, int> occurrence;

        while (j<n){
            occurrence[s[j]]++;
            j++;
            if (occurrence.size() == 3){
                ans = ans + n - j + 1;

                while (occurrence.size() == 3){
                    occurrence[s[i]]--;
                    if (occurrence[s[i]] == 0){
                        occurrence.erase(s[i]);
                    } else {
                        ans = ans + n - j + 1;
                    }
                    i++;
                }
            }
        }

        return ans;
    }
};