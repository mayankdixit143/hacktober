#include<iostream.h>
class circular
{
	int a[10];
	int front,rear;
	public:
		circular()
		{
			front=rear=-1;
		}
		int over()
		{
			if(front==0 && rear==9)
			{
				return 1;
			}
			else if(front==rear+1)
			{
				return 1;
			}
			else
				return 0;
		}
		void enqueue(int x)
		{	
			if(rear==9)
				rear=0;
			else	
			{
				++rear;
				a[rear]=x;
			}
			if(front==-1)
				front=0;
		}
		int under()
		{
			if(front==-1 && rear==-1)
				return 1;
			else
				return 0;
		}
		int dequeue()
		{
			int x=a[front];
			if(front==rear)
			{
				front=-1;
				rear=-1;
			}
			else
			{
				if(front==9)
					front=0;
				else
					++front;
			}
                     return x;
		}
		void display()
		{
			if(front<rear)
				for(int i=0;i<rear;i++)
					cout<<a[i];
			else if(rear<front)
			{
				for(int j=front;j<9;j++)
					cout<<a[j];
				for(int k=0;k<=rear;k++)
					cout<<a[k];
			}
		}
};
int main()
{
	circular c1;
	int x,y;
	char ch;
	do
	{
	cout<<"1. Enqueue"<<endl;
	cout<<"2. Dequeue"<<endl;
	cout<<"Enter your choice"<<endl;
	cin>>x;
	switch(x)
	{
		case 1: if(c1.over())
					cout<<"Overflow Queue"<<endl;
				else
					cout<<"Enter the element"<<endl;
					cin>>y;
					c1.enqueue(y);
					c1.display();
				break;
		case 2: if(c1.under())
					cout<<"Underflow Queue"<<endl;
				else
					c1.dequeue();
					c1.display();	 
				break;
	}
	cout<<"Do you want to continue"<<endl;
	cin>>ch;
	}
	while(ch=='y' || ch=='Y');
}
				
		

