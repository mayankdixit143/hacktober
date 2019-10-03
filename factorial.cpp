#include<iostream.h>
int fact(int);
void factr(int,int);
int main()
{
	int a,b,b1,i,pro=1,j=1;
	char ch;
	do
	{
		cout<<"Enter a number"<<endl;
		cin>>a;
		cout<<"1. Factorial Using Recusion"<<endl;
		cout<<"2. Factorial Using Iteration"<<endl;
		cout<<"3. Factors Using Recursion"<<endl;
		cout<<"4. Factors Using Iteration"<<endl;
		cout<<"Enter your choice"<<endl;
		cin>>b;
		switch(b)
		{
			case 1: b1=fact(a);
					cout<<"Factorial of a number"<<endl;
					cout<<b1;
					break;
			case 2: for(i=1;i<=a;i++)
					{
						pro=pro*i;
					}
					cout<<"Factorial of a number"<<endl;
					cout<<pro;
					break;
			case 3: cout<<"Factors are ";
					factr(j,a);
					break;
			case 4: cout<<"Factors are ";
					for(i=1;i<=a;i++)
					{
						if(a%i==0)
							cout<<i<<" ";
					}
					break;
		}
		cout<<"\nDo you want to enter again(y/n)"<<endl;
		cin>>ch;
	}while(ch=='y' || ch=='Y');
}
int fact(int a)
{
	if(a==0)
		return 1;
	else
		return a*fact(a-1);
}
void factr(int i,int m)
{
	if(i<=m)
	{
		if(m%i==0)
			cout<<i<<" ";
		i++;
		factr(i,m);
	}
}	 

