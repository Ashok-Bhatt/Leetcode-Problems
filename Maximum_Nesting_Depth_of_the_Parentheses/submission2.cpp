class Solution {
public:
    int maxDepth(string s) {

        int ans = 0, n = s.size();
        stack<int> s1;

        for (int i=0; i<n; i++){
            if (s[i]=='('){
                s1.push('(');
                if (s1.size() > ans){
                    ans = s1.size();
                }
            } else if (s[i]==')'){
                s1.pop();
            }
        }

        return ans;
    }
};