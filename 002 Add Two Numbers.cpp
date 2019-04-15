/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL)
            return l2;
        if(l2 == NULL)
            return l1;
        ListNode *Head = new ListNode(-1);
        Head->next = NULL;
        int sum = 0, carry = 0;
        while(!l1 && !l2){
            sum = l1->val + l2->val + carry;
            l1 = l1->next;
            l2 = l2->next;
            carry = sum / 10;
            sum %= 10;
            ListNode *tmp = new ListNode(sum);
            tmp->next = Head->next;
            Head->next = tmp;
        }
        while( !l1  ){
            sum = l1->val + carry;
            l1 = l1->next;
            carry = sum / 10;
            sum %= 10;
            ListNode *tmp = new ListNode(sum);
            tmp->next = Head->next;
            Head->next = tmp;
        }
        while(!stack2.empty()){
            sum = stack2.top()->val + carry;
            stack2.pop();
            carry = sum / 10;
            sum %= 10;
            ListNode *tmp = new ListNode(sum);
            tmp->next = Head->next;
            Head->next = tmp;
        }
        return Head->next;
    }
};