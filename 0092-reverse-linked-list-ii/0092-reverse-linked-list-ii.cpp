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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *temp = head;
        ListNode *prev = NULL;
        int i = 1;
        while(temp != NULL && i != left){
            prev = temp;
            temp = temp->next;
            i++;
        }
        ListNode *startptr = prev;
        ListNode *start = temp;
        prev = NULL;
        while(temp!=NULL && i!=right+1){
            ListNode *front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
            i++;
        }
        start->next = temp;
        if(startptr != NULL){
            startptr->next = prev;
        }else{
            return prev;
        }
        return head;
    }
};