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
		~Node(){
			int value=this->data;
			if(this->next !=NULL){
				delete next;
				this->next = NULL;
			}
			cout<<"Memory is free for node with data"<<value<<endl;
		}
};
void InsertAtHead(Node* &head,int d){
	Node* temp = new Node(d);
	temp->next=head;
	head=temp;
}
void InsertAtTail(Node* &tail,int d){
	Node* temp=new Node(d);
	tail->next=temp;
	tail=tail->next;
}
void InsertAtPosition(Node* &head,Node* &tail,int position,int d){
	if(position==1){
		InsertAtHead(head,d);
		return;
	}
	
	Node* temp=head;
	int cnt=1;
	while(cnt<position-1){
		temp=temp->next;
		cnt++;
	}
	if(temp->next==NULL){
		InsertAtTail(tail,d);
		return;
	}
	Node* nodeToInsert = new Node(d);
	nodeToInsert->next=temp->next;
	temp->next=nodeToInsert;
}

void DeleteAtPosition(int position,Node* &head){
	if(position==1){
		Node* temp=head;
		head=head->next;
		temp->next=NULL;
		delete temp;
	}
	else{
		
		Node* curr =head;
		Node* prev=NULL;
		int cnt=1;
		while(cnt<position){
			prev=curr;
			curr=curr->next;
			cnt++;
		}	
		prev->next=curr->next;
		curr->next=NULL;
		delete curr;
	}
}
void Print(Node* &head){
	Node* temp=head;
	while(temp!=NULL){
		cout<<temp->data<<"->";
		temp=temp->next;
		
	}
	cout<<endl;
}
int main(){
	Node* head = new Node(10);
	Node* tail =head;
	InsertAtHead(head,5);
	InsertAtTail(tail,20);
	InsertAtTail(tail,25);
	InsertAtPosition(head,tail,3,15);
	Print(head);
	cout<<"head"<<head->data<<endl;
	cout<<"tail"<<tail->data<<endl;
	DeleteAtPosition(1,head);
	Print(head);
	cout<<"head"<<head->data<<endl;
	cout<<"tail"<<tail->data<<endl;
	DeleteAtPosition(3,head);
	Print(head);
	
}

