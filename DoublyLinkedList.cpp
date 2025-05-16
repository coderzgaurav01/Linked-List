#include<bits/stdc++.h>
using namespace std;
class Node{
	public:
		int data;
		Node* prev;
		Node* next;
		
		Node(int data){
			this->data=data;
			this->prev=NULL;
			this->next=NULL;
		}
};
void InsertAtHead(Node* &head,int d){
	Node* temp = new Node(d);
	head->prev=temp;
	temp->prev = NULL;
	temp->next = head;
	head=temp;
}
void InsertAtTail(Node* &tail,int d){
	Node* temp=new Node(d);
	temp->prev=tail;
	tail->next=temp;
	tail=tail->next;
}
void InsertAtPosition(Node* &head,Node* &tail,int position,int d){
	if(position==1){
		InsertAtHead(head,d);
		return;
	}
	Node*temp=head;
	int cnt=1;
	while(cnt<position){
		temp=temp->next;
		cnt++;
	}
	if(temp->next==NULL){
		InsertAtTail(tail,d);
	}
	Node* nodetoinsert=new Node(d);
	nodetoinsert->next=temp->next;
	temp->next->prev=nodetoinsert;
	nodetoinsert->prev=temp;
	temp->next=nodetoinsert;
}
void Print(Node* &head){
	Node* temp=head;
	while(temp !=NULL){
		cout<<temp->data<<"->";
		temp=temp->next;
	}
	cout<<endl;
}
int getlength(Node* &head){
	int length=0;
	Node* temp =head;
	while(temp!=NULL){
		length++;
		temp=temp->next;
	}
	return length;
}
int main(){
	Node* head = new Node(20);
	Node* tail=head;
	Print(head);
	InsertAtHead(head,50);
	Print(head);
	InsertAtHead(head,60);
	Print(head);
	InsertAtTail(tail,10);
	Print(head);
	InsertAtPosition(head,tail,2,30);
	Print(head);
	InsertAtPosition(head,tail,2,40);
	Print(head);
	cout<<"Head:-"<<head->data<<endl;
	cout<<"Tail:-"<<tail->data<<endl;
	cout<<"Length Of Linked List: "<<getlength(head);
}
