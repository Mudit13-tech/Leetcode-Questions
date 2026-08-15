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
    bool isPalindrome(ListNode* head) {
        stack<int>stck;
        ListNode* temp = head;
        int count = 0;
        while(temp != nullptr){
            stck.push(temp->val);
            temp = temp->next;
            count++;
        }
        ListNode* head2 = new ListNode(stck.top());
        stck.pop();
        ListNode* temp2 = head2;
        while (!stck.empty()) {
            temp2->next = new ListNode(stck.top());
            stck.pop();
            temp2 = temp2->next;
        }   
        while(head != nullptr && head2 != nullptr){
            if(head->val != head2->val){
                return false;
            }
            head = head->next;
            head2 = head2->next;
        }
        return true;       
    }
};