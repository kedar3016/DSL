#include<iostream>
#include<stdlib.h>
using namespace std;
struct btree
{
	struct btree *lc;
	char data;
	struct btree *rc;	
};

class mybtree
{
	private:
		btree *root;
	public:
		mybtree();
		void create_btree();
		void insert_btree(btree *);
		void rec_traversals();
};

mybtree::mybtree()
	{
		root=NULL;
	}

void inorder(btree *temp)
	{
		if(temp != NULL)
			{
				inorder(temp->lc);
				cout<<temp->data<<" ";
				inorder(temp->rc);
			}
	}

void preorder(btree *temp)
	{
		if(temp != NULL)
			{
				cout<<temp->data<<" ";
				preorder(temp->lc);
				preorder(temp->rc);
			}
	}

void postorder(btree *temp)
	{
		if(temp != NULL)
			{
				postorder(temp->lc);
				postorder(temp->rc);
				cout<<temp->data<<" ";
			}
	}

void mybtree::insert_btree(btree *node)
	{
		char ans;
		btree *par;
			if(root == NULL)
				root=node;
			else
				{
					par=root;
					while(1)
						{
							cout<<"Where to add (l/r) of "<<par->data<<" : ";
							cin>>ans;
								if(ans == 'l')
									{
										if(par->lc == NULL)
											{
												par->lc = node;
												break;
											}
										else
											par = par->lc;
									}
								else
									{
										if(par->rc == NULL)
											{
												par->rc = node;
												break;
											}
										else
											par = par->rc;
									}
						}
						cout<<"\nNode inserted successfully";
				}
	}

void mybtree::create_btree()
	{
		int i,n;
		btree *node;
		cout<<"\nEnter the no of nodes in the tree: ";
		cin>>n;
			for(i = 1;i<=n;i++)
				{
					node = new btree;
					cout<<"\nEnter the data field of node "<<i<<" : ";
					cin>>node->data;
					node->lc = NULL;
					node->rc = NULL;
					insert_btree(node);
				}
				cout<<"\nBinary tree created successfully";
	}

void mybtree::rec_traversals()
	{
		if(root==NULL)
			{
				cout<<"\nBinary tree is empty";
			}
		else
			{
				cout<<"\nInorder Traversal is : ";
				inorder(root);
				cout<<"\nPreorder Traversal is : ";
				preorder(root);
				cout<<"\nPostorder Traversal is : ";
				postorder(root);
			}
	}
int main()
	{
		mybtree b;
		int ch;
		system("clear");
	
			do{
				cout<<"\n1:Create a Binary tree";
				cout<<"\n2:Traversal of tree";
				cout<<"\n5:Exit";
				cout<<"\nEnter your choice : ";
				cin>>ch;
		
				switch(ch)
					{
						case 1:b.create_btree();
						break;
						case 2:b.rec_traversals();
						break;
						case 5:cout<<"\nGod Bye";
						break;
					}
			}while(ch!=5);
	
		return 0;
	}
