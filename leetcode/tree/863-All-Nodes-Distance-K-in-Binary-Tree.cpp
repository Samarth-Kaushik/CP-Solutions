/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parentMap;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            for(int i = 0; i < n; i++){
                TreeNode* temp = q.front();
                q.pop();
                if(temp->right){
                    parentMap[temp->right] = temp;
                    q.push(temp->right);
                }
                if(temp->left){
                    parentMap[temp->left] = temp;
                    q.push(temp->left);
                }
            }
        }
        // int cnt = 0;
        vector<int> ans;
        q.push(target);
        unordered_map<TreeNode*, bool> visited;
        visited[target] = true;
        int currLevel = 0;
        while(!q.empty()){
            int n = q.size();
            TreeNode* node = q.front();
            // q.pop();
            if(currLevel == k) break;
           for(int i = 0; i < n; i++){
            TreeNode* node = q.front();
                q.pop();
                
                if(parentMap[node] && !visited[parentMap[node]]){
                    q.push(parentMap[node]);
                    visited[parentMap[node]] = true;
                }
                if(node->left && !visited[node->left]){
                    q.push(node->left);
                    visited[node->left] = true;
                }
                if(node->right && !visited[node->right]){
                    q.push(node->right);
                    visited[node->right] = true;
                }
           }
            currLevel++;
        }
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};