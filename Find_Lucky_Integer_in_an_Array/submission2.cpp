class Solution {
public:
    int findLucky(vector<int>& arr) {
        int n = arr.size(), ans = -1;
        map<int, int> freq;

        for (auto it : arr){
            freq[it]++;
        }

        for (auto it : freq){
            if (it.first == it.second && it.first>ans) ans = it.first;
        }

        return ans;
    }
};