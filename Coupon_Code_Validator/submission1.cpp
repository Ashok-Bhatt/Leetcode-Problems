class Solution {
public:
    static bool cmp(pair<string, string> &x, pair<string, string> &y){
        unordered_map<string, int> businessOptions = {{"electronics", 1}, {"grocery", 2}, {"pharmacy", 3}, {"restaurant", 4}};

        return (businessOptions[x.first]<businessOptions[y.first]) || (businessOptions[x.first]==businessOptions[y.first] && x.second<y.second);
    }

    bool isAlphaNumneric(string &x){
        for (auto it : x){
            if ((it=='_') || (it>='A' && it<='Z') || (it>='a' && it<='z') || (it>='0' && it<='9')) continue;
                return false;
        }
        return true;
    }

    bool isValidBusiness(string &x){
        return x=="electronics" || x=="grocery" || x=="pharmacy" || x=="restaurant";
    }
    
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n = code.size();
        vector<pair<string, string>> temp;
        vector<string> ans;

        for (int i=0; i<n; i++){
            if (code[i].size()>0 && isAlphaNumneric(code[i]) && isValidBusiness(businessLine[i]) && isActive[i]){
                temp.push_back({businessLine[i], code[i]});
            }
        }

        sort(temp.begin(), temp.end(), cmp);

        for (auto it : temp){
            ans.push_back(it.second);
        }

        return ans;
    }
};