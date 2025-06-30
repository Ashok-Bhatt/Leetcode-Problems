class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int ans = 0, sum = 0,  n = cardPoints.size() ;

        // rightmost window
        for (int i=n-k; i<n; i++){
            sum = sum + cardPoints[i];
            ans = sum;
        }

        // portion of right window + portion of left window
        int i=n-k, j = n-1;
        while (i<n){
            j++;
            sum = sum + cardPoints[j%n];
            sum = sum - cardPoints[i];
            i++;
            ans = max(ans, sum);
        }

        // leftmost window
        sum = 0;
        for (int i=0; i<k; i++){
            sum = sum + cardPoints[i];
            ans = max(ans, sum);
        }

        return ans;

    }
};