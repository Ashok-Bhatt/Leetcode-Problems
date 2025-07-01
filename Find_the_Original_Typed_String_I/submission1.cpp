class Solution {
public:
    int possibleStringCount(string word) {
        int n = word.size(), i = 0, j = 0, ans = 0;
        while (j<n){
            while (j<n && word[i]==word[j]){
                j++;
            }
            ans = ans + j - i - 1;
            i = j;
        }
        return ans+1;
    }
};