class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == divisor){
            return 1;
        } else if (dividend==INT_MIN){
            if (divisor== -1) return INT_MAX;
            else if (divisor==1) return INT_MIN;
        } else if (divisor==INT_MIN){
            return 0;
        }

        int ans = 0, x = 1;
        bool isNegative = (dividend<0) ^ (divisor<0);
        divisor = abs(divisor);

        if (dividend == INT_MIN){
            ans++;
            dividend = dividend + divisor;
        }

        dividend = abs(dividend);

        while (x*divisor <= INT_MAX/2 && 2*x*divisor<=dividend){
            x = 2*x;
        }

        cout << x << " ";
        while (dividend >= divisor){
            if (dividend - divisor*x >= 0){
                ans = ans + x;
                dividend = dividend - divisor*x;
            }
            x = x/2;
        }

        return isNegative ? -ans : ans;
    }
};