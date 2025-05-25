class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        unordered_map<int, int> elementToIndex;
        stack<int> st;
        vector<int> ans(m);

        for (int i=0; i<m; i++){
            elementToIndex[nums1[i]] = i;
        }

        for (int i=n-1; i>=0; i--){
            
            while (!st.empty() && st.top() <= nums2[i]){
                st.pop();
            }

            if (elementToIndex.find(nums2[i]) != elementToIndex.end()){
                if (st.empty()){
                    ans[elementToIndex[nums2[i]]] = -1;
                } else {
                    ans[elementToIndex[nums2[i]]] = st.top();
                }
            }

            st.push(nums2[i]);

        }

        return ans;
    }
};