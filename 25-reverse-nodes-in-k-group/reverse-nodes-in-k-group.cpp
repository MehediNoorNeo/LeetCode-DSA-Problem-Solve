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
    ListNode* reverseList(ListNode* head, ListNode* tail){
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;
 
        while(curr != tail){
            next = curr->next;
            curr->next = prev;
            prev = curr; 
            curr = next;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        int i=0;
        while(i != k){
            if(temp == NULL) return head;
            temp = temp->next;
            i++;
        }
        ListNode* revHead = reverseList(head, temp);
        ListNode* revTemp = revHead;
        while(revTemp->next != NULL){
            revTemp = revTemp->next;
        }
        revTemp->next = reverseKGroup(temp, k);
        return revHead;
    }
};