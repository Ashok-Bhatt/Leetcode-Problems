class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, n = s.size(), j = n-1;
        while (i < j){
            while (i<n && !isalnum(s[i])) i++;
            while (j>=0 && !isalnum(s[j])) j--;
            if (i<j && tolower(s[i]) != tolower(s[j])) return false;
            i++;
            j--;
        }
        return true;
    }
};