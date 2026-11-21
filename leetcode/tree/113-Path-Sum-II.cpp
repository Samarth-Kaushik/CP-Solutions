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
    void solve(TreeNode* root, int targetSum, vector<int>& v, vector<vector<int>>& ans){
        if(root == NULL) return;
        v.push_back(root->val);
        if(root->left == NULL && root->right == NULL && targetSum == root->val){
            ans.push_back(v);
        }
        else{
            solve(root->left, targetSum-root->val, v, ans);
            solve(root->right, targetSum-root->val, v, ans);
        }
        v.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> v;
        vector<vector<int>> ans;
        solve(root, targetSum, v, ans);
        return ans;
    }
};