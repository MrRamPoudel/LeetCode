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
/*
Basically build a minheap with all the character and merge with heapify
*/
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
       if (lists.empty()) {
        return nullptr;
    }
    
    auto func = [](const ListNode* l1, const ListNode* l2) {
        return l1->val > l2->val;
    };

    priority_queue<ListNode*, vector<ListNode*>, decltype(func)> pq(func);

    // Build heap
    for (int i = 0; i < lists.size(); ++i) {
        // Iterate through each of the lists and add its elements to the heap
        ListNode* head = lists[i];
        while (head) {
            pq.push(head);
            head = head->next;
        }
    }

    // Create a new list by appending each pointer to the list
    ListNode* dummy = new ListNode();
    ListNode* temp = dummy;
    while (pq.size() > 0) {
        ListNode* temp2 = pq.top();
        pq.pop();
        temp->next = temp2;
        temp = temp->next;
    }
    temp->next = nullptr;
    ListNode* result = dummy->next;
    delete dummy; 
    return result;
    }
};

