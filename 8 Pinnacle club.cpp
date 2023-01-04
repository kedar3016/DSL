/* 
Department of Computer Engineering has student's club named 'Pinnacle Club'. Students of Second, third and final year of department can be granted membership on request. Similarly one may cancel the membership of club. First node is reserved for president of club and last node is reserved for secretary of club. Write C++ program to maintain club member‘s information using singly linked list. Store student PRN and Name. Write functions to 
a)	Add and delete the members as well as president or even secretary. 
b)	Compute total number of members of club 
c)	Display members 
d)	Display list in reverse order using recursion 
e)	Two linked lists exists for two divisions. Concatenate two lists.
*/

#include<iostream>
#include<stdlib.h>

using namespace std;

struct SLL
{
	int prn;
	char name[20];
	struct SLL *next;
};
typedef struct SLL sll;

class Pinnacle_Club
{
	private :
		sll *President;
		sll *Secretary;
	public : 
		Pinnacle_Club();
		sll * get_President();	
		void Add_Member();	
		void display_members();		
	 	void Delete_Member();
		void compute_total_members();
		void display_list_reverse_order(sll *temp);
		void concatinate_list(Pinnacle_Club & B);
};

sll * Pinnacle_Club :: get_President()
{
	return President;
}

Pinnacle_Club :: Pinnacle_Club()
{
	President = NULL;
	Secretary = NULL;
}

void Pinnacle_Club :: Add_Member()
{
	char ans;
	int ch;
	sll *Member,*temp,*node;
 	Member  = new sll;
 	cout<<"\nEnter the PRN of the member : ";
 	cin>>Member->prn;
 	cout<<"\nEnter the Name of the member : ";
 	cin>>Member->name;
	Member->next = NULL;
	if(President == NULL)
	{
		President = Member;
		cout<<"\nPresident added successfully\n";
	}
	else
	{
		if(Secretary == NULL || President->next == NULL)
		{
			Secretary = Member;
			President->next = Secretary;			
			cout<<"\nSecretary added successfully\n";
		}
		else
		{
			temp = President;
			while(temp->next != Secretary)
				temp = temp->next;
			temp->next = Member;
			Member->next = Secretary;
			cout<<"\nNew Member add successfully\n";
		}
	}
}

void Pinnacle_Club :: Delete_Member()
{
	char ans;
	int ch,prn;
	sll *Member,*temp,*pnode;
	cout<<"\nEnter the prn of the member to be deleted : ";
	cin>>prn;
	for(temp = President; temp != NULL; temp = temp->next)
	{
		if(temp->prn == prn)
			break;
		pnode = temp;
	}
	if(temp == NULL )
	{
		cout<<"\nMember to be deleted not found in the Club \n";
	}
	else
    {
		if(temp == President)
		{
			President = President->next;
			if(President == NULL)
				Secretary = NULL;
			cout<<"\nCurrent President deleted from the Club\n";
		}
		else
		{
			if(temp->next == NULL)
			{
				pnode->next = NULL;
				Secretary = pnode;
				cout<<"\nCurrent Secretary deleted from the Club\n";
			}
			else
			{
				pnode->next = temp->next;
				cout<<"\nMember deleted from the Club\n";
			}
		}
		
		delete temp;
	}
}

void Pinnacle_Club :: display_members()
{
	int i = 1;
	sll *temp;
	cout<<"\nOrganization of Pinnacle Club \n";
	for(temp = President; temp != NULL; temp= temp->next)
	{
		cout<<"\n\t\t"<<i++<<" : "<<temp->name<<"  "<<temp->prn;	
		if(temp == President)
 			cout<<" (President) ";
		if(temp->next == NULL)
			cout<<" (Secretary)";
	}	
}

void Pinnacle_Club :: display_list_reverse_order(sll *temp)
{
	if(temp != NULL)
	{
		display_list_reverse_order(temp->next);
		cout<<"\n\t\t"<<temp->name<<"  "<<temp->prn;	
		if(temp == President)
 			cout<<" (President) ";
		if(temp->next == NULL)
			cout<<" (Secretary)";
	}
}

void Pinnacle_Club :: compute_total_members()
{
	int i = 0;
	sll *temp;
	for(temp = President; temp != NULL; temp= temp->next)
	{
		i++;
	}
	cout<<"\nTotal members of Pinnacle Club  = "<<i;	
}

void Pinnacle_Club :: concatinate_list(Pinnacle_Club & B)
{
	Secretary->next = B.President;
	Secretary = B.Secretary;
	B.President = NULL;
	B.Secretary = NULL;
	cout<<"\nList concatinated successfully";
}
int main()
{
	int ch;
	Pinnacle_Club A,B;
	char ans;
	system("clear");
	do
	{
		cout<<"\n\t\t\t1 : Add Members";
		cout<<"\n\t\t\t2 : Display Members";
		cout<<"\n\t\t\t3 : Delete Members";
		cout<<"\n\t\t\t4 : Compute Total Members";
		cout<<"\n\t\t\t5 : Display list in reverse order using recursion";
		cout<<"\n\t\t\t6 : Concatinate two lists";
		cout<<"\n\t\t\t7 : Exit";
		cout<<"\n\nEnter ur choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1 : A.Add_Member(); 
					 break;
			case 2 : A.display_members(); 
					 break;
			case 3 : A.Delete_Member(); 
					 break;
			case 4 : A.compute_total_members(); 
					 break;
			case 5 : A.display_list_reverse_order(A.get_President());
					 break;
			case 6 : do
					 {
					    B.Add_Member(); 
						cout<<"\nDo u want to add more : ";
						cin>>ans; 
					 }while(ans == 'y');
					 cout<<"\nDivision A";
					 A.display_members(); 
					 cout<<"\nDivision B";
					 B.display_members(); 
					 A.concatinate_list(B);
					 cout<<"\nConcatinated list :";
					 A.display_members(); 
					 break;
			case 7 : cout<<"\nEnd of Program\n";
					 break;
			default: cout<<"\nInvalid choice !! Try again\n\n";
		}
	}while(ch != 7);
	return 0;
}
