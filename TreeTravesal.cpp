/*
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// http://www.cnblogs.com/grandyang/p/4606334.html

/*
 * LeetCode:
 * 94: Binary Tree Inorder Traversal
 *
 */

// Method 1: Using Stack
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode* cur = root;
        
        while (cur || !s.empty()){
            while (cur){
                s.push(cur);
                cur = cur->left;
            }
            cur = s.top();
            s.pop();
            res.push_back(cur->val);
            cur = cur->right;
        }
        return res;
    }
};

// Method 2: Using Recursion
class Solution {
    void helper(TreeNode* root, vector<int> &res){
        if (root == NULL) return;
        helper(root->left, res);
        res.push_back(root->val);
        helper(root->right, res);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        helper(root, res);
        return res;
    }
};

/*
 * LeetCode:
 * 144: Binary Tree Preorder Traversal
 *
 */

// Method 1: Using Stack
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) return {};
        vector<int> res;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()){
            TreeNode* cur = s.top();
            s.pop();
            res.push_back(cur->val);
            if (cur->right) s.push(cur->right);
            if (cur->left) s.push(cur->left);
        }
        return res;
    }
};

// Method 2: Using Recursion
class Solution {
    void helper(TreeNode* root, vector<int> &res){
        if (root == NULL) return;
        res.push_back(root->val);
        helper(root->left, res);
        helper(root->right, res);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        helper(root, res);
        return res;
    }
};


/*
 * LeetCode:
 * 145: Binary Tree Postorder Traversal
 *
 */

// Method 1: Using Stack
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        stack<TreeNode*> s;
        s.push(root);
        TreeNode* last_visit = root;
        while (!s.empty()){
            // if a leaf node or already visited node
            TreeNode* cur = s.top();
            if ((!cur->left && !cur->right) ||
                (cur->left == last_visit || cur->right == last_visit)){
                res.push_back(cur->val);
                s.pop();
                last_visit = cur;
            }
            else{
                if (cur->right) s.push(cur->right);
                if (cur->left) s.push(cur->left);
            }
        }
        return res;
    }
};

// Method 2: Using Recursion
class Solution {
    void help(TreeNode* root, vector<int>& res){
        if (!root) return;
        help(root->left, res);
        help(root->right, res);
        res.push_back(root->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        help(root, res);
        return res;
    }
};


/*
 * LeetCode:
 * 102: Binary Tree Level Order Traversal
 *
 */

// Method 1: Using Recursion
class Solution {
    void help(TreeNode* root, int level, vector<vector<int>>& res){
        if (!root) return;
        if (level == res.size()) res.push_back(vector<int>());
        res[level].push_back(root->val);
        help(root->left, level + 1, res);
        help(root->right, level + 1, res);
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        help(root, 0, res);
        return res;
    }
};


// Method 2: Using Queue
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()){
            int len = q.size();
            res.push_back({});
            for (int i = 0; i < len; i++){
                TreeNode* cur = q.front();
                q.pop();
                res.back().push_back(cur->val);
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
        }
        return res;
    }
};


/*
 * LeetCode:
 * 103: Binary Tree Zigzag Level Order Traversal
 *
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        bool if_rev = 0;
        while (!q.empty()){
            int len = q.size();
            res.push_back({});
            for (int i = 0; i < len; i++){
                TreeNode* cur = q.front();
                q.pop();
                if (if_rev){
                    res.back().insert(res.back().begin(), cur->val);
                }
                else
                    res.back().push_back(cur->val);
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            if_rev = !if_rev;
        }
        return res;
    }
};