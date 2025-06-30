class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size(), ans = 0, current = 0;

        // First Window containing only left elements
        for (int i=0; i<k; i++){
            current = current + cardPoints[i];
        }

        ans = current;

        // Now checking other k windows in which we will push current window to left and extract new window from right side
        for (int i=0; i<k; i++){
            current = current - cardPoints[k-i-1] + cardPoints[n-i-1];
            ans = max(ans, current);
        }

        return ans;
    }
};