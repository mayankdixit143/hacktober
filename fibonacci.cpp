#include<iostream.h>
int fibo(int);
int main()
{
	int a,i=0,b,b1=0,c=1,d;
	char ch;

	do
	{
		cout<<"Enter a number"<<endl;
		cin>>a;
		cout<<"1. Fibonacci using Recusion"<<endl;
		cout<<"2. Fibonacci using Iteration"<<endl;
		cout<<"Enter your choice"<<endl;
		cin>>b;
		switch(b)
		{
			case 1: for(i=0;i<a;i++)
					{
						int c=fibo(i);
						cout<<c<<" ";
					}
					break;
			case 2: cout<<"0"<<" "<<"1 ";
					while(i<(a-2))
					{	 
						d=b1+c;
						cout<<d<<" ";
						b1=c;
						c=d;
						i++;
					}
					break;
		}
		cout<<"Do you want to continue(Y/n)"<<endl;
		cin>>ch;
	}while(ch=='y' || ch=='Y');
}
int fibo(int a)
{
	int i=0,c,b,d;
	if(a==0)
		return 0;
	else if(a==1)
		return 1;
	else
		return fibo(a-1)+fibo(a-2);
		
}

