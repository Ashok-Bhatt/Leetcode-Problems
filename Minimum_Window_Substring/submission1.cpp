class Solution {
public:
    bool isFeasibleSolution(unordered_map<char, int> &maxOccurrence, unordered_map<char, int> &occurrence){

        for (auto x : maxOccurrence){
            char character = x.first;
            int maxCount = x.second;
            if (occurrence[character] < maxCount){
                return false;
            }
        }

        return true;

    }

    string minWindow(string s, string t) {
        pair<int, int> ans= {-1, -1};
        int m = s.size(), n = t.size(), i = 0, j = 0;
        string ansString;
        unordered_map<char, int> occurrence;
        unordered_map<char, int> maxOccurrence;

        for (int i=0; i<n; i++){
            maxOccurrence[t[i]]++;
        }

        while (i<m){

            if (j<m){
                if (maxOccurrence.find(s[j]) != maxOccurrence.end()){
                    occurrence[s[j]]++;
                }
                j++;
            } else if (!isFeasibleSolution(maxOccurrence, occurrence)){
                break;
            }

            while (isFeasibleSolution(maxOccurrence, occurrence)){

                if ((ans.first == -1) || (ans.second-ans.first+1 > j-i)){
                    ans = {i, j-1};
                }

                occurrence[s[i]]--;
                i++;

            }
        }

        if (ans.first == -1) return ansString;

        for (int i=ans.first; i<=ans.second; i++){
            ansString.push_back(s[i]);
        }

        return ansString;
    }
};