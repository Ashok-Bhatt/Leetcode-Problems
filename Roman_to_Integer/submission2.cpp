class Solution {
public:
    int romanToInt(string s) {
        int n = s.size(), ans = 0, i = 0;
        unordered_map<char, int> letterToNumber = {{'I',1}, {'V',5}, {'X',10}, {'L',50}, {'C',100}, {'D',500}, {'M',1000}};

        while (i<n){
            int ratio = letterToNumber[s[i+1]]/letterToNumber[s[i]];
            if ( i+1<n &&  (ratio==5 || ratio==10)){
                ans = ans + letterToNumber[s[i+1]] - letterToNumber[s[i]];
                i = i + 2;
            } else {
                ans = ans + letterToNumber[s[i]];
                i++;
            }
        }

        return ans;
    }
};