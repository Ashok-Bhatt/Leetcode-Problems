class cmp{
public:
    bool operator()(pair<char, int> &a, pair<char, int> &b){
        return (a.first > b.first) || (a.first == b.first && a.second < b.second);
    }
};

class Solution {
public:
    string clearStars(string s) {
        int n = s.size();
        priority_queue<pair<char, int>, vector<pair<char, int>>, cmp> pq;
        string ans;

        for (int i=0; i<n; i++){
            if (s[i] == '*'){
                pair<char, int> top = pq.top();
                int index = top.second;
                pq.pop();
                s[index] = '*';
            } else {
                pq.push({s[i], i});
            }
        }
        
        for (int i=0; i<n; i++){
            if (s[i] != '*'){
                ans.push_back(s[i]);
            }
        }

        return ans;
    }
};