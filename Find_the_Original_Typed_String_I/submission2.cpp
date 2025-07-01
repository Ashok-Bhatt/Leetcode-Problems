class Solution {
public:
    int possibleStringCount(string word) {
        
        int n = word.size(), ans = 1, occurrence = 1;
        char character = word[0];

        for (int i=1; i<=n; i++){
            if (i==n){
                ans = ans + occurrence - 1;
            } else if (word[i] == character){
                occurrence++;
            } else {
                ans = ans + occurrence - 1;
                character = word[i];
                occurrence = 1;
            }
        }

        return ans;
    }
};