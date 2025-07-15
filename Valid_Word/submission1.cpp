class Solution {
public:
    bool isVowel(char x){
        int vowels[] = {'A', 'E', 'I', 'O', 'U'};
        for (auto vowel : vowels){
            if ( (vowel==x) || ((vowel|32)==x) ) return true;
        }
        return false;
    }

    bool isValid(string word) {
        int n = word.size();
        bool consonant = false, vowel = false;
        for (int i=0; i<n; i++){
            if ((word[i]>='A' && word[i]<='Z') || (word[i]>='a' && word[i]<='z')){
                if (isVowel(word[i])){
                    vowel = true;
                } else {
                    consonant = true;
                }
            } else if (word[i]<'0' || word[i]>'9'){
                return false;
            }
        }

        return n>=3 && vowel && consonant;
    }
};