/*Keith Swamy
  21105097
  ECE */

// Question.1- While traversing a single-circular linked list, which condition establishes that the traversing element/variable has reached the first element? 

//Answer 1-
//Beginning by creating a Code to create a circular linked list
#include <iostream>
using namespace std;
//Node class created
class Node{
    public:
    int input;
    Node*next;
    //Making Node class constructor
    Node(int input){
        this->input=input;
        next=NULL;
    }
}
//Inserting a node at end on linked list
void append(Node*&head,int input){
    Node*temp=head;
    Node*new_node=new Node(input);
    if(temp==NULL)
    {
      head=new_node;
      new_node->next=head;
      return;
    }
    while(temp->next!=head)   //This condition establishes that the traversing element(temp) has reached the first element
    {
      temp=temp->next;
    }  
    temp->next=new_node;
    new_node->next=head;
}
//Printing elements of linked list from head to the last node.
void print(Node*&head){
    Node*temp=head;
    do
    {
      cout<<temp->data<<" ";
      temp=temp->next;
    }
    while(temp!=head);
}

int main(){
    Node*head=NULL;
    append(head,34);
    append(head,1);
    append(head,5);
    print(head);
}
/*
Here in the above written code, line 31 establishes that the traversing element/variable has reached the first element.
We Know that in circular linked list last node of linked list points to head of that linked list, hence we can check if any node points to head of linked list then that node is the end of circular linked list.
*/


/*Question.2  What are the practical applications of a circular linked list? (Try to find applications in your respective fields).

Answer 2- A Circular Linked List can be used for the following –

1.Circular lists are used in applications where the entire list is accessed one-by-one in a loop.
2.It is also used by the Operating system to share time for different users, generally uses a Round-Robin time-sharing mechanism.
3.Multiplayer games use a circular list to swap between players in a loop.
4.Implementation of Advanced data structures like Fibonacci Heap
5.The browser cache which allows you to hit the BACK button
6.Undo functionality in Photoshop or Word
7.Circular linked lists are used in Round Robin Scheduling
8.Circular linked list used Most recent list (MRU LIST) */
