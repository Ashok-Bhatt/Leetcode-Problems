class Solution {
public:
    long long solve(vector<int> &segments, vector<vector<int>> &dp, int n, int k){
        if (n==-1){
            return k==0 ? 1 : 0;
        } else if (k<0){
            return 0;
        } else if (dp[n][k] != -1){
            return dp[n][k];
        } else {
            long long total = 0;
            for (int i=0; i<=min(k, segments[n]); i++){
                total = (total + solve(segments, dp, n-1, k-i))%int(1e9+7);
            }
            return dp[n][k] = total;
        }
    }

    int possibleStringCount(string word, int k) {
        int n = word.size(), temp = 1;
        long long total = 1;
        vector<int> segments;
        
        for (int i=1; i<n; i++){
            if (word[i]==word[i-1]){
                temp++;
            } else {
                total = (total * temp) % int(1e9+7);
                segments.push_back(temp-1);
                temp = 1;
            }
        }

        total = (total * temp) % int(1e9+7);
        segments.push_back(temp-1);

        if (segments.size()>=k) return total;

        k = k - segments.size() - 1;
        long long notUsed = 0; 

        vector<long long> prev(k+1, 0);
        vector<long long> curr(k+1, 0);
        vector<long long> prevPrefix(k+1, 1);
        vector<long long> currPrefix(k+1, 0);
        prev[0] = 1;

        for (int x=0; x<segments.size(); x++){
            for (int y=0; y<=k; y++){
                int l = max(0, y-segments[x])-1, r = y;
                long long current = (l<0) ? prevPrefix[r] : (prevPrefix[r] - prevPrefix[l] + int(1e9+7))%int(1e9+7);
                curr[y] = current;
                currPrefix[y] = (y==0) ? current : (currPrefix[y-1] + current)%int(1e9+7);
            }
            prev = curr;
            prevPrefix = currPrefix;
        }

        for (int i=0; i<=k; i++){
            notUsed = (notUsed + prev[i])%int(1e9+7);
        }

        return (total - notUsed + int(1e9+7))%int(1e9+7);
    }
};