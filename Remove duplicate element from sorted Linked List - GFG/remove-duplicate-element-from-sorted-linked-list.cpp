//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
    cout<<temp->data<<" ";
    temp=temp->next;
    }
}
Node* removeDuplicates(Node *root);
int main() {
	// your code goes here
	int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		Node *head = NULL;
        Node *temp = head;

		for(int i=0;i<K;i++){
		int data;
		cin>>data;
			if(head==NULL)
			head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp=temp->next;
			}
		}
		
		Node *result  = removeDuplicates(head);
		print(result);
		cout<<endl;
	}
	return 0;
}
// } Driver Code Ends


/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};*/

//Function to remove duplicates from sorted linked list.
Node *removeDuplicates(Node *head)
{
    // your code goes here
    // if(head==NULL || head->next==NULL)return head;
    // Node *tmp = head;
    // int prev = head->data;
    // while(tmp->next!=NULL)
    // {
    //     int curr = tmp->next->data;
    //     if(prev==curr)
    //     {
    //       tmp->next = tmp->next->next; 
    //     }
    //     prev = curr;
    //     tmp = tmp ->next;
    // }
    // return head;
    
    if(head == NULL) 
    {
        return NULL;
    }
    
    Node *p = head;
    while(p != NULL && head->data == p->data) 
    {
        p = p->next;
    }
    
    head->next = removeDuplicates(p);
    
    return head;
    
}