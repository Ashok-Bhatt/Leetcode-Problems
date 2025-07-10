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
        ListNode *oddHead = head, *evenHead = (head) ? head->next : NULL;
        ListNode *oddTail = head, *evenTail = (head) ? head->next : NULL;
        ListNode *current = head;
        int index = 0;

        while (current){
            ListNode* forward = current->next;
            if (index%2==0){
                ListNode* nextNode = current->next;
                if (nextNode) nextNode = nextNode->next;
                oddTail->next = nextNode;
                if (nextNode) oddTail = nextNode;
            } else {
                ListNode* nextNode = current->next;
                if (nextNode) nextNode = nextNode->next;
                evenTail->next = nextNode;
                if (nextNode) evenTail = nextNode;
            }
            current = forward;
            index++;
        }

        if (oddTail) oddTail->next = evenHead; 
        return oddHead;
    }
};