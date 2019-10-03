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
		int overflow()
		{
			if(top>10)
				return 1;
			else 
			return 0;
		}
		int isempty()
		{
			if(top==-1)
				return 1;
			else
				return 0;
		}
		void push(T a)
		{
			if(overflow())
				cout<<"Stack overflow"<<endl;
			else
				{
					++top;
					arr[top]=a;
				}
		}
		T pop()
		{	 	 
				return arr[top--];
		}
		void display()
		{
			for(int i=top;i>=0;i--)
			{
				cout<<arr[i];
			}
		}
		void largeno(stack &s2)
		{
			stack<T> result;
			int x,y,carry=0,c;
			while(!isempty() || !s2.isempty())
			{
				if(!isempty())
					x=pop();
				else
					x=0;
				if(!s2.isempty())
					y=s2.pop();
				else
					y=0;
				carry+=x+y;
				result.push(carry%10);
				carry=carry/10;
			}
			if(carry!=0)
				result.push(carry);
			while(!result.isempty())
			{
				c=result.pop();
				cout<<c;
			}
		}
};
int main()
{
	stack<int> s1,s2,result;
	int s,x,c,a;
	char ch='y',ch2;
	do
	{
	cout<<"1. Pop"<<endl;
	cout<<"2. Push"<<endl;
	cout<<"3. Display"<<endl;
	cout<<"4. Adding Large Numbers"<<endl;
	cout<<"Enter your choice"<<endl;
	cin>>s;
	switch(s)
	{
		case 1: cout<<"Enter the number"<<endl;
				cin>>x;
				s1.push(x);
				s1.display();
				break;
		case 2: c=s1.pop();
				cout<<"The popped Element "<<c;
				s1.display();
				break;
		case 3: s1.display();
				break;
		case 4: while(ch=='y')
				{
					cout<<"Enter the number"<<endl;
					cin>>a;
					s2.push(a);
					cout<<"Do you want to enter more(y)"<<endl;
					cin>>ch;
				}
				s1.largeno(s2);
				break;
	}
	cout<<"Do you want to continue"<<endl;
	cin>>ch2;
	}while(ch2=='y' || ch2=='Y');
}

