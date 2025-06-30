class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int n = s.size(), ans = 0, zeroes = 0, ones = 0;
        int i = 0, j = 0;

        while (j<n){

            while (j<n && s[j]=='0'){
                zeroes++;
                j++;
            }

            while (j<n && s[j]=='1'){
                ones++;
                j++;
            }

            ans = max(ans, min(zeroes, ones)*2);
            zeroes = ones = 0;
        }

        return ans;
    }
};