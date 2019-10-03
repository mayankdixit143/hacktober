#include<iostream.h>
int gcd(int,int);
int main()
{
	int m,n,r,c,s;
	char ch;
	do
	{
		cout<<"Enter the divisor"<<endl;
		cin>>m;
		cout<<"Enter the dividend"<<endl;
		cin>>n;
		cout<<"1. GCD using recusion"<<endl;
		cout<<"2. GCD using iteration"<<endl;
		cout<<"Enter your choice"<<endl;
		cin>>s;
		switch(s)
		{
			case 1: c=gcd(m,n);
					cout<<"The greatest common divisor is "<<c<<endl;
					break;
			case 2:	r=n%m;
					while(r!=0)
					{
						n=m;
						m=r;
						r=n%m;
					}
					cout<<"The greatest common divisor is "<<m<<endl;
					break;
		}
		cout<<"Do you want to continue(y/n)"<<endl;
		cin>>ch;
	}while(ch=='y' || ch=='Y');
}
int gcd(int m,int n)
{
	if(m<=n && n%m==0)
		return m;
	else if(n<m)
		gcd(m,n);
	else
		gcd(n%m,m);
}

