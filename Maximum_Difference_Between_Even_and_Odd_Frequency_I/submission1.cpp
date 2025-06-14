class Solution {
public:
    int maxDifference(string s) {
        int n = s.size(), maxi = INT_MIN, mini = INT_MAX;
        unordered_map<char, int> frequency;

        for (int i=0; i<n; i++){
            frequency[s[i]]++;
        }

        for (int i='a'; i<='z'; i++){
            if (frequency[i] != 0){
                if (frequency[i]%2==0){
                    mini = min(mini, frequency[i]);
                } else {
                    maxi = max(maxi, frequency[i]);
                }
            }
        }

        return maxi-mini;
    }
};