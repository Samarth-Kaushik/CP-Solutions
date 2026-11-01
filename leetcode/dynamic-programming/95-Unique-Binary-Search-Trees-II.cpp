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
    vector<TreeNode*> solve(int start, int end){
        vector<TreeNode*> ans;
        if(start > end){
            ans.push_back(NULL);
            return ans;
        }
        for(int i = start; i <= end; i++){
            vector<TreeNode*> leftSubtree = solve(start, i-1);
            vector<TreeNode*> rightSubtree = solve(i+1, end);
            for(TreeNode* leftNode : leftSubtree){
                for(TreeNode* rightNode : rightSubtree){
                    TreeNode* root = new TreeNode(i);
                    root->left = leftNode;
                    root->right = rightNode;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        // vector<TreeNode*> ans;
        if(n == 0) return {};
        return solve(1, n);
    }
};