class Solution {
public:
    bool isValid(string s) {
        stack<char> validator;
        int n = s.size();

        for (int i=0; i<n; i++){
            if (s[i] == '(' || s[i] == '{' || s[i] == '['){
                validator.push(s[i]);
            } else {
                if ((!validator.empty()) && ((validator.top()=='(' && s[i]==')') || (validator.top()=='{' && s[i]=='}') || (validator.top()=='[' && s[i]==']')) ){
                    validator.pop();
                } else {
                    return false;
                }
            }
        }

        return validator.empty();
    }
};