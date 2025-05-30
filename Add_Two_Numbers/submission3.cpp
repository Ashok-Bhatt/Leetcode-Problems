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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* head = new ListNode(0);
        ListNode* temp = head;
        int carry = 0;

        while (l1!=NULL || l2!=NULL || carry!=0){

            ListNode* nodeToInsert = new ListNode(0);
            int value = carry;

            if (l1!=NULL){
                value = value + l1->val;
                l1 = l1->next;
            }
            if (l2!=NULL){
                value = value + l2->val;
                l2 = l2->next;
            }

            nodeToInsert->val = value%10;
            carry = value/10;
            temp->next = nodeToInsert;
            temp = temp->next;
        }

        ListNode* newhead = head->next;
        head->next = NULL;
        delete head;

        return newhead;
    }
};