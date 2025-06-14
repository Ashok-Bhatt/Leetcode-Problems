class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        int n = wordList.size(), m = beginWord.size();
        unordered_set<string> present;
        queue<pair<string, int>> q;

        for (int i=0; i<n; i++){
            present.insert(wordList[i]);   
        }

        q.push({beginWord, 1});

        while (!q.empty()){
            pair<string, int> front = q.front();
            string word = front.first;
            int level = front.second;

            q.pop();

            if (word == endWord){
                return level;
            }

            for (int i=0; i<m; i++){
                for (char j='a'; j<='z'; j++){
                    string newWord = word;
                    newWord[i] = j;
                    if (present.find(newWord) != present.end()){
                        present.erase(newWord);
                        q.push({newWord, level+1});
                    }
                }
            }
        }

        return 0;
    }
};