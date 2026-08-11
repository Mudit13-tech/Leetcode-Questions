/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = head;
        stack<int> stck;
        while(temp != NULL){
            stck.push(temp->val);
            temp = temp->next;
        }
        temp = head;
        while(temp != NULL){
            temp->val = stck.top();
            stck.pop();
            temp = temp->next;
        }
        return head;
    }
};