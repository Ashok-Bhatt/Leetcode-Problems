class Solution {
public:
    bool isPrime(int n){
        if (n<2) return false;

        for (int i=2; i*i<=n; i++){
            if (n%i==0){
                return false;
            }
        }

        return true;
    }
    
    bool checkPrimeFrequency(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> occurrence;

        for (int i=0; i<n; i++){
            occurrence[nums[i]]++;
        }

        for (auto it : occurrence){
            if (isPrime(it.second)){
                return true;
            }
        }

        return false;
    }
};