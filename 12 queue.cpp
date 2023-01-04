/* 
Queues are frequently used in computer programming, and a typical example is the creation of a job queue by an operating system. If the operating system does not use priorities, then the jobs are processed in the order they enter the system. Write C++ program for simulating job queue. Write functions to add job and delete job from queue.
*/

#include<iostream>
#include<stdlib.h>
#define Size 5


using namespace std;

class myqueue
{
	private :
		int Q[Size];
		int front,rear;
	public :
		myqueue();
		void enqueue(int X);
		int dequeue();
		int isQempty();
		int isQfull();
};

myqueue :: myqueue()
{
	front = 0, rear = -1;
}

int myqueue :: isQempty()
{
	if(front > rear)
		return 1;
	else
		return 0;
}

int myqueue :: isQfull()
{
	if(rear == Size - 1)
		return 1;
	else
		return 0;
}

void myqueue :: enqueue(int X)
{
	if(!isQfull())
	{
		rear = rear + 1;
		Q[rear] = X;
		cout<<"\nJob added into the queue";
	}
	else
		cout<<"\nQueue is Full!! Job cannot be added";
}

int myqueue :: dequeue()
{
	int X = -1;
	if(!isQempty())
	{
		X = Q[front];
		front++;
	}
	return X;
}

int main()
{
	int ch;
	int n;
	myqueue JQ;
	system("clear");
	do
	{
		cout<<"\n\t\t\t1 : Insert into Job Queue";
		cout<<"\n\t\t\t2 : Delete from Job Queue";
		cout<<"\n\t\t\t3 : Exit";
		cout<<"\n\nEnter ur choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1 : cout<<"\nEnter the Job No to be added : ";
					 cin>>n;
					 JQ.enqueue(n);
					 break;
			case 2 : n = JQ.dequeue();
					 if(n != -1)
					    cout<<"\nJob No "<<n<<" deleted from Queue";
					 else
						cout<<"\nJob Queue is Empty !! No Jobs to delete";
					 break;			
			case 3 : cout<<"\nEnd of Program\n";
					 break;
			default: cout<<"\nInvalid choice !! Try again\n\n";
		}
	}while(ch != 3);
	return 0;
} 
