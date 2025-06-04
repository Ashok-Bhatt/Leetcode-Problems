class Solution {
public:
    int candy(vector<int>& ratings) {

        int n = ratings.size(), ans = 1, rise = 1, down = 0, i = 1;

        while (i < n){

            // logic for rising slope
            while (i<n && ratings[i] > ratings[i-1]){
                ans = ans + ++rise;
                i++;
            }

            // slope for slipping slope
            while (i<n && ratings[i] < ratings[i-1]){
                ans = ans + ++down;
                i++;
            }

            // adjusting the peak comparing the top and foot of the slope
            if (down>=rise) ans = ans + down - rise + 1;

            // for the case when there is no slope
            while (i<n && ratings[i]==ratings[i-1]){
                ans++;
                i++;
            }
            
            // adjusting the rise and down variables for the next rising and falling slope
            rise = 1;
            down = 0;

        }

        return ans;
    }
};