class Solution {
public:
    int solve(long long k, vector<int> &operations){
        long long x = 1;
        int index = 0, ans = 0;
        while (x<=k){
            if (operations[index] && k&x) ans = (ans+1)%26;
            index++;
            x = x<<1;
        }
        return ans;
    }

    char kthCharacter(long long k, vector<int>& operations) {
        k--;
        return solve(k, operations)+'a';
    }
};