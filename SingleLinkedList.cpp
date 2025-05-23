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
	Node* temp = new Node(d);
	temp->next=head;
	head=temp;
}
void insertAtTail(Node* &tail,int d){
	Node *temp = new Node(d);
	tail->next=temp;
	tail=tail->next;
}
void insertAtPosition(Node* &head,Node* &tail,int position,int d){
	if(position==1){
		InsertAtHead(head,d);
		return;
	}
	Node* temp = head;
	int cnt = 1;
	
	while(cnt< position-1){
		temp=temp->next;
		cnt++;
	}
	if(temp->next==NULL){
		insertAtTail(tail,d);
		return;
	}
	Node* nodeToInsert = new Node(d);
	nodeToInsert->next=temp->next;
	temp->next=nodeToInsert;	
}
void print(Node* &head){
	Node* temp =head;
	while(temp!=NULL){
		cout<<temp->data<<"->";
		temp=temp->next;
	}
	cout<<endl;
}
int main(){
	Node* node1 = new Node(10);
	Node* head=node1;
	Node* tail=node1;
	insertAtTail(tail,12);
	InsertAtHead(head,8);
	insertAtPosition(head,tail,2,11);
	insertAtPosition(head,tail,1,7);
	insertAtPosition(head,tail,6,9);
	print(head);
	cout<<"head"<<head->data<<endl;
	cout<<"Tail"<<tail->data<<endl;
}
