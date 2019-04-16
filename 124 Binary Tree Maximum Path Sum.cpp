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
    int maxPathDown(TreeNode *root){
        if(!root)
            return 0;
        int left = max(0, maxPathDown(root->left));
        int right = max(0, maxPathDown(root->right));
        maxSum = max(maxSum, left + right + root->val);
        return root->val + max(left, right);
    }
    
    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        maxPathDown(root);
        return maxSum;
    }
private:
    int maxSum;
};