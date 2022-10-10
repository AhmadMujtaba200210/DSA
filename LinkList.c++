//I have used the OOP concepts because it also help us to understand the ListSTL is written

#include<iostream>
using namespace std;

//Forward Declaration
class List;

class Node{
    int data;
    Node*next;
  public:
	Node(int data):data(data),next(NULL){} //initialisation list
	int getData(){
	   return data;
	}

	friend class List;

	// ~Node(){
	// 	if(next!=NULL){
	// 		delete next;
	// 		cout<<"deleting the node with data "<<data<<endl;
	// 	}
	// }
};

class List{
    Node*head;
    Node*tail;
	int searchHelper(Node*start,int key){
		if(start==NULL){ return -1;}
		if(start->data==key) {return 0;}
	    int subIdx=searchHelper(start->next,key);
	    	if(subIdx==-1) {return -1;}
		return subIdx+1;
	}

  public:
	List():head(NULL),tail(NULL){}

	void push_front(int data){
	   if(head==NULL){
		Node*n=new Node(data);
		head=tail=n;
		return;
	}
	else{
	    Node*n=new Node(data);
	    n->next=head;
	    head=n;
	}
	}
	
	void push_back(int data){
		if(head==NULL){
			Node*n=new Node(data);
			head=tail=n;
			return;
		}
		else{
		     Node*n=new Node(data);
		     tail->next=n;
		     tail=n;
		}
	}
	
	void insert(int data,int pos){
	     if(head==NULL){
		push_front(data);
		return;
	     }
		Node*temp=head;
	     for(int jump=0;jump<=pos-1;jump++){
		temp=temp->next;
	     }
	   	Node*n=new Node(data);
		n->next=temp->next;
		temp->next=n;
	}	
	
	int search(int key){
	    Node*temp=head;
	    int idx=0;
		while(temp!=NULL){
		     if(temp->data==key) {return idx;}
		  	
		     idx++;
		     temp=temp->next;
		}
		return -1;
	}
	    

	int recursiveSearch(int key){
	    int idx=searchHelper(head,key);
	    return idx;
	}

	void pop_front(){
		Node*temp=head;
		head=head->next;
		temp->next=NULL;
		delete temp;
	}

	void pop_back(){
		Node*temp=head;
		if(head==NULL){
			return;
		}
		if(head->next==NULL){
			delete head;
			return;
		}
		while(temp->next->next!=NULL){
			temp=temp->next;
		}
		delete temp->next;
		temp->next=NULL;
	}

	void removeAtPos(int key){
		Node*temp=head;
		if(head==NULL){
			return;
		}else if(key==0){
			head=NULL;
			delete temp;
		}
		int idx=0;
		while(temp!=NULL&& idx<key-1){
		     temp=temp->next;
			 idx++;
		}
		// only when size of node is smaller than the key
		if(temp==NULL||temp->next==NULL){
			return;
		}
			Node*temp2=temp->next->next;
			delete temp->next;
			temp->next=temp2;
	}
 
	void display(){
		Node*temp=head;
	   while(temp!=NULL){
		cout<<temp->getData()<<"->";
		temp=temp->next;
		}
		
	}	

	// ~List(){
	// 	if(head!=NULL){
	// 		delete head;
	// 		head=NULL;
	// 	}
	// }
};   

int main(){
	List l;
	l.push_front(1);
	l.push_front(0);
	l.push_back(2);
	l.push_back(3);
	l.display();
	cout<<endl;

	l.removeAtPos(1);
	l.display();
	cout<<endl;
}