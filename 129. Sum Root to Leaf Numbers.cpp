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
    void sumNumbers(TreeNode* root, int res) {
        int tmp = res*10 + root->val;
        if(!root->left && !root->right){
            sum += tmp;
            return;    
        }
        if(root->left)
            sumNumbers(root->left, tmp);
        if(root->right)
            sumNumbers(root->right, tmp);
    }
    int sumNumbers(TreeNode* root) {
        if(!root)
            return 0;
        sumNumbers(root, 0);
        return  sum;
    }
private:
    int sum;
};