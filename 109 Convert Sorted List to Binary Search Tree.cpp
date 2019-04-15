/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedArrayToBST(vector<int>& nums,int start, int end) {
        if(start == end)
            return new TreeNode(nums[start]);
        if(start > end)
            return NULL;
        int mid = start + (end - start)/2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = sortedArrayToBST(nums, start, mid-1);
        root->right = sortedArrayToBST(nums, mid+1, end);
        return root;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL)
            return NULL;
        if(head->next == NULL)
            return new TreeNode(head->val);
        vector<int> nums;
        ListNode *cur = head;
        while(cur){
            nums.push_back(cur->val);
            cur = cur->next;
        }
        return sortedArrayToBST(nums, 0, nums.size()-1);
    }
};