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
    pair<int, int> solve(TreeNode* root){
        if (!root){
            return {INT_MIN, 0};
        } else {
            pair<int, int> left = solve(root->left);
            pair<int, int> right = solve(root->right);
            int ans = max(root->val + (left.second>=0?left.second:0) + (right.second>=0?right.second:0), max(left.first, right.first));
            int pathSum = max(root->val, root->val + max(left.second, right.second));
            return {ans, pathSum};
        }
    }

    int maxPathSum(TreeNode* root) {
        return solve(root).first;
    }
};