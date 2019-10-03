#include<iostream.h>
template<class T>
class insertion
{
	T a[50];
	int size;
	T item;
	public:
		void input()
		{
			cout<<"Enter the size of the array"<<endl;
			cin>>size;
			cout<<"Enter the array"<<endl;
			for(int i=0;i<size;i++)
			{
				cin>>a[i];
			}
		}
		void isort()
		{
			int temp;
			int num;
			for (int i=0;i<size;i++)
    		{
      			for (int j=i;j>=1;j--)
        		{
            		if (a[j]<a[j-1])
            		{
                		temp=a[j];
                		a[j]=a[j-1];
                		a[j-1]=temp;
            		}
            	else
                	break;
        		}
			}
			for(int j=0;j<size;j++)
			{
				cout<<a[j]<<endl;
			}
		}
	};
int main()
{
	insertion<int>o1;
	o1.input();
	o1.isort();
}
				

