class Solution {
public:
    string getHexadecimal(int n){
        string ans = "";
        while (n){
            int digit = n%16;
            if (digit <= 9){
                ans.push_back(digit + '0');
            } else {
                ans.push_back(digit - 10 + 'A' );
            }
            n = n/16;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }

    string getHexaTrigemisal(int n){
        string ans = "";
        while (n){
            int digit = n%36;
            if (digit <= 9){
                ans.push_back(digit + '0');
            } else {
                ans.push_back(digit - 10 + 'A' );
            }
            n = n/36;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    string concatHex36(int n) {
        return getHexadecimal(n*n) + getHexaTrigemisal(n*n*n);
    }
};