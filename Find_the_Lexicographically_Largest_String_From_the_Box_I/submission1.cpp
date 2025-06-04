class Solution {
public:
    bool isLexicographicallyLarger(string word, int index, int ansIndex, int size, int n){

        for (int i=0; i<min(size, n-index); i++){
            if (word[i+index] > word[i+ansIndex]){
                return true;
            } else if (word[i+index] < word[i+ansIndex]){
                return false;
            }
        }

        return false;
    }

    string answerString(string word, int numFriends) {
        
        int n = word.size(), size = n - (numFriends - 1), ansIndex = 0;
        string ans;

        if (numFriends==1){
            return word;
        }

        for (int i=0; i<n; i++){
            if (isLexicographicallyLarger(word, i, ansIndex, size, n)){
                ansIndex = i;
            }
        }

        for (int i=ansIndex; i<min(ansIndex+size, n); i++){
            ans.push_back(word[i]);
        }

        return ans;
    }
};