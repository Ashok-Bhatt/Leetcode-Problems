class Solution {
public:
    int solve(int k, int x){
        if (k<=1){
            return 0;
        } else if (k<=x){
            return solve(k, x/2);
        } else {
            return (1 + solve(k-x, x/2)) % 26;
        }
    }

    char kthCharacter(int k) {
        int x = 1;
        while (2*x < k) x = 2*x;
        return solve(k, x) + 'a';
    }
};