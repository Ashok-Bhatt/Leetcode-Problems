class Solution {
public:
    string intToRoman(int num) {
        map<int, char> numberToLetter = {{1, 'I'}, {5, 'V'}, {10, 'X'}, {50, 'L'}, {100, 'C'}, {500, 'D'}, {1000, 'M'}};
        int thousand = num/1000, hundred = (num/100)%10, ten = (num/10)%10, unit = num%10;
        string ans = "";

        for (int i=0; i<thousand; i++){
            ans.push_back('M');
        }

        if (hundred == 4 || hundred == 9){
            ans.push_back('C');
            ans.push_back(numberToLetter[(hundred+1)*100]);
        } else {
            if (hundred>=5){
                ans.push_back(numberToLetter[500]);
                hundred = hundred - 5;
            }
            for (int i=0; i<hundred; i++){
                ans.push_back('C');
            }
        }

        if (ten == 4 || ten == 9){
            ans.push_back('X');
            ans.push_back(numberToLetter[(ten+1)*10]);
        } else {
            if (ten>=5){
                ans.push_back(numberToLetter[50]);
                ten = ten - 5;
            }
            for (int i=0; i<ten; i++){
                ans.push_back('X');
            }
        }

        if (unit == 4 || unit == 9){
            ans.push_back('I');
            ans.push_back(numberToLetter[unit+1]);
        } else {
            if (unit>=5){
                ans.push_back(numberToLetter[5]);
                unit = unit - 5;
            }
            for (int i=0; i<unit; i++){
                ans.push_back('I');
            }
        }

        return ans;
    }
};