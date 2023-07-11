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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode;
        ListNode* ptr = head;

        int carry = 0;

        while (l1 and l2) {
            int val = l1->val + l2->val + carry;

            carry = val / 10;
            ptr->val = val % 10;

            if (l1->next or l2->next or carry) {
                ptr->next = new ListNode;
                ptr = ptr->next;
            }
            
            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1) {
            int val = l1->val + carry;

            carry = val / 10;
            ptr->val = val % 10;

            if (l1->next or carry) {
                ptr->next = new ListNode;
                ptr = ptr->next;
            }

            l1 = l1->next;
        }

        while (l2) {
            int val = l2->val + carry;

            carry = val / 10;
            ptr->val = val % 10;

            if (l2->next or carry) {
                ptr->next = new ListNode;
                ptr = ptr->next;
            }

            l2 = l2->next;
        }

        if (carry) {
            ptr->val = carry;
        }

    
        return head;
    }
};