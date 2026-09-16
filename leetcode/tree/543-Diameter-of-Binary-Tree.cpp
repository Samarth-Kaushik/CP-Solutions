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
    pair<int, int> diameter(TreeNode* root){
        if(root == NULL) return {0,0};
        pair<int, int> right = diameter(root->right);
        pair<int, int> left = diameter(root->left);
        int op1 = left.first;
        int op2 = right.first;
        int op3 = right.second + left.second;
        pair<int, int> ans;
        ans.first = max({op1, op2, op3});
        ans.second = max(left.second, right.second) + 1;
        return ans;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return diameter(root).first;
    }
};