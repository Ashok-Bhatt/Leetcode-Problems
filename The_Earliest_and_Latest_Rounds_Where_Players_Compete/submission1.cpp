class Solution {
public:
    int getEarliest(int n, int firstPlayer, int secondPlayer, vector<bool> &earliestUsed, int i, int j){

        while (i<n && earliestUsed[i]==true) i++;
        while (j>=0 && earliestUsed[j]==true) j--;

        if (i>=j){
            return 1 + getEarliest(n, firstPlayer, secondPlayer, earliestUsed, 0, n-1);
        } else if (i==firstPlayer && j==secondPlayer){
            return 1;
        } else if (i==firstPlayer || i==secondPlayer){
            earliestUsed[j] = true;
            int temp = getEarliest(n, firstPlayer, secondPlayer, earliestUsed, i+1, j-1);
            earliestUsed[j] = false;
            return temp;
        } else if (j==firstPlayer || j==secondPlayer){
            earliestUsed[i] = true;
            int temp = getEarliest(n, firstPlayer, secondPlayer, earliestUsed, i+1, j-1);
            earliestUsed[i] = false;
            return temp;
        } else {
            int mini = INT_MAX;
            earliestUsed[i] = true;
            mini = min(mini, getEarliest(n, firstPlayer, secondPlayer, earliestUsed, i+1, j-1));
            earliestUsed[i] = false;
            earliestUsed[j] = true;
            mini = min(mini, getEarliest(n, firstPlayer, secondPlayer, earliestUsed, i+1, j-1));
            earliestUsed[j] = false;
            return mini;
        }
    }

    int getLatest(int n, int firstPlayer, int secondPlayer, vector<bool> &latestUsed, int i, int j){

        while (i<n && latestUsed[i]==true) i++;
        while (j>=0 && latestUsed[j]==true) j--;

        if (i>=j){
            return 1 + getLatest(n, firstPlayer, secondPlayer, latestUsed, 0, n-1);
        } else if (i==firstPlayer && j==secondPlayer){
            return 1;
        } else if (i==firstPlayer || i==secondPlayer){
            latestUsed[j] = true;
            int temp = getLatest(n, firstPlayer, secondPlayer, latestUsed, i+1, j-1);
            latestUsed[j] = false;
            return temp;
        } else if (j==firstPlayer || j==secondPlayer){
            latestUsed[i] = true;
            int temp = getLatest(n, firstPlayer, secondPlayer, latestUsed, i+1, j-1);
            latestUsed[i] = false;
            return temp;
        } else {
            int maxi = INT_MIN;
            latestUsed[i] = true;
            maxi = max(maxi, getLatest(n, firstPlayer, secondPlayer, latestUsed, i+1, j-1));
            latestUsed[i] = false;
            latestUsed[j] = true;
            maxi = max(maxi, getLatest(n, firstPlayer, secondPlayer, latestUsed, i+1, j-1));
            latestUsed[j] = false;
            return maxi;
        }
    }

    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        vector<int> ans = {0, 0};
        vector<bool> earliestUsed(n, false), latestUsed(n, false);

        ans[0] = getEarliest(n, firstPlayer-1, secondPlayer-1, earliestUsed, 0, n-1);
        ans[1] = getLatest(n, firstPlayer-1, secondPlayer-1, latestUsed, 0, n-1);
        return ans;
    }
};