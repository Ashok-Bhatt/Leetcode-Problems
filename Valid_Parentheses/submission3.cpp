class Solution {
public:
    bool isValid(string s) {
        
        stack<char> bracketBox;
        int length = s.length();

        for (int i=0; i<length; i++){
            if (bracketBox.empty()){
                bracketBox.push(s[i]);
            }
            else if ((bracketBox.top()=='(' && s[i]==')') || (bracketBox.top()=='{' && s[i]=='}') || (bracketBox.top()=='[' && s[i]==']')){
                bracketBox.pop();
            }
            else{
                bracketBox.push(s[i]);
            }
        }

        if (bracketBox.empty()){
            return true;
        }
        return false;
    }
};