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
    void flatten(TreeNode* root) {
        if(root == NULL)
            return ;
        flatten(root->right);
        flatten(root->left);
        
        root->right = Head;
        root->left = NULL;
        Head = root;
    }
private:
    TreeNode *Head = NULL;
};

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
    void flatten(TreeNode* root) {
        TreeNode *cur = root, *tmp;
        while(cur){
            if(cur->left){
                tmp = cur->left;
                while(tmp->right)
                    tmp = tmp->right;
                tmp->right = cur->right;
                cur->right = cur->left;
                cur->left = NULL;
            }
            else{
                cur = cur->right;
            }
        }
        return ;
    }
};