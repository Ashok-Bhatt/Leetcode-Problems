class Solution {
public:
    void solve(vector<vector<int>>& image, int i, int j, int newColor, int oldColor, int m, int n){
        if (i<0 || i>=m || j<0 || j>=n || image[i][j]!=oldColor || image[i][j]==newColor){
            return;
        }

        image[i][j] = newColor;
        vector<pair<int, int>> neighbors = {{i-1, j}, {i+1, j}, {i, j-1}, {i, j+1}};

        for (auto neighbour : neighbors){
            solve(image, neighbour.first, neighbour.second, newColor, oldColor, m, n);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size(), n = image[0].size(), oldColor = image[sr][sc];
        solve(image, sr, sc, color, oldColor, m, n);
        return image;
    }
};