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
        queue<pair<TreeNode*, int>> q1;
        q1.push({target, 0});
        if(k == 0) return {target->val};
        unordered_map<TreeNode*, bool> visited;
        visited[target] = true;
        while(!q1.empty()){
            int n = q1.size();
            for(int i = 0; i < n; i++){
                auto temp = q1.front();
                q1.pop();
                TreeNode* node = temp.first;
                int dis = temp.second;
                if(dis > k) continue;
                if(dis == k){
                    ans.push_back(node->val);
                    continue;
                }
                if(parentMap[node] && !visited[parentMap[node]]){
                    q1.push({parentMap[node], dis+1});
                    visited[parentMap[node]] = true;
                }
                if(node->left && !visited[node->left]){
                    q1.push({node->left, dis+1});
                    visited[node->left] = true;
                }
                if(node->right && !visited[node->right]) {
                    q1.push({node->right, dis+1});
                    visited[node->right] = true;
                }
            }
        }
        return ans;
    }
};