class Solution {
public:
    ListNode* reverseList(ListNode* head) {
       if(head==NULL)
           return head;
        ListNode *pre,*cur;
        pre=head;
        while(pre->next)
        {
            cur=pre->next;
            pre->next=cur->next;
            cur->next=head;
            head=cur;
        }
        return head;
    }
};
