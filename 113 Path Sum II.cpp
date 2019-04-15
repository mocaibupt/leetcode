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
    void pathSum(vector<vector<int>> &res, vector<int> &vec, TreeNode* root, int sum){
        
        vec.push_back(root->val);
        if(root->left == NULL && root->right == NULL && root->val == sum){
            res.push_back(vec);
        }
        if(root->left)
            pathSum(res, vec, root->left, sum - root->val);
        
        if(root->right)
            pathSum(res, vec, root->right, sum - root->val);
        
        vec.pop_back();
        return ;
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        if(root == NULL)
            return res;
        vector<int> vec;
        pathSum(res, vec, root, sum);
        return res;
    }
};