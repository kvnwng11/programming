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
    ListNode *conquer(ListNode* left, ListNode* right) {
        ListNode *to_delete = new ListNode(0);
        ListNode *dummy = to_delete;
        while (left and right) {
            if (left->val < right->val) {
                dummy->next = new ListNode(left->val);
                left = left->next;
            }
            else {
                dummy->next = new ListNode(right->val);
                right = right->next;
            }
            dummy = dummy->next;
        }

        if (left) dummy->next = left;
        else if (right) dummy->next = right;

        dummy = to_delete->next;
        delete to_delete;
        return dummy;
    }

    ListNode* divide(vector<ListNode*>& lists, int start, int end) {
        // One linked list
        if (start+1 == end) {
            return lists[start];
        }
        // Two linked lists
        else if (start+2 == end) {
            return conquer(lists[start], lists[start+1]);
        }
        else {
            int mid = start + (end-start)/2;
            ListNode* left = divide(lists, start, mid);
            ListNode* right = divide(lists, mid, end);
            return conquer(left, right);
        }
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0)
            return nullptr;
        if (lists.size() == 1)
            return lists[0];
        return divide(lists, 0, lists.size());
    }
};