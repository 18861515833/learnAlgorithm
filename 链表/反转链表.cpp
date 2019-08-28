//思路：利用链表的插入删除效率，采用一次遍历的方式，每次把当前节点插入到链表头部 
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
