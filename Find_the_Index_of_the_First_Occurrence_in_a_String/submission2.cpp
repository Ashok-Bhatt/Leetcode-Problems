class Solution {
public:
    void findLps(string needle, vector<int> &lps, int m){
        int i = 0, j = 1;
        while (j<m){
            while (i>=0 && needle[i]!=needle[j]){
                i--;
                if (i>=0){
                    i = lps[i];
                }
            }

            lps[j] = i+1;
            i++;
            j++;
        }
    }

    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        vector<int> lps(m, 0);

        findLps(needle, lps, m);
        int i = 0, j = 0;

        while (i<n && j<m){
            if (haystack[i] == needle[j]){
                i++;
                j++;
            } else {
                while (j>=0 && haystack[i]!=needle[j]){
                    j--;
                    if (j>=0) j = lps[j];
                }
                i++;
                j++;
            }
        }

        if (j>=m)return i-m;
        return -1;
    }
};