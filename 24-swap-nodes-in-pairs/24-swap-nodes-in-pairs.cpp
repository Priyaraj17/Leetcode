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
    ListNode* swapPairs(ListNode* head) {
        if(!head or !head->next) 
            return head;
        bool flag = true;
        ListNode *curr = head, *prev = nullptr;
        while(curr and curr->next) {
            ListNode *nxtPair = curr->next, *secPair = curr->next->next;
            nxtPair->next = curr;
            curr->next = secPair;
            if(flag) {
                head = nxtPair;
                flag = false;
            }
            if(prev) prev->next = nxtPair;
            prev = curr;
            curr = secPair;
        }
        return head;
    }
};