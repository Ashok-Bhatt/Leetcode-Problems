class Solution {
public:
    vector<int> lexicalOrder(int n) {
        
        vector<int> ans;
        int current  = 1;
        
        while (current > 0){
            ans.push_back(current);
            if (current*10 <= n){
                current = current*10;
            } else if (current%10!=9 && current+1 <= n){
                current++;
            } else {
                current = current/10;
                while (current%10 == 9){
                    current = current/10;
                }

                if (current!=0 && current+1 <= n){
                    current++;
                }
            }
        }

        return ans;
    }
};