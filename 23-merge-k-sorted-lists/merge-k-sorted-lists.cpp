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

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        int k = lists.size();
        cout<<"list size is "<<k<<"\n";
        for(int i=0; i<k; ++i) {
            if(lists[i] != NULL)
                pq.push({lists[i]->val,i});   
        }

        ListNode* head = new ListNode();
        ListNode* ans = head;

        while(!pq.empty()) {
            
            int idx = pq.top().second;
            cout<<"idx is "<<idx<<"\n";

            head->next = lists[idx];
            head = head->next;
            lists[idx] = lists[idx]->next;

            pq.pop();

            if(lists[idx] != NULL)
                pq.push({lists[idx]->val, idx});
            
        }

        return ans->next;
        
    }
};