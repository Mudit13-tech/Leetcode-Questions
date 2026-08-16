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
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* pre = nullptr;
        ListNode* nxt = nullptr;
        while(slow != nullptr){
            nxt = slow->next;
            slow->next = pre;
            pre = slow;
            slow = nxt;
        }

        while(pre != nullptr){
            if(pre->val != head->val){
                return false;
            }
            pre = pre->next;
            head = head->next;
        }
        return true;
        
    }
};