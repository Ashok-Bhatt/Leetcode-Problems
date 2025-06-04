class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {

        int n = status.size(), ans = 0;
        queue<int> q;
        vector<int> visited(n, false);
        vector<int> used(n, false);

        for (auto box : initialBoxes){
            if (status[box]){
                q.push(box);
                used[box] = true;
            }
            visited[box] = true;
        }

        while (!q.empty()){

            int front = q.front();
            q.pop();

            ans = ans + candies[front];

            for (auto x : keys[front]){
                status[x] = 1;
                if (visited[x] && !used[x]){
                    q.push(x);
                    used[x] = true;
                }
            }

            for (auto x : containedBoxes[front]){
                if (status[x]){
                    q.push(x);
                    used[x] = true;
                }
                visited[x] = true;
            }
        }

        return ans;
    }
};