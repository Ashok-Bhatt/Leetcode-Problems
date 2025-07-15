class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == 0) return 0;
        else if (divisor==INT_MIN && dividend==INT_MIN) return 1;
        else if (dividend==INT_MIN){
            if (divisor == -1) return INT_MAX;
            else if (divisor == 1) INT_MIN;
        } else if (divisor==INT_MIN){
            return 0;
        }

        long long x = 1, ans = 0;
        bool sign = (dividend<0) ^ (divisor<0);

        if (dividend == INT_MIN){
            dividend = dividend + abs(divisor);
            ans++;
        }

        dividend = abs(dividend);
        divisor = abs(divisor);

        if (divisor>dividend) return sign ? -ans : ans;

        while (2*x*divisor <= (long long)dividend){
            x = 2*x;
        }

        while (dividend >= divisor){
            if (dividend >= divisor*x){
                ans = ans + x;
                dividend = dividend - divisor*x;
            }
            x = x/2;
        }

        return sign ? -ans : ans;
    }
};