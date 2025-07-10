class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int ans = 0;
        int length = s.length();
        int i=0, j=0;

        unordered_map<char,int> mapping;

        while (j<length){

            char element = s[j];
            mapping[element]++;

            if (mapping[element]==2){
                while (mapping[element]==2){
                    char element2 = s[i];
                    mapping[element2]--;
                    i++;
                }
            }

            int currentSize = j-i+1;
            ans = max(ans,currentSize);
            j++;
        }

        return ans;
    }
};