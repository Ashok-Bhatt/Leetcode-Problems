class Solution {
public:
    static bool cmp(pair<char, int> &a, pair<char, int> &b){
        return a.second > b.second;
    }

    string frequencySort(string s) {
        int n = s.size(), i = 0;
        vector<pair<char, int>> frequency(62, {' ', 0});
        
        while (i<n){
            if (s[i]>='a' && s[i]<='z'){
                frequency[s[i]-'a'].first = s[i];
                frequency[s[i]-'a'].second++;
            } else if (s[i]>='A' && s[i]<='Z'){
                frequency[s[i]-'A'+26].first = s[i];
                frequency[s[i]-'A'+26].second++;
            } else {
                frequency[s[i]-'0'+52].first = s[i];
                frequency[s[i]-'0'+52].second++;
            }
            i++;
        }

        sort(frequency.begin(), frequency.end(), cmp);

        i = 0;
        for (auto it : frequency){
            char character = it.first;
            int occurrence = it.second;
            while (occurrence){
                s[i] = character;
                occurrence--;
                i++;
            }
        }

        return s;
    }
};