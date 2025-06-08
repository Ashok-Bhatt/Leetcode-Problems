class Solution {
public:
    void solve(vector<int> &ans, int i, int n){
        if (i>n){
            return;
        }

        ans.push_back(i);
        for (int j=0; j<10; j++){
            solve(ans, i*10+j, n);
        }
    }

    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for (int i=1; i<10; i++){
            solve(ans, i, n);
        }
        return ans;
    }
};