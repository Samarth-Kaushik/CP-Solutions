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
    int countNodes(TreeNode* root) {
        int leftH = 0;
        TreeNode* temp = root;
        while(temp != NULL){
            leftH++;
            temp = temp->left;
        }
        temp = root;
        int rightH = 0;
        while(temp != NULL){
            rightH++;
            temp = temp->right;
        }
        if(leftH == rightH) return (1 << leftH)-1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};