class Solution {
public:
    bool isFeasibleSolution(unordered_map<char, int> &occurrence, int k, int currentCount){
        char maxOccurrenceIndex = 'A';
        for (char i='B'; i<='Z'; i++){
            if (occurrence[i] > occurrence[maxOccurrenceIndex]){
                maxOccurrenceIndex = i;
            }
        }

        return (currentCount - occurrence[maxOccurrenceIndex]) <= k;
    }

    int characterReplacement(string s, int k) {
        
        int n = s.size(), ans = 0, i = 0, j = 0, currentCount = 0;
        unordered_map<char, int> occurrence;
        
        while (j<n){
            currentCount++;
            occurrence[s[j]]++;
            j++;

            if (isFeasibleSolution(occurrence, k, currentCount)){
                ans = max(ans, j-i);
            } else {
                while (!isFeasibleSolution(occurrence, k, currentCount)){
                    currentCount--;
                    occurrence[s[i]]--;
                    i++;
                }
            }
        }

        return ans;
    }
};