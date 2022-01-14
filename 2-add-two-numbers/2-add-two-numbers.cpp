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
        int sum = 0, carry = 0;
        ListNode *newHead = nullptr, *newTail = nullptr;
        while(l1 and l2) {
            sum = l1->val + l2->val + carry;
            ListNode *node = new ListNode(sum % 10);
            if(!newHead) {
                newHead = node;
                newTail = node;
            } else {
                newTail->next = node;
                newTail = node;
            }
            if(sum > 9) carry = 1;
            else carry = 0;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1) {
            sum = l1->val + carry;
            ListNode *node = new ListNode(sum % 10);
            if(!newHead) {
                newHead = node;
                newTail = node;
            } else {
                newTail->next = node;
                newTail = node;
            }
            if(sum > 9) carry = 1;
            else carry = 0;
            l1 = l1->next;
        }
        while(l2) {
            sum = l2->val + carry;
            ListNode *node = new ListNode(sum % 10);
            if(!newHead) {
                newHead = node;
                newTail = node;
            } else {
                newTail->next = node;
                newTail = node;
            }
            if(sum > 9) carry = 1;
            else carry = 0;
            l2 = l2->next;
        }
        if(carry==1) newTail->next = new ListNode(1);
        return newHead;
    }
};