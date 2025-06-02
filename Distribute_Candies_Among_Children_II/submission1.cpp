class Solution {
public:
    long long solve(int n, int candies, int limit){
        if (n==2){
            if (candies<=limit){
                return candies+1;
            } else if (candies<=2*limit){
                return 2*limit-candies+1;
            } else {
                return 0;
            }
        } else {
            long long ans = 0;
            for (int i=0; i<=min(candies, limit); i++){
                ans = ans + solve(n-1, candies-i, limit);
            }
            return ans;
        }
    }

    long long distributeCandies(int n, int limit) {
        return solve(3, n, limit);
    }
};