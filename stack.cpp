#include<iostream.h>
template<class T>
class stack
{
	T arr[10];
	int top;
	public:
		stack()
		{
			top=-1;
		}
		void push(T a)
		{
			if(top>10)
				cout<<"Stack overflow"<<endl;
			else
				{
					++top;
					arr[top]=a;
				}
		}
		T pop()
		{
			if(top==-1)
				cout<<"Stack underflow"<<endl;
			else
				
				return arr[top--];
		}
		void display()
		{
			for(int i=top;i>=0;i--)
			{
				cout<<arr[i];
			}
		}
};
int main()
{
	stack<int>o1;
	int k,num,m;
	char ch;
	do
	{
		cout<<"1. Push"<<endl;
		cout<<"2. Pop:"<<endl;
		cout<<"3. Display"<<endl;
		cout<<"Enter your choice"<<endl;
		cin>>k;
	
		switch(k)
		{
			case 1:cout<<"Enter the number to be pushed"<<endl;
					cin>>num;
					o1.push(num);
					break;
			case 2: m=o1.pop();
					cout<<"The number popped "<<m<<endl;
					break;
			case 3: o1.display();
					break;
		}
		cout<<"\nDo you want to continue(Y/N)"<<endl;
		cin>>ch;
	}
	while(ch=='Y' || ch=='y');
}
	
			

