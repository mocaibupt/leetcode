/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL)
            return NULL;
        Node *pre= NULL, *cur;
        int pre_level = -1, cur_level;
        queue<pair<Node *, int>> que;
        que.push({root,0});
        while(!que.empty()){
            cur = que.front().first;
            cur_level = que.front().second;
            que.pop();
            if(cur_level == pre_level)
                pre->next = cur;
            
            if(cur->left)
                que.push({cur->left, cur_level+1});
            if(cur->right)
                que.push({cur->right, cur_level+1});
            
            pre_level = cur_level;
            pre = cur;
        }
        return root;
    }
	
	Node* connect(Node* root) {
        if(root == NULL)
            return root;
        Node *cur = NULL, *pre = root, *first, *Head = new Node(0);
        while(pre){
            cur = pre;
            while(cur && !cur->left && !cur->right)
                cur = cur->next;
            if(!cur)
                break;
            pre = cur->left ? cur->left : cur->right;
            first = Head;
            while(cur){
                if(cur->left){
                    first->next = cur->left;
                    first = first->next;
                }
                if(cur->right){
                    first->next = cur->right;
                    first = first->next;
                }
                cur = cur->next;
            }
        }
        return root;
    }
};

