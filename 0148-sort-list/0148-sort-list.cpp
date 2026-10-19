 
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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;

        int n = 0;
        ListNode* curr = head;

        while (curr) {
            n++;
            curr = curr->next;
        }

        ListNode dummy(0);
        
        for (int size = 1; size < n; size *= 2) {
            ListNode* tail = &dummy;
            curr = head;

            while (curr) {
                ListNode* left = curr;
                ListNode* right = split(left, size);
                curr = split(right, size);

                tail->next = merge(left, right);

                while (tail->next) {
                    tail = tail->next;
                }
            }

            head = dummy.next;
        }

        return head;
    }

private:
    ListNode* split(ListNode* head, int size) {
        if (!head) return nullptr;

        for (int i = 1; head->next && i < size; i++) {
            head = head->next;
        }

        ListNode* next = head->next;
        head->next = nullptr;
        return next;
    }

    ListNode* merge(ListNode* a, ListNode* b) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (a && b) {
            if (a->val <= b->val) {
                tail->next = a;
                a = a->next;
            } else {
                tail->next = b;
                b = b->next;
            }
            tail = tail->next;
        }

        tail->next = a ? a : b;
        return dummy.next;
    }
};
