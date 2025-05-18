class cmp{
    public:
    int totalSum(int x){
        int ans = 0;
        while (x){
            ans = ans + x%10;
            x = x / 10;
        }
        return ans;
    }
    
    bool operator()(int &a, int &b){
        return (totalSum(a) > totalSum(b)) || (totalSum(a) == totalSum(b) && a > b);
    }  
};

class Solution {
public:
    
    int minSwaps(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        priority_queue<int, vector<int>, cmp> pq;
        unordered_map<int, int> indexing;

        for (int i=0; i<n; i++){
            pq.push(nums[i]);
            indexing[nums[i]] = i;
        }

        for (int i=0; i<n; i++){
            int top = pq.top();
            pq.pop();

            int topIndex = indexing[top];
            if (top != nums[i]){
                swap(nums[topIndex], nums[i]);
                indexing[nums[topIndex]] = topIndex;
                indexing[nums[i]] = i;
                ans++;
            }
        }

        return ans;
    }
};