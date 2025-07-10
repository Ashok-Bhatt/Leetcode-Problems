class Solution {
public:
    char kthCharacter(int k) {
        string temp = "a";
        while (temp.size() < k){
            int n = temp.size();
            for (int i=0; i<n; i++){
                temp.push_back(temp[i] + 1);
            }
        }
        return temp[k-1];
    }
};