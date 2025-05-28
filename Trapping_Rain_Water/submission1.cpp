class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), prevMaxi = INT_MIN, nextMaxi = INT_MIN, ans = 0;
        vector<int> prev(n), next(n);

        for (int i=0; i<n; i++){
            prevMaxi = max(prevMaxi, height[i]);
            prev[i] = prevMaxi;
        }

        for (int i=n-1; i>=0; i--){
            nextMaxi = max(nextMaxi, height[i]);
            next[i] = nextMaxi;
        }

        for (int i=0; i<n; i++){
            ans = ans + min(prev[i], next[i]) - height[i];
        }

        return ans;
    }
};