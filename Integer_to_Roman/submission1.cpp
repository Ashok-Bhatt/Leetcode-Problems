class Solution {
public:
    string intToRoman(int num) {
        map<int, char> numberToLetter = {{1, 'I'}, {5, 'V'}, {10, 'X'}, {50, 'L'}, {100, 'C'}, {500, 'D'}, {1000, 'M'}};
        int x = 1000;
        string ans = "";

        while (x){
            int y = (num/x)*x, digit = num/x;

            if (digit == 4 || digit == 9){
                ans.push_back(numberToLetter[x]);
                ans.push_back(numberToLetter[y+x]);
                num = num - y;
            } else {
                if (digit >= 5){
                    ans.push_back(numberToLetter[5*x]);
                    y = y - 5*x;
                    num = num - 5*x;
                }

                while (y){
                    ans.push_back(numberToLetter[x]);
                    y = y - x;
                    num = num - x;
                }
            }
            x = x/10;
        }

        return ans;
    }
};