class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        int n = fruits.size(), i = 0, j = 0, ans = 0;
        unordered_map<int, int> occurrence;

        while (j<n){
            occurrence[fruits[j]]++;
            j++;

            while (occurrence.size() > 2){
                occurrence[fruits[i]]--;
                if (occurrence[fruits[i]] == 0){
                    occurrence.erase(fruits[i]);
                }
                i++;
            }

            ans = max(ans, j-i);
        }

        return ans;
    }
};