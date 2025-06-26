class Solution {
public:
    int getGap(vector<int> &frequency){
        int maxi = INT_MIN, mini = INT_MAX;
        for (int i=0; i<26; i++){
            if (frequency[i] != 0){
                maxi = max(maxi, frequency[i]);
                mini = min(mini, frequency[i]);
            }
        }
        return maxi-mini;
    }

    int beautySum(string s) {
        int n = s.size(), sum = 0;
        for (int i=0; i<n; i++){
            vector<int> frequency(26, 0);
            for (int j=i; j<n; j++){
                frequency[s[j]-'a']++;
                sum = sum + getGap(frequency);
            }
        }
        return sum;
    }
};