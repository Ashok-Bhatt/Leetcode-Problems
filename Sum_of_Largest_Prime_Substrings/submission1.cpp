class Solution {
public:
    bool isPrime(long long n){
        
        long long i=2;
        while (i*i <= n){
            if (n%i == 0) {
                return false;
            }
            i++;
        }

        if (n<=1){
            return false;
        } else {
            return true;
        }
    }
    
    long long sumOfLargestPrimes(string s) {
        int n = s.size();
        long long ans = 0;
        unordered_set<long long> unique;
        priority_queue<long long> pq;

        for (int i=0; i<n; i++){
            long long num = 0;
            for (int j=i; j<n; j++){
                num = num*10 + s[j] - '0';
                if (isPrime(num)){
                    unique.insert(num);
                }
            }
        }

        for (auto x : unique){
            pq.push(x);
        }

        for (int i=0; i<3; i++){
            if (!pq.empty()){
                ans = ans + pq.top();
                pq.pop();   
            }
        }

        return ans;
    }
};