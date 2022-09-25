// Name-Keith Swamy
// SID- 21105097
// Branch - ECE

//FAMILY LINKED LIST

#include <iostream>            
using namespace std;                

//creating class node
class Node{
    public:
    string name;
    int age;
    Node*next; //declaration of pointer for next node
    Node*prev; //declaration of pointer for previous node
    //creating constructor
    Node(string name,int age){
        this->name=name;
        this->age=age;
        next=NULL; //initialising next as NULL
        prev=NULL; //initialising prev as NULL
    }
};

//Inserting data at the end
void append(Node* &head,string name,int age){
    //Creating a node pointer and storing address of head in temp
    Node*temp=head;
    //creating a new node and storing name and age in it
    Node* new_node=new Node(name,age)
    if(temp==NULL){
        head=new_node;
    }
    //Inserting node in non empty list
    else{
        while(temp->next!=NULL)
        {
        temp=temp->next;
        }
        temp->next=new_node;
        new_node->prev=temp;
    }
}

//Inserting data at the head
void insert_at_head(Node*&head,string name,int age){
    //Creating a Node pointer and storing address of new node in it 
    Node*new_node=new Node(name,age);
    //Inserting new node at head
    new_node->next=head;
    head->prev=new_node;
    head=new_node;
}

//Displaying data from head to tail
void display_start(Node*head){
    Node*temp=head;
    while(temp!=NULL)
    {
    cout<<"Name:"<<temp->name<<" Age:"<<temp->age<</n;
    temp=temp->next;
    }
    cout<<endl;
}

//Displaying data from tail to head
void display_from_end(Node*head){
    Node*temp=head;
    while(temp->next!=NULL)
    {
    temp=temp->next;
    }
    while (temp!=NULL)
    {
    cout<<"Name:"<<temp->name<<" Age:"<<temp->age<</n;
    temp=temp->prev;
    }
    cout<<endl;
}

//Deleting data from linked list from any index
void delete(Node*&head,int i){
    if(i==0){
        Node*temp=head;
        head=temp->next;
        head->prev=NULL;
        delete temp;
    }
    else{
        Node*temp=head;
        for(int j=0;j<i;j++){temp=temp->next;}
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        delete temp;
    }
}

//Deleting data from last index
void pop(Node*&head){
    Node*temp=head;
    while(temp->next!=NULL)
    {
    temp=temp->next;
    }
    temp->prev->next=NULL;
    delete temp;
}

int main()
{
    //Initialising an empty linked list
    Node*head=NULL;
	  int number; 
    //Taking no of family mem as input
	  cout<<"Enter Number Of Family Members:";
    cin>>number;
    //Inserting family members details in doubly linked list
	for(int i=1;i<=number;i++){
		string name;
		int age;
		cout<<"Enter Family Member "<<i<<" Name:";cin.ignore();getline(cin,name);
		cout<<"Enter Family Member "<<i<<" Age:";cin>>age;
        //appending data name and age in doubly linked list
		append(head,name,age);
	}
    cout<<endl;//For space
    //Displaying Family details
    cout<<"Doubly Linked list with my family members as elements is shown below:"<<endl;
    cout<<endl;
    display_start(head);
}

/*BONUS QUESTION
Q.Try to find a way to link the family members' doubly-linked list based on their relationship.
Ans. We can do such by having the linked list sort in either ascending or descending order by age so that family members come in hierarchical order.*/
