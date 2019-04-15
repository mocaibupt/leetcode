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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL)
            return res;
        queue<pair<TreeNode *, int>> que;
        que.push(pair<TreeNode *, int>(root,0));
        while(!que.empty()){
            TreeNode *cur = que.front().first;
            int level = que.front().second;
            que.pop();
            if(res.size() == level)
                res.push_back(vector<int>{});
            
            res[level].push_back(cur->val);
            if(cur->left != NULL)
                que.push(pair<TreeNode *, int>(cur->left, level+1));
            if(cur->right != NULL)
                que.push(pair<TreeNode *, int>(cur->right, level+1));
        }
        return res;
    }
};