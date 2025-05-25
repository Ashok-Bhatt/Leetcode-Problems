class Solution {
public:
    long long minCuttingCost(int n, int m, int k) {
        long long ans = 0;
        cout << (m<=k) << " " << (n<=k) << endl;
        if (m>k) ans = ans + (long long)k*(m-k);
        if (n>k) ans = ans + (long long)k*(n-k);
        // ans = ans + (m<=k) ? 0 : k*(m-k);
        // ans = ans + (n<=k) ? 0 : k*(n-k);
        return ans;
    }
};