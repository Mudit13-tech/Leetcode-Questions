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
    ListNode* deleteMiddle(ListNode* head) {
        int count = 0;
        int val = 0;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* temp = head;
        if(head->next == NULL || head == NULL){
            return NULL;
        }
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            count++;
        }
        while(val != count-1){
            temp = temp->next;
            val++;
        }
        temp->next = temp->next->next;
        return head;    
    }
};