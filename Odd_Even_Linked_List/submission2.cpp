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
    ListNode* oddEvenList(ListNode* head) {
        
        ListNode *odd = NULL, *even = NULL, *oddHead = NULL, *evenHead = NULL, *current = head;
        bool isOdd = true;
        
        while (current){
            ListNode* forward = current->next;
            if (isOdd){
                if (!odd){
                    odd = oddHead = current;
                } else {
                    odd->next = current;
                    odd = odd->next;
                }
                odd->next = NULL;
            } else {
                if (!even){
                    even = evenHead = current;
                } else {
                    even->next = current;
                    even = even->next;
                }
                even->next = NULL;
            }

            current = forward;
            isOdd = !isOdd;
        }

        if (odd){
            odd->next = evenHead;
        }
        return oddHead;
    }
};