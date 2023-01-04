
#include<iostream>
#include<stdlib.h>
#include<math.h>

using namespace std;

struct DLL
{
	struct DLL *prev;
	char data;
	struct DLL *next;
};
typedef struct DLL dll;

class binary_number
{
	private :
		dll *head;
	public :
		binary_number();
		void accept_binary_number();
		void insert_at_beg(dll *);
		void insert_at_end(dll *);
		~binary_number();
		dll * find_last_node();
		void display_binary_number();
		binary_number compute_1s_complement();
		binary_number compute_2s_complement();
		friend binary_number operator + (binary_number, binary_number);
};

void binary_number :: insert_at_end(dll *node)
{
	dll *last;
	if(head == NULL)
		head = node;
	else
	{
		last = head;
 		while(last->next != NULL)
			last = last->next;
		last->next = node;
		node->prev = last;
	}
}

void binary_number :: insert_at_beg(dll *node)
{
	if(head == NULL)
		head = node;
	else
	{
		node->next = head;
		head->prev = node;
		head = node;
	}
}

binary_number :: binary_number()
{
	head = NULL;
}

binary_number :: ~binary_number()
{
	dll *temp,*node;
	temp = head;
    while(temp != NULL)
    {
        node = temp;
		temp = temp->next;
		delete node;       
    }		
}

void binary_number :: accept_binary_number()
{
	char Str[20];
	dll *node,*last;
    int i;
	cout<<"\nEnter the binary number : ";
	cin>>Str;
	for(i = 0 ; Str[i] != '\0'; i++)
	{
		node = new dll;
		node->prev = NULL;
		node->data = Str[i];
		node->next = NULL;
		if(i == 0)
		{
			head = node;
			last = node;
		}
		else
		{
			last->next = node;
			node->prev = last;
			last = node;
		}
	}
	cout<<"\nBinary number created successfully using dll\n";
}

binary_number binary_number :: compute_1s_complement()
{
	binary_number b2;	
	dll *temp,*node;
	for(temp = head; temp != NULL; temp = temp->next)
	{
		node = new dll;
		node->prev = NULL;
		node->next = NULL;
		if(temp->data == '1')
        	node->data = '0';
		else
 			node->data = '1';
		b2.insert_at_end(node);
	}
	return b2;
}


dll * binary_number ::  find_last_node()
{
	dll *last;
	last = head;
	while(last->next != NULL)
		last = last->next;
	return last;
}

binary_number binary_number :: compute_2s_complement()
{
	binary_number b2;	
	dll *temp,*node;
	char Carry = '1';
	for(temp = find_last_node(); temp != NULL; temp = temp->prev)
	{
		node = new dll;
		node->prev = NULL;
		node->next = NULL;
		if(temp->data == '1')
        	node->data = '0';
		else
 			node->data = '1';
		
		if(Carry == '1')
		{
			if(node->data == '1')
				node->data = '0';
			else
			{
				node->data = '1';
				Carry = '0';
			}
		}
		b2.insert_at_beg(node);
	}
	return b2;
}

void binary_number :: display_binary_number()
{
	dll *temp;	
	for(temp = head ;temp != NULL; temp = temp->next)
	{
      cout<<temp->data;
	}
}

binary_number operator + (binary_number b1,binary_number b2)
{
	binary_number b3;
	dll *temp1,*temp2,*node;
	char Carry = '0';
	temp1 = b1.find_last_node();	
	temp2 = b2.find_last_node();
	while(temp1 != NULL && temp2 != NULL)
	{
		node = new dll;
		node->next = NULL;
		node->prev = NULL;
		if(Carry == '1')
		{
			if(temp1->data == '1' && temp2->data == '1')
			{
				node->data = '0';
			}
			else
			{
				if(temp1->data == '0' && temp2->data == '0')
				{
					node->data  = '1';
					Carry = '0';
				}
				else
				{
					node->data = '0';
				}
			}
		}
		else
		{
			if(temp1->data == '1' && temp2->data == '1')
			{
				node->data = '0';
				Carry = '1';
			}
			else
			{
				if(temp1->data == '0' && temp2->data == '0')
				   	node->data = '0';
				else
					node->data = '1';
			}
		}
		b3.insert_at_beg(node);
		temp1 = temp1->prev;
		temp2 = temp2->prev;
	}
	while(temp1 != NULL)
	{
		node = new dll;
		node->next = NULL;
		node->prev = NULL;

		if( (Carry == '1' && temp1->data == '1') || (Carry == '0' && temp1->data == '0') )
			node->data = '0';
		else
		{
			node->data = '1';
			Carry = '0';
		}
		b3.insert_at_beg(node);
		temp1 = temp1->prev;
	}

	while(temp2 != NULL)
	{
		node = new dll;
		node->next = NULL;
		node->prev = NULL;

		if( (Carry == '1' && temp2->data == '1') || (Carry == '0' && temp2->data == '0') )
			node->data = '0';
		else
		{
			node->data = '1';
			Carry = '0';
		}
		b3.insert_at_beg(node);
		temp2 = temp2->prev;
	}
	if(Carry == '1')
	{
		node = new dll;
		node->next = NULL;
		node->prev = NULL;
		node->data = '1';
		b3.insert_at_beg(node);
	}
	return b3;
}
int main()
{
	int ch;
	binary_number b1,b2,b3;
	system("clear");
	do
	{
		cout<<"\n\t\t\t1: Accept a binary number";
		cout<<"\n\t\t\t2: Compute 1s complement";
		cout<<"\n\t\t\t3: Compute 2s complement";
		cout<<"\n\t\t\t4: Addition of two binary numbers";
		cout<<"\n\t\t\t5: Exit";
		cout<<"\n\nEnter ur choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1 : cout<<"\nInput First binary number";
					 b1.accept_binary_number();
					 cout<<"\nThe binary number : ";
					 b1.display_binary_number();
					 break;
			case 2 : cout<<"\nThe binary number : ";
					 b1.display_binary_number();
					 b2  = b1.compute_1s_complement();
					 cout<<"\n1s Complement     : ";
           			 b2.display_binary_number();
					 break;
			case 3 : cout<<"\nThe binary number : ";
					 b1.display_binary_number();
					 b2  = b1.compute_2s_complement();
					 cout<<"\n2s Complement     : ";
           			 b2.display_binary_number();
					 break;
			case 4 : cout<<"\nInput Second binary number";
					 b2.accept_binary_number();
					 cout<<"\nFirst binary number  : ";
					 b1.display_binary_number();
					 cout<<"\nSecond binary number : ";
					 b2.display_binary_number();
					 b3  = b1 + b2;
					 cout<<"\nResultant addition   : ";
           			 b3.display_binary_number();
					 break;
			case 5 : cout<<"\nGoodbye\n";
					 break;
			default:cout<<"\nInvalid choice !! Try again!!! \n\n";
		}
	}while(ch!= 5);
	return 0;
}

