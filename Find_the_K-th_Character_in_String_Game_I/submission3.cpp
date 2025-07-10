class Solution {
public:
    char kthCharacter(int k) {
        int count = 1, n;
        string x = "a";
        while (count < k){
            n = x.size();
            for (int i=0; i<n; i++){
                char nextCharacter = ((x[i]-'a')+1)%26 + 'a';
                x.push_back(nextCharacter);
                count = x.size();
            }
        }

        return x[k-1];
    }
};