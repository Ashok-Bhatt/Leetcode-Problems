class Solution {
public:
    char getUpper(char x){
        if (x>='a' && x<='z'){
            x = x + 'A' - 'a';
        }
        return x;
    }

    char getLower(char x){
        if (x>='A' && x<='Z'){
            x = x - 'A' + 'a';
        }
        return x;
    }
    
    string generateTag(string caption) {

        string ans = "#";
        int count = 0, n = caption.size();
        bool isCapital = true;

        for (int i=0; i<n; i++){
            if (caption[i] == ' '){
                isCapital = true;
            } else if ((caption[i]<'A') || (caption[i]>'z' || (caption[i]>'Z' && caption[i]<'a'))){
                continue;
            } else {
                if (isCapital && ans.size()>1){
                    ans.push_back(getUpper(caption[i]));
                    isCapital = false;
                } else {
                    ans.push_back(getLower(caption[i]));
                    isCapital = false;
                }
            }

            if (ans.size() == 100){
                break;
            }
        }

        return ans;
    }
};