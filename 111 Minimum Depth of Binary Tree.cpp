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
    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        stack<pair<TreeNode*,int>> stack;
        stack.push({root,1});
        int result = INT_MAX;
        while(!stack.empty()){
            TreeNode *cur = stack.top().first;
            int depth = stack.top().second;
            stack.pop();
            if(cur->left == NULL && cur->right == NULL)
                result = min(depth, result);
            if(cur->left && result > depth)
                stack.push({cur->left, depth+1});
            if(cur->right && result > depth)
                stack.push({cur->right, depth+1});
        }
        return result;
    }
};