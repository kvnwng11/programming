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
    ListNode* getMid(ListNode* head) {
        ListNode* midPrev = nullptr;
        while (head and head->next) {
            midPrev = (midPrev == nullptr)? head: midPrev->next;
            head = head->next->next;
        }
        ListNode* mid = midPrev->next;
        midPrev->next = nullptr;
        return mid;
    }

    ListNode* divide(ListNode* node) {
        if (!node or !node->next)
            return node;

        ListNode* tmp = getMid(node);
        ListNode* left = divide(node);
        ListNode* right = divide(tmp);

        return conquer(left, right);
    }


    ListNode* conquer(ListNode* node1, ListNode* node2) {
        if (!node1)
            return node2;
        if (!node2)
            return node1;

        if (node1 == node2)
            return node1;

        ListNode *dummy = new ListNode(0);
        ListNode* to_delete = dummy;
        while (node1 and node2) {
            if (node1->val < node2->val) {
                dummy->next = new ListNode(node1->val);
                node1 = node1->next;
            }
            else {
                dummy->next = new ListNode(node2->val);
                node2 = node2->next;
            }
            dummy = dummy->next;
        }

        if (node1) dummy->next = node1;
        else if (node2) dummy->next = node2;

        // Memory management
        dummy = to_delete->next;
        delete to_delete;

        cout << dummy->val << endl;

        return dummy;
    }


    ListNode* sortList(ListNode* head) {
        return divide(head);
    }
};