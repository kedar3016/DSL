/* 
Pizza parlor accepting maximum M orders. Orders are served in first come first served basis. Order once placed can not be cancelled. Write C++ program to simulate the system using circular queue using array.
*/

#include<iostream>
#include<stdlib.h>
#define Max 5

using namespace std;


class myCircularQueue
{
	private :
		int Q[Max];
		int front,rear;
		int count;
	public :
		myCircularQueue();
		void enqueue(int X);
		int dequeue();
		int isQempty();
		int isQfull();
};

myCircularQueue :: myCircularQueue()
{
	front = 0, rear = -1;
	count = 0;
}

int myCircularQueue :: isQempty()
{
	if(count == 0)
		return 1;
	else
		return 0;
}

int myCircularQueue :: isQfull()
{
	if(count == Max)
		return 1;
	else
		return 0;
}

void myCircularQueue :: enqueue(int X)
{
	if(!isQfull())
	{
		rear = (rear + 1)%Max;
		Q[rear] = X;
		count++;
		cout<<"\nPizza Order placed successfully into the queue";
	}
	else
		cout<<"\nQueue is Full!! Order cannot be added";
}

int myCircularQueue :: dequeue()
{
	int X = -1;
	if(!isQempty())
	{
		X = Q[front];
		front = (front+1) %Max;
		count--;
	}
	return X;
}

int main()
{
	int ch;
	int n;
	myCircularQueue Q;
	system("clear");
	do
	{
		cout<<"\n\t\t\t1 : Insert into Pizza order into Queue";
		cout<<"\n\t\t\t2 : Delete the order from Queue";
		cout<<"\n\t\t\t3 : Exit";
		cout<<"\n\nEnter ur choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1 : cout<<"\nEnter the Order No to be placed : ";
					 cin>>n;
					 Q.enqueue(n);
					 break;
			case 2 : n = Q.dequeue();
					 if(n != -1)
					    cout<<"\nOrder No "<<n<<" completed & deleted from Queue";
					 else
						cout<<"\nPizza Order Queue is Empty !! No orders to delete";
					 break;			
			case 3 : cout<<"\nEnd of Program\n";
					 break;
			default: cout<<"\nInvalid choice !! Try again\n\n";
		}
	}while(ch != 3);
	return 0;
}
