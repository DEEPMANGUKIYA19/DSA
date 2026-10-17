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
class Solution
 {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        priority_queue<ListNode*, vector<ListNode*>,
        decltype([](ListNode* a, ListNode* b) 
        
        {
            return a->val > b->val;
        })> pq;

        for (auto list : lists)
         {
            if (list != nullptr) 
            {
                pq.push(list);
            }
        }

        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        while (!pq.empty()) 
        
        {
            ListNode* node = pq.top();
            pq.pop();

            tail->next = node;
            tail = tail->next;


            if (node->next != nullptr) 
            {
                pq.push(node->next);
            }
        }

        tail->next = nullptr;
        return dummy->next;
    }
};