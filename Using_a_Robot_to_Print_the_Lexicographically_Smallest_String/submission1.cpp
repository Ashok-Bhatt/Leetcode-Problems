class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();
        vector<int> lastOccurrence(26, -1);
        stack<int> st;
        string ans;

        for (int i=0; i<n; i++){
            lastOccurrence[s[i]-'a'] = i;
        }

        int last = lastOccurrence[0], current = 0;

        for (int i=1; i<26; i++){
            if (lastOccurrence[i] < last){
                lastOccurrence[i] = -1;
            } else {
                last = lastOccurrence[i];
            }
        }

        for (int i=0; i<26; i++){
            if (lastOccurrence[i] != -1){

                for (int j=current; j<=lastOccurrence[i]; j++){

                    while (!st.empty() && st.top()<=i){
                        int top = st.top();
                        st.pop();
                        ans.push_back(top+'a');
                    }

                    if (s[j]-'a' == i){
                        ans.push_back(s[j]);
                    } else {
                        st.push(s[j]-'a');
                    }
                }

                current = lastOccurrence[i]+1;
            }
        }

        while (!st.empty()){
            int top = st.top();
            st.pop();
            ans.push_back(top+'a');
        }

        return ans;
    }
};