class FindSumPairs {
public:
    int m, n;
    vector<int> nums1, nums2;
    unordered_map<int, int> freq;

    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->m = nums1.size();
        this->n = nums2.size();
        this->nums1 = nums1;
        this->nums2 = nums2;
        for (auto it : nums2) freq[it]++;
    }
    
    void add(int index, int val) {
        freq[nums2[index]]--;
        freq[nums2[index]+val]++;
        nums2[index] = nums2[index] + val;
    }
    
    int count(int tot) {
        int ans = 0;
        for (int i=0; i<m; i++){
            if (freq.find(tot-nums1[i])!=freq.end()) ans = ans + freq[tot-nums1[i]];
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */