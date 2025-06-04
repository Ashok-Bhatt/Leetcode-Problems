class Solution {
public:
    int candy(vector<int>& ratings) {
        
        int n = ratings.size(), ptr=n-2, ans = 0;
        vector<int> temp(n,1);

        // processing for the left part
        for (int i=1; i<n; i++){
            if (ratings[i] > ratings[i-1]) temp[i] = temp[i-1] + 1;
        }

        // processing for the right part
        for (int i=n-2; i>=0; i--){
            if (ratings[i] > ratings[i+1]) temp[i] = max(temp[i], temp[i+1]+1);
            ans = ans + temp[i];
        }

        return n==1 ? 1 : ans + temp[n-1];
    }
};