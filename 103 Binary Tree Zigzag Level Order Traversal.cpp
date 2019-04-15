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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL)
            return res;
        queue<TreeNode*> que;
        TreeNode *cur;
        que.push(root);
        bool leftToRight = true;
        while(!que.empty()){
            int size = que.size();
            vector<int> veci(size,0);
            for(int i = 0; i < size; i++){
                cur = que.front();
                que.pop();
                int index = leftToRight ? i : size -i - 1;
                veci[index] = cur->val;
                if(cur->left)
                    que.push(cur->left);
                if(cur->right)
                    que.push(cur->right);
            }
            leftToRight ^= true;
            res.push_back(veci);
        }
        return res;
    }
};