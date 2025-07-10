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
        vector<int> ans;
        stack<TreeNode*> st;
        unordered_map<TreeNode*, int> occurrence;

        if (root){
            st.push(root);
            occurrence[root] = 0;
        }

        while (!st.empty()){
            TreeNode* top = st.top();
            if (occurrence[top] == 0){
                occurrence[top]++;
                if (top->left){
                    st.push(top->left);
                    occurrence[top->left] = 0;
                }
            } else  if (occurrence[top] == 1){
                occurrence[top]++;
                if (top->right){
                    st.push(top->right);
                    occurrence[top->right] = 0;
                }
            } else {
                ans.push_back(top->val);
                st.pop();
            }
        }

        return ans;
    }
};