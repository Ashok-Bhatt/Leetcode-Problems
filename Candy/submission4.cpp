class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size(), ans = 0;
        vector<int> left(n,1);
        vector<int> right(n,1);

        // processing the left array
        for (int i=1; i<n; i++){
            if (ratings[i] > ratings[i-1]){
                left[i] = left[i-1] + 1;
            }
        }

        // processing for right array
        for (int i=n-2; i>=0; i--){
            if (ratings[i+1] < ratings[i]){
                right[i] = right[i+1] + 1;
            }
        }

        // Processing the answer
        for (int i=0; i<n; i++){
            ans = ans + max(left[i], right[i]);
        }

        return ans;
    }
};