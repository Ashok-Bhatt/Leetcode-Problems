class cmp{
public:
    int reverse(int x){
        int y = 0;
        while (x){
            y = y*10 + x%10;
            x = x/10;
        }
        return y;
    }

    bool operator()(int &a, int &b){
        int x = reverse(a), y = reverse(b);
        while (x && y){
            if (x%10 > y%10){
                return true;
            } else if (x%10 < y%10){
                return false;
            } else {
                x = x/10;
                y = y/10;
            }
        }

        if (!x && !y){
            return a > b;
        } else if (!x){
            return false;
        } else {
            return true;
        }
    }
};

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        priority_queue<int, vector<int>, cmp> pq;
        vector<int> ans;

        for (int i=1; i<=n; i++){
            pq.push(i);
        }

        while (!pq.empty()){
            int top = pq.top();
            pq.pop();
            ans.push_back(top);
        }

        return ans;
    }
};