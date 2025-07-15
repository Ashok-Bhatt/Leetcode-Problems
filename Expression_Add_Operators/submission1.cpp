class Solution {
public:

    void solve(string &num, int target, int index, int n, string &temp, vector<string> &ans, long long current, long long prev, int sign){

        if (index==n){
            if ((long long)target == current) ans.push_back(temp);
            return;
        }

        if (index==0){
            long long nextNum = 0;
            for (int i=0; i<n; i++){
                nextNum = nextNum*10 + num[i]-'0';
                temp.push_back(num[i]);
                solve(num, target, i+1, n, temp, ans, nextNum, nextNum, 1);
                if (num[index] == '0'){
                    temp.pop_back();
                    return;
                }
            }

            for (int i=0; i<n; i++){
                temp.pop_back();
            }
        } else {

            vector<char> operators = {'*', '+', '-'};

            for (auto op : operators){
                long long nextNum = 0;
                temp.push_back(op);
                
                for (int i=index; i<n; i++){
                    nextNum = nextNum*10 + num[i]-'0';
                    temp.push_back(num[i]);
                    if (op == '+'){
                        solve(num, target, i+1, n, temp, ans, current+nextNum, nextNum, 1);
                    } else if (op == '-'){
                        solve(num, target, i+1, n, temp, ans, current-nextNum, nextNum, 0);
                    } else {
                        if (sign == 0){
                            solve(num, target, i+1, n, temp, ans, (current+prev) - (prev*nextNum), prev*nextNum, 0);
                        } else if (sign == 1){
                            solve(num, target, i+1, n, temp, ans, (current-prev) + (prev*nextNum), prev*nextNum, 1);
                        } else {
                            solve(num, target, i+1, n, temp, ans, current*nextNum, prev*nextNum, 2);
                        }
                    }

                    if (num[index] == '0'){
                        temp.pop_back();
                        break;
                    }
                }   

                temp.pop_back();
                if (num[index] != '0'){
                    for (int i=index; i<n; i++){
                        temp.pop_back();
                    }
                }
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        string temp = "";
        int n = num.size(), index = 0;
        long long current = 0, prev = 0;
        int sign = 1;
        vector<string> ans;
        solve(num, target, index, n, temp, ans, current, prev, sign);
        return ans;
    }
};