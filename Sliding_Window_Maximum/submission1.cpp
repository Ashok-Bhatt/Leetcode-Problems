class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size(), l = 0, r = 0;
        vector<int> ans(n-k+1);
        deque<int> dq;

        while (r<k){
            while (!dq.empty() && nums[dq.back()]<nums[r]){
                dq.pop_back();
            }

            dq.push_back(r);
            r++;
        }

        ans[l] = nums[dq.front()];

        while (r<n){

            if (dq.front() == l){
                dq.pop_front();
            }

            l++;

            while (!dq.empty() && nums[dq.back()]<nums[r]){
                dq.pop_back();
            }

            dq.push_back(r);
            ans[l] = nums[dq.front()];
            r++;
        }

        return ans;
    }
};