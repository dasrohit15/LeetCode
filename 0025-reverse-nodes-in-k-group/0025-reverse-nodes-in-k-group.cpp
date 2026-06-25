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
    ListNode* findkth(ListNode* temp, int k){
        while(temp!=NULL && k>1){
            k--;
            temp = temp->next;
        }
        return temp;
    }

    ListNode* reverseLL(ListNode* head){
        ListNode* temp =head;
        ListNode* prev = NULL;
        while(temp != NULL){
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prev = NULL;
        while(temp != NULL){
            ListNode* kNode = findkth(temp,k);
            if(kNode == NULL){
                if(prev) prev->next = temp;
                break;
            }
            ListNode* nextNode = kNode->next;
            kNode->next = NULL;
            reverseLL(temp);
            if(head == temp){
                head = kNode;
            }else{
                prev->next = kNode;
            }
            prev = temp;
            temp = nextNode;
        }
        return head;
    }
};