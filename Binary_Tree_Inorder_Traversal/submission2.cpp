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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        unordered_set<TreeNode*> occurrence;

        if (root){
            st.push(root);
        }

        while (!st.empty()){
            TreeNode* top = st.top();

            if (occurrence.find(top) == occurrence.end()){
                occurrence.insert(top);
                if (top->left){
                    st.push(top->left);
                }
            } else {
                ans.push_back(top->val);
                st.pop();
                if (top->right){
                    st.push(top->right);
                }
            }
        }

        return ans;
    }
};