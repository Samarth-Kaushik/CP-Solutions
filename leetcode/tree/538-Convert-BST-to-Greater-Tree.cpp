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
    void solve(TreeNode* root, int& runningSum){
        if(!root) return;
        solve(root->right, runningSum);
        runningSum += root->val;
        root->val = runningSum;
        solve(root->left, runningSum);
    }
    TreeNode* convertBST(TreeNode* root) {
        int runningSum = 0;
        solve(root, runningSum);
        return root;
    }
};