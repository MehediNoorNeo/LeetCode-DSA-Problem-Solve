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
    ListNode* swapNode(ListNode* head){
        ListNode* curr = head;
        ListNode* next = NULL;

        next = curr->next;
        curr->next = NULL;
        next->next = curr;

        return next;
    }
    ListNode* swapPairs(ListNode* head) {
        int k = 2, i = 0;
        ListNode* temp = head;
        while(i < k){
            if(temp == NULL) return head;
            temp = temp->next;
            i++;
        }
        ListNode* swapHead = swapNode(head);
        swapHead->next->next = swapPairs(temp);
        return swapHead;
    }
};