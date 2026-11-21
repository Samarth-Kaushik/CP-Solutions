class Codec {
public:
    
    string serialize(TreeNode* root) {
        if (!root) return "";  
        
        string ans = "";
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            
            if (!node) {
                ans += "#,";
            } else {
                ans += to_string(node->val) + ',';
                q.push(node->left);
                q.push(node->right);
            }
        }
        return ans;
    }

     
    TreeNode* deserialize(string data) {
        if (data.empty()) return NULL;
        
        stringstream ss(data);
        string str;
        
         
        getline(ss, str, ',');
        TreeNode* root = new TreeNode(stoi(str));
        
        queue<TreeNode*> q;
        q.push(root);
        
         
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            
             
            getline(ss, str, ',');
            if (str != "#") {
                node->left = new TreeNode(stoi(str));
                q.push(node->left);
            }
            
             
            getline(ss, str, ',');
            if (str != "#") {
                node->right = new TreeNode(stoi(str));
                q.push(node->right);
            }
        }
        
        return root;
    }
};  