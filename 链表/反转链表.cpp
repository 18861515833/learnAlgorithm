//˼·����������Ĳ���ɾ��Ч�ʣ�����һ�α����ķ�ʽ��ÿ�ΰѵ�ǰ�ڵ���뵽����ͷ�� 
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
