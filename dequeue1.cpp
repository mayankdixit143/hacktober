#include<iostream.h>
class node
{
    public:
		int info;
    	node *next;
    	node *prev;
		node(int x,node *n=0,node *p=0)
		{
			info=x;
			next=n;
			prev=p;
		}
};
class dqueue
{
 	node *head,*tail;
	public:
        void insert1(int);
		void insert2(int);
        void del1();
		void del2();
        void display1();
		void display2();
        dqueue()
        {
            head = 0;
            tail = 0;
        }
		int isempty()
		{
			if(head==0)
				return 1;
			else
				return 0;
		}
};
void dqueue::insert1(int x)
{
    node *temp=new node(x);
    if(isempty())
	{
		head=tail=temp;
	}
	else
	{
		temp->next=head;
		head->prev=temp;
		head=temp;
	}
}
void dqueue::insert2(int x)
{
    node *temp=new node(x);
    if(isempty())
	{
		head=tail=temp;
	}
	else
	{
		tail->next=temp;
		temp->prev=tail;
		tail=temp;
	}
}
void dqueue::del1()
{
	int x=head->info;
	node *temp;
	if(head==tail)
	{
		delete head;
		head=tail=0;
	}
	else
	{
		temp=head;
		head=head->next;
		head->prev=0;
		delete temp;
	}
	cout<<"Deleted Element "<<x<<endl;
}
void dqueue::del2()
{
	int x=tail->info;
	node *temp;
	if(head==tail)
	{
		delete tail;
		head=tail=0;
	}
	else
	{
		tail=tail->prev;
		delete tail->next;
		tail->next=0;
	}
	cout<<"Deleted Element "<<x<<endl;
} 
void dqueue::display1()
{
	node *temp=head;
	while(temp!=0)
	{
		cout<<"info-> "<<temp->info;
		temp=temp->next;
	}
}
void dqueue::display2()
{
	node *temp=tail;
	while(temp!=0)
	{
		cout<<"info-> "<<temp->info;
		temp=temp->prev;
	}
}
int main()
{
	dqueue d;
	int ch,ch1,value;
	char ch2;
	do
	{
		cout<<"1. Insert Element"<<endl;
		cout<<"2. Delete Eleemnt"<<endl;
		cout<<"3. Display"<<endl;
		cout<<"Enter your choice"<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1: if(d.isempty())
					{
						cout<<"Enter the Elemet"<<endl;
						cin>>value;
						d.insert1(value);
					}
					else 
					{
						cout<<"1. Insert At Beginning"<<endl;
						cout<<"2. Insert At Last"<<endl;
						cout<<"Choice=";
						cin>>ch1;
						switch(ch1)
						{
							case 1: cout<<"Enter the element"<<endl;
									cin>>value;
									d.insert1(value);
									break;
							case 2: cout<<"Enter the element"<<endl;
									cin>>value;
									d.insert2(value);
									break;
						}
					}
					break;
			case 2: if(d.isempty())
						cout<<"Queue is empty"<<endl;
					else
					{
						cout<<"1. Delete from beginning"<<endl;
						cout<<"2. Delete from Last"<<endl;
						cout<<"Choice=";
						cin>>ch1;
						switch(ch1)
						{
							case 1: d.del1();
									break;
							case 2: d.del2();
									break;
						}
					}
					break;
			case 3: cout<<"1. Display from beginning"<<endl;
					cout<<"2. Display from last"<<endl;
					cout<<"Choice=";
					cin>>ch1;
					switch(ch1)
					{
						case 1: d.display1();
								break;
						case 2: d.display2();
								break;
					}
					break;
		}
		cout<<"Do you want to continue(y/n)"<<endl;
		cin>>ch2;
	}while(ch2=='y' || ch2=='Y');
}

