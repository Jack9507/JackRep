#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next=NULL;
};

node* addnode(int x)
{
    node *tmp=new node;
    tmp->data=x;
    tmp->next=NULL;
    return tmp;
}
node* insertathead(node *head, int x)
{
    if(head == NULL)
        return addnode(x);
    node *tmp=addnode(x);
    tmp->next=head;
    head=tmp;
    return head;
}

node *insertAtTail(node *head, int x)
{
    if(head == NULL)
       return addnode(x);

      node *tmp =head;
      while(tmp->next != NULL)
      {
          tmp = tmp->next;
      }
      node *n =addnode(x);
      tmp->next =n;
        //n->next=NULL;
      return head;

}
void display(node *head)
{
    node *tmp=head;
    while(tmp != NULL)
    {
        cout<<tmp->data<<" -> ";
        tmp = tmp->next;
    }
}
node *deleteAthead(node *head)
{
    if(head == NULL)
        return NULL;
    node *tmp =head;
    head = head->next;
    delete tmp;
    return head;
}
node *deleteAtTail(node *head)
{
    if(head == NULL)
        return NULL;
    if(head->next == NULL)
        deleteAthead(head);
    node *tmp =head;
    while(tmp->next->next != NULL)
        tmp = tmp->next;
    node *n=tmp->next;
    tmp->next = NULL;
    delete n;
    return head;
}
int length(node *head)
{
    if(head == NULL)
        return 0;
    node *tmp =head;
    int cnt=0;
    while(tmp != NULL)
    {
        cnt++;
        tmp= tmp->next;
    }
    return cnt;
}

bool searchlinklist(node *head , int val)
{
    if(head == NULL)
        return false;
    node *tmp=head;
    while(tmp != NULL)
    {
        if(tmp->data == val)
            return true;
        tmp =tmp->next;
    }

    return false;
}

node *insertAtIndex(node *head, int x, int idx)
{
    if(idx<=1 || head == NULL)
    {
        return insertathead(head, x);
    }
    if(idx> length(head))
      return insertAtTail(head,x);

    node *tmp=head;
    int jump =idx-2;
    while(jump!=0)
    {
        tmp=tmp->next;
        jump--;
    }

    node *n=addnode(x);
    n->next = tmp->next;
    tmp->next=n;
    return head;
}

node *deleteAtIndex(node *head, int idx)
{
    if(idx<=1 || head->next == NULL)
        return deleteAthead(head);
    if(idx == length(head))
        return deleteAtTail(head);

    node *tmp=head;
    int jump=idx-2;
    while(jump!=0)
    {
        tmp=tmp->next;
        jump--;
    }
    node *nq= tmp->next;
    tmp->next = tmp->next->next;
    delete nq;

    return head;
}
node *midPoint(node *head)
{
    node *slow=head;
    node *fast=head;

    if(head != NULL)
    {
        while(fast != NULL && fast->next != NULL)
        {
            slow =slow->next;
            fast =fast->next->next;
        }
    }
    return slow;
}

node*  reverseRecursive(node *head)
{
    if(head == NULL || head->next == NULL)
        return head;
    node *tmp = reverseRecursive(head->next);

    node *curr =head;
    curr->next->next =curr;
    curr->next =NULL;
    return tmp;
}

node* reverseIterative(node *head)
{
    node *prev=NULL;
    node *curr=head;

    node *tmp =curr->next;
    curr->next =prev;
    prev = curr;
    curr = tmp;

    return prev;
}
int main()
{
    node *head1=new node;
    head1=NULL;

    //list1
   head1= insertathead(head1, 1);
   head1= insertathead(head1, 2);
   head1= insertathead(head1, 3);
   head1= insertathead(head1, 4);
   head1= insertathead(head1, 5);

    display(head1);
    cout<<endl;

    node *head2=new node;
    head2=NULL;
    //list2
    head2= insertathead(head2, 5);
    head2= insertathead(head2, 4);
    head2= insertathead(head2, 3);
    head2= insertathead(head2, 2);
    head2= insertathead(head2, 1);

    //display
    display(head2);
    cout<<endl;

    node *head3 =new node;
    head3= NULL;

    head3=insertAtTail(head3, 5);
    head3=insertAtTail(head3, 6);
    head3=insertAtTail(head3, 7);
    head3=insertAtTail(head3, 8);
    head3=insertAtTail(head3, 9);
    head3=insertAtTail(head3, 10);
    head3=insertAtTail(head3, 11);

    display(head3);
    cout<<endl;
    head3=deleteAthead(head3);
    display(head3);
    cout<<endl;
    head3=deleteAtTail(head3);
    display(head3);
    cout<<endl;
    cout<<"length of linked list = "<<length(head3)<<endl;
   cout<<searchlinklist(head3,5);
    cout<<endl;
   head3 = insertAtIndex(head3, 69, 5);
   display(head3);
   cout<<endl;
   head3 = deleteAtIndex(head3, 5);
   display(head3);
   cout<<endl;
   cout<<"mid point of link list = ";
   node *tmp=midPoint(head3);
   cout<<tmp->data<<endl;

   ///////////////////////////////////

   cout<<"Reverse of linked list recursively = "<<endl;
   head3=reverseRecursive(head3);
   display(head3);
   cout<<endl;
   cout<<"Reverse of linked list iteratively = "<<endl;
   head3=reverseRecursive(head3);
   display(head3);
   cout<<endl;








}
