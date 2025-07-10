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
        TreeNode* node = root;
        stack<TreeNode*> st;

        if (root) {
            st.push(root);
            node = node->left;   
        }

        while (!st.empty() || node){
            if (node){
                st.push(node);
                node = node->left;
            } else {
                ans.push_back(st.top()->val);
                node = st.top()->right;
                st.pop();
            }
        }

        return ans;
    }
};