#include<bits/stdc++.h>
using namespace std;
class Node{
	public:
		int data;
		Node* next;
		
		Node(int data){
			this->data=data;
			this->next=NULL;
		}
};
void InsertAtHead(Node* &head,int d){
	Node* temp =new Node(d);
	temp->next=head;
	head=temp;
}
void insertAtTail(Node* &tail,int d){
	Node* temp=new Node(d);
	tail->next=temp;
	temp=tail;
}
void Print(Node* &head){
	Node* temp =head;
	while(temp!=NULL){
		cout<<temp->data<<"->";
		temp=temp->next;
	}
	cout<<endl;
}
int main(){
	Node* head = new Node(10);
	Node* tail=head;
	InsertAtHead(head,20);
	insertAtTail(tail,5);
	Print(head);
}
