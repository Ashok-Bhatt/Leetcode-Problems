class Solution {
public:
    int strStr(string haystack, string needle) {
        if (haystack.size() < needle.size()) return -1;
        string s = needle + "$" + haystack;
        int n = s.size(), left = 0, right = 0;
        vector<int> zArr(n, 0);

        for (int i=1; i<n; i++){
            if (i > right){
                left = right = i;
                while (right<n && s[right]==s[right-left]){
                    right++;
                }
                zArr[i] = right - left;
                right--;
            } else {
                int k = i-left;
                if (zArr[k] < right-i+1){
                    zArr[i] = zArr[i-left];
                } else {
                    left = i;
                    while (right<n && s[right]==s[right-left]){
                        right++;
                    }
                    zArr[i] = right - left;
                    right--;
                }
            }
        }

        for (int i=0; i<n; i++){
            if (zArr[i] == needle.size()){
                return i-needle.size()-1;
            }
        }

        return -1;
    }
};