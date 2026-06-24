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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //declaring min-heap priority queue
        priority_queue<pair<int , ListNode *>, vector<pair<int , ListNode *>>, greater<pair<int , ListNode *>>> pq;
        ListNode *dummyNode = new ListNode(-1);
        ListNode *temp = dummyNode;
        for(int i = 0; i < lists.size(); i++){
            if(lists[i]) pq.push({lists[i]->val, lists[i]});
        }

        while(! pq.empty()){
            auto curr = pq.top();
            pq.pop();
            temp->next = curr.second;
            temp = temp->next;
            if(curr.second->next){
                pq.push({curr.second->next->val, curr.second->next});
            } 
        }
        return dummyNode->next;
    }
};