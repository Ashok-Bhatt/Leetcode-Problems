class Solution {
public:
    int romanToInt(string s) {
        int n = s.size(), ans = 0;
        unordered_map<char, int> letterToNumber = {{'I',1}, {'V',5}, {'X',10}, {'L',50}, {'C',100}, {'D',500}, {'M',1000}};

        for (int i=0; i<n; i++){
            if (i+1<n && letterToNumber[s[i]]<letterToNumber[s[i+1]]){
                ans = ans - letterToNumber[s[i]];
            } else {
                ans = ans + letterToNumber[s[i]];
            }
        }

        return ans;
    }
};