/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        stack<Node*> stk;
        Node* temp = head;
        Node* curr = temp;
        while(temp) {
            if(temp -> next == NULL) {
                if(!stk.empty()) {
                    Node* tp = stk.top();
                    temp -> next = tp;
                    tp -> prev = temp;
                    stk.pop();
                }
            }
            if(temp -> child) {
                if(temp -> next) {
                    stk.push(temp -> next);
                    temp -> next -> prev = NULL;
                }
                temp -> next = temp -> child;
                temp -> child -> prev = temp;
                temp -> child = NULL;
            }
            temp = temp -> next;
        }
        return curr;
    }
};
