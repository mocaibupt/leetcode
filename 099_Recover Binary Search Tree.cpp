// leetcode 99题 
// Two elements of a binary search tree (BST) are swapped by mistake.
// Recover the tree without changing its structure.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
//Morris Traversal or Morris Threading Traversal. explain: http://www.cnblogs.com/AnnieKim/archive/2013/06/15/morristraversal.html
//每个具有左儿子的节点(cur)都会去搜索其左儿子的最右叶子
//第一次将左儿子的最右叶子的右指针指向当前节点(cur)，然后指向左儿子
//当cur的左子树遍历结束后，cur回到根节点，此时再次搜索其左儿子的最右叶子
//将左儿子的最右叶子的右指针释放，然后遍历右子树
class Solution {
public:
    void recoverTree(TreeNode* root) {
        //pre指向未错误树中小于cur的最大值的节点
        TreeNode *cur = root, *pre = NULL;
        TreeNode *first = NULL, *second = NULL;
        TreeNode *tmp = NULL;
        while(cur != NULL ){
            if(cur->left != NULL){
                tmp = cur->left;
                while(tmp->right != NULL && tmp->right != cur)
                    tmp = tmp->right;
                if(tmp->right != NULL){
                    if(pre != NULL && pre->val > cur->val){
                        if(first == NULL){
                            first = pre;
                            second = cur;
                        }
                        else
                            second = cur;
                        cout << "first:" << first->val << "  second:" << second->val << endl;
                    }
                    pre = cur;
                    tmp->right = NULL;
                    cur = cur->right;
                }
                else{
                    tmp->right = cur;
                    cur = cur->left;
                }
            }
            else{
                if(pre != NULL&& pre->val > cur->val){
                    if(first == NULL){
                        first = pre;
                        second = cur;
                    }
                    else
                        second = cur;
                    cout << "first:" << first->val << "  second:" << second->val << endl;
                }
                pre = cur;
                cur = cur->right;
            }
        }
        if(first && second){
            int i = first->val;
            first->val = second->val;
            second->val = i;
        }
        return ;
    }
};