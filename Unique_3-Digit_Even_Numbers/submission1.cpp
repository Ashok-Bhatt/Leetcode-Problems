class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        unordered_set<int> unique;
        int n = digits.size();
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                for (int k=0; k<n; k++){
                    if (i!=j && j!=k && k!=i && digits[i]!= 0 && digits[k] % 2 == 0){
                        int num = digits[i]*100 + digits[j]*10 + digits[k];
                        unique.insert(num);
                    }
                }
            }
        }

        return unique.size();
    }
};