class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      if(head==NULL || head->next == NULL)
      {
          return NULL;       
      }
        int len = 0 ;
        ListNode*temp = head ; 
        while(temp)
        {
            len++ ;
            temp=temp->next;
        }
        int trav = len-n+1 ; 
        if(trav==1)
        {
            head=head->next;
            return head;
        }
        int cnt=2;
        temp = head ; 
        while(temp and cnt<trav)
        {  temp=temp->next;
            cnt++;
        }

     if(temp->next!=NULL)   temp->next = temp->next->next ; 
        return head ;   
    }
};