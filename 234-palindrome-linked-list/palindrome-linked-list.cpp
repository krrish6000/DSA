class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next && fast->next->next) {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* prev=nullptr;
        ListNode* curr=slow->next;
        while(curr) {
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        ListNode* secondhead=prev;
        ListNode* c1=head;
        ListNode* c2=secondhead;
        bool result=true;
        while(c2) {
            if(c1->val !=c2->val) {
                result=false;
                break;
            }
            c1=c1->next;
            c2=c2->next;
        }
        return result;
    }
};