#include<iostream>
using namespace std;

struct btree{
	btree *lc;
	int data;
	btree *rc;
};

class MyBtree{
	private:
		btree* root;
		
	public:
		MyBtree();
		void create();
		void insert(btree*);
		void display();
		void preorder(btree*);
		void inorder(btree*);
		void postorder(btree*);
};

MyBtree::MyBtree(){
	root=NULL;
}

void MyBtree::insert(btree *node){
	btree *par;
	char ans;
	if(root == NULL){
		root =node;
	}
	else{
		par=root;
		
		while(1){
			cout<<"\nWhere to insert(l/r):- ";
		    cin>>ans;
		    if(ans=='l'){
		    	
				if(par->lc==NULL){
		    		par->lc=node;
		    		break;
				}
				else{
					par=par->lc;
				}
			}
			
			
			else{
			
				if(par->rc == NULL){
					par->rc=node;
					break;
				}
				else{
					par=par->rc;
				}
			}
		
	}
 }
 cout<<"\nElement added successfully.";
}
void MyBtree::preorder(btree *temp){
	if(temp!=NULL){
	cout<<temp->data<<",";	
	preorder(temp->lc);
	preorder(temp->rc);
	}
}
void MyBtree::inorder(btree *temp){
	if(temp!=NULL){
		inorder(temp->lc);
		cout<<temp->data<<",";
		inorder(temp->rc);
	}
}
void MyBtree::postorder(btree *temp){
	if(temp!=NULL){
		postorder(temp->lc);
		postorder(temp->rc);
		cout<<temp->data<<",\b";
	}
}
void MyBtree::create(){
	int i,n;
	btree *node;
	cout<<"\n\tEnter the no. of node:- ";
	cin>>n;
	 
	 for(i=0;i<n;i++){
	 	node=new btree;
	 	cout<<"\n\tEnter the "<<i+1<<" element in btree:- ";
	 	cin>>node->data;
	 	node->lc=NULL;
	 	node->rc=NULL;
	 	insert(node);
	 	
	 }
	 cout<<"\nNode added successfully";
}

void MyBtree::display(){
	cout<<"\nThe preorder traversal is:- ";
	preorder(root);
	cout<<"\nThe inorder traversal is:- ";
	inorder(root);
	cout<<"\nThe postorder traversal is:- ";
	postorder(root);
}
int main(){
	MyBtree b;
	int ch;
	do{
		cout<<"\n\t\t1:create";
		cout<<"\n\t\t2:insert";
		cout<<"\n\t\t3:Display";
		cout<<"\n\t\t4:Delete";
		cout<<"\n\t\t5:Exit";
		cout<<"\n\tEnter your choice:- ";
		cin>>ch;
		
		switch(ch){
			case 1: b.create();
					break;
			case 2:	btree *node;
					node=new btree;
					cout<<"\nEnter Element to Insert:- ";
					cin>>node->data;
					node->lc=NULL;
	 				node->rc=NULL;
	 				b.insert(node);
	 				break;
					 
			case 3: b.display();
					break;  
			case 5: break;
			default:cout<<"\nInvalid Choice!!";
		}		
	}while(ch!=5);
}
