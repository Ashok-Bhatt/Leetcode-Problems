class Solution {
public:
    bool isFeasibleSolution(vector<int> &freq, int k){
        int maxi = 0, sum = 0;
        for (int i=0; i<26; i++){
            sum = sum + freq[i];
            maxi = max(maxi, freq[i]);
        }
        return (sum - maxi) <= k;
    }

    int characterReplacement(string s, int k) {
        int n = s.size(), i = 0, j = 0, ans = 0;
        vector<int> freq(26, 0);

        while (j<n){
            freq[s[j]-'A']++;
            j++;
            if (isFeasibleSolution(freq, k)){
                ans = max(ans, j-i);
            }

            while (!isFeasibleSolution(freq, k)){
                freq[s[i]-'A']--;
                i++;
            }
        }

        return ans;
    }
};