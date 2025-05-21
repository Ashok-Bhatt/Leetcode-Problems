class Solution {
public:
    void block(vector<vector<char>>& board, vector<vector<bool>> &visited, int x, int y, int m, int n){

        visited[x][y] = true;
        vector<pair<int, int>> neighbors = {{x-1, y}, {x+1, y}, {x, y-1}, {x, y+1}};

        for (auto neighbour : neighbors){
            int newX = neighbour.first, newY = neighbour.second;
            if (newX>=0 && newX<m && newY>=0 && newY<n && board[newX][newY]=='O' && !visited[newX][newY]){
                block(board, visited, newX, newY, m, n);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size(), ans = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // Bocking cells starting from first row and last row
        for (int i=0; i<n; i++){
            if (board[0][i]=='O' && !visited[0][i]){
                block(board, visited, 0, i, m, n);
            }

            if (board[m-1][i]=='O' && !visited[m-1][i]){
                block(board, visited, m-1, i, m, n);
            }
        }

        // Bocking cells starting from first column and last column
        for (int i=0; i<m; i++){
            if (board[i][0]=='O' && !visited[i][0]){
                block(board, visited, i, 0, m, n);
            }

            if (board[i][n-1]=='O' && !visited[i][n-1]){
                block(board, visited, i, n-1, m, n);
            }
        }

        // Converting every unvisited/unblocked O to X
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (board[i][j]=='O' && !visited[i][j]){
                    board[i][j] = 'X';
                }
            }
        }
    }
};