class Solution {
public:
    int findLargest(vector<int> &mat, int n){
        int largest = 0;
        for (int i=1; i<n; i++){
            if (mat[i] > mat[largest]){
                largest = i;
            }
        }
        return largest;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int> ans = {-1, -1};
        int s = 0, e = n-1, mid;
        
        while (s<=e){
            mid = s + (e-s)/2;
            int largest = findLargest(mat[mid], m);
            if ((mid==s || mat[mid][largest] > mat[mid-1][largest]) && (mid==e || mat[mid][largest] > mat[mid+1][largest])){
                ans = {mid, largest};
                break;
            } else if (mid==s || (mid!=e && mat[mid+1][largest]>mat[mid-1][largest])){
                s = mid+1;
            } else {
                e = mid-1;
            }
        }
        return ans;
    }
};