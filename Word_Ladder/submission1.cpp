class Solution {
public:
    int gap(string &x, string &y){
        int ans = 0;
        for (int i=0; i<x.size(); i++){
            if (x[i] != y[i]){
                ans++;
            }
        }

        return ans;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        vector<bool> visited(n);
        queue<pair<int, int>> q;

        // Initializing queue with one gap words
        for (int i=0; i<n; i++){
            if (!visited[i] && gap(beginWord, wordList[i]) == 1){
                q.push({i, 1});
                visited[i] = true;
            }
        }

        // Solving problem until either queue is not empty or we get solution
        while (!q.empty()){
            pair<int, int> front = q.front();
            int index = front.first, value = front.second;

            if (wordList[index] == endWord){
                return value+1;
            }

            q.pop();

            for (int i=0; i<n; i++){
                if (!visited[i] && gap(wordList[index], wordList[i]) == 1){
                    q.push({i, value+1});
                    visited[i] = true;
                }
            }
        }

        return 0;
    }
};