class Solution {
public:

    static bool cmpX(vector<int> &a, vector<int> &b){
        return (a[0] < b[0]) || (a[0] == b[0] && a[1] < b[1]);
    }

    static bool cmpY(vector<int> &a, vector<int> &b){
        return (a[1] < b[1]) || (a[1] == b[1] && a[0] < b[0]);
    }
    
    long long maxArea(vector<vector<int>>& coords) {

        int n = coords.size();
        long long ans = -1;
        vector<vector<int>> coordX(n);
        vector<vector<int>> coordY(n);

        // Parallel to Y-axis
        sort(coords.begin(), coords.end(), cmpX);

        for (int i=0; i<n; i++){
            coordX[i] = coords[i];
        }

        // Parallel to X-axis
        sort(coords.begin(), coords.end(), cmpY);

        for (int i=0; i<n; i++){
            coordY[i] = coords[i];
        }

        int i = 0, j = 1;
        while (i<n){
            while (j<n && coordX[j][0] == coordX[i][0]){
                j++;
            }

            if (i!=j-1){
                if (i!=0){
                    ans = max(ans, (long long)(coordX[j-1][1]-coordX[i][1])*abs(coordX[i][0] - coordX[0][0]));
                }

                if (j!=n){
                    ans = max(ans, (long long)(coordX[j-1][1]-coordX[i][1])*abs(coordX[i][0] - coordX[n-1][0]));
                }
            }

            i = j;
            j++;
        }

        i = 0;
        j = 1;
        while (i<n){
            while (j<n && coordY[j][1] == coordY[i][1]){
                j++;
            }

            if (i!=j-1){
                if (i!=0){
                    ans = max(ans, (long long)(coordY[j-1][0]-coordY[i][0])*abs(coordY[i][1] - coordY[0][1]));
                }

                if (j!=n){
                    cout << i << " " << j-1 << endl;
                    cout << coordY[j-1][0] << " " << coordY[i][0] << " ";
                    ans = max(ans, (long long)(coordY[j-1][0]-coordY[i][0])*abs(coordY[i][1] - coordY[n-1][1]));
                }
            }

            i = j;
            j++;
        }

        if (ans==0){
            return -1;
        }

        return ans;
    }
};