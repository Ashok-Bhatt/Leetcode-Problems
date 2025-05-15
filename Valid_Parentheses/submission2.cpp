class Solution {
public:
    bool isValid(string s) {

       stack<char> balance;
       int size = s.length();

       for (int i=0; i<size; i++){
            if (s[i]=='(' || s[i]=='{' || s[i]=='['){
               balance.push(s[i]);
            }
            else if (balance.empty()){
                return false;
            }
            else{
                if( (balance.top()=='(' && s[i]==')')  ||  (balance.top()=='{' && s[i]=='}')  || (balance.top()=='[' && s[i]==']')){
                   balance.pop();
                }
                else{
                    return false;
                }
            }
       }

       if (balance.empty()){
           return true;
       }
       return false;

    }
};