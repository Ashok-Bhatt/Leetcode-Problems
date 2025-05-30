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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *current = head;
        while (current){
            ListNode *forward = current->next;
            while (forward && current->val==forward->val){
                current->next = forward->next;
                forward->next = NULL;
                delete forward;
                forward = current->next;
            }
            current = forward;
        }
        
        return head;
    }
};