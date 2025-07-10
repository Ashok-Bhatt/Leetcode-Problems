class Solution {
public:
    int findLucky(vector<int>& arr) {
        int n = arr.size(), ans = -1, counter = 1;

        sort(arr.begin(), arr.end(), greater<int>());

        for (int i=1; i<n; i++){
            if (arr[i]==arr[i-1]){
                counter++;
            } else {
                if (counter == arr[i-1]) ans = max(ans, counter);
                counter = 1;
            }
        }

        if (counter == arr[n-1]) ans = max(ans, counter);
        return ans;
    }
};