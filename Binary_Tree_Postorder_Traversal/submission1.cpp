/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> ans;
        TreeNode* current = root;

        while (!st.empty() || current){
            if (current){
                st.push(current);
                current = current->left;
            } else {
                TreeNode* temp = st.top()->right;
                if (!temp){
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->val);
                    while (!st.empty() && st.top()->right==temp){
                        temp = st.top();
                        st.pop();
                        ans.push_back(temp->val);
                    }
                } else {
                    current = temp;
                }
            }
        }

        return ans;
    }
};