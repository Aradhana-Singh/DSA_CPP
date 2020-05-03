//Given a linked list, remove the n-th node from the end of list and return its head.

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* firstPtr = head;
        for(int i=0 ; i<n; i++){
            firstPtr = firstPtr->next;
        }
        if(firstPtr == NULL) {head = head->next; return head;}
        ListNode* secondPtr = head;
        while(firstPtr -> next!=NULL){
            firstPtr = firstPtr->next;
            secondPtr = secondPtr->next;
        }
        secondPtr->next = secondPtr->next->next;
        return head;
    }
};