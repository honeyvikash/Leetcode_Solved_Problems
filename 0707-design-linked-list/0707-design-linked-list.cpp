class MyLinkedList {
public:
    int data, size;
    MyLinkedList* next;
    MyLinkedList* head;
    MyLinkedList* tail;
    MyLinkedList(): next(nullptr), head(nullptr), tail(nullptr), data(0), size(0) {}
    
    int get(int index) 
    {
        if (index>=size||index<0)
            return -1;
        if(index==0)
            return head->data;
        MyLinkedList* temp=head;
        for (int i=0;i<index;i++)
        {
            temp=temp->next;
        }
        return temp->data;
    }
    
    void addAtHead(int val) {
        MyLinkedList* temp= new MyLinkedList();
        temp->data=val;
        temp->next=head;
        head=temp;
        size+=1;
    }
    
    void addAtTail(int val) 
    {
        MyLinkedList* temp= new MyLinkedList();
        temp->data=val;
        temp->next=nullptr;
        if(head)
        {
            MyLinkedList* curr = head;
            while(curr->next)
            {
                curr=curr->next;
            }
            curr->next=temp;
        }
        else
        {
            head=temp;
            tail=temp;
        }
        size+=1;
    }
    
    void addAtIndex(int index, int val) 
    {
        if(index>size||index<0)
            return;
        if(index==0){
            addAtHead(val);
            return;
        }
        if(index==size)
        {
            addAtTail(val);
            return;
        }
        MyLinkedList* temp= new MyLinkedList();
        temp->data=val;
        MyLinkedList* curr=head;
        for(int i=0;i<index-1;i++)
        {
            curr=curr->next;
        }
        temp->next=curr->next;
        curr->next=temp;
        size+=1;
    }
    
    void deleteAtIndex(int index) 
    {
        if(index>=size||index<0)
            return;
        MyLinkedList* curr=head;
        if(index==0)
        {
            head=curr->next;
            delete curr;
            size-=1;
            if (!head) 
            {
                tail = nullptr;
            }

            return;
        }
        for(int i=0;i<index-1;i++)
        {
            curr=curr->next;
        }
        MyLinkedList* temp=curr->next;
        curr->next=temp->next;
        delete temp;
        size--;
        if (index == size) 
        {
            tail = curr;
        }
    }
};