class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int n = players.size(), m = trainers.size(), i = 0, j = 0, ans = 0;

        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        while (i<n && j<m){
            if (players[i] > trainers[j]){
                j++;
            } else {
                i++;
                j++;
                ans++;
            }
        }

        return ans;
    }
};