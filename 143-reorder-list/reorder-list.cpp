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
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* prev = nullptr; 
        ListNode* curr = slow->next;
        slow->next = nullptr; 
        while (curr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        ListNode* c1 = head;
        ListNode* c2 = prev;
        ListNode* temp;
        while (c2) {
            temp = c1->next;
            c1->next = c2;
            c1 = temp;
            temp = c2->next;
            c2->next = c1;
            c2 = temp;
        }
    }
};