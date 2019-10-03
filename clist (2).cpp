#include<iostream.h>
template<class T>
class Node
{
	public:
		T info;
		Node *next;
		Node(T x,Node *n=0)
		{
			info=x;
			next=n;
		}
};
template<class T>
class clist
{
	Node<T> *tail;
	public:
		clist()
		{
			tail=0;
		}
		int isempty()
		{
			if(tail==0)
				return 1;
			else
				return 0;
		}
		void addtohead(T);
		void addtotail(T);
		T deletefromhead();
		T deletefromtail();
		void isinlist(T);
		void deletenode(T);
		void display();
		void reverse(clist&);
};
template<class T>
void clist<T>::addtohead(T x)
{
	Node<T> *temp=new Node<T>(x);
	if(isempty())
	{
		tail=temp;
		tail->next=temp;
	}
	else
	{
		temp->next=tail->next;
		tail->next=temp;
	}
}
template<class T>
void clist<T>::addtotail(T x)
{
	Node<T> *temp=new Node<T>(x);
	if(isempty())
	{
		tail=temp;
		tail->next=tail;
	}
	else
	{
		temp->next=tail->next;
		tail->next=temp;
		tail=temp;
	}
}
template<class T>
T clist<T>::deletefromhead()
{
	Node<T> *temp;
	T x=tail->next->info;
	if(tail==tail->next)
	{
		delete tail;
		tail=0;
	}
	else
	{
		temp=tail->next;
		tail->next=temp->next;
		delete temp;
	}
	return x;
}
template<class T>
T clist<T>::deletefromtail()
{
	Node<T> *temp;
	T x=tail->info;
	if(tail==tail->next)
	{
		delete tail;
		tail=0;
	}
	else
	{
		temp=tail->next;
		while(temp->next!=tail)
		{
			temp=temp->next;
		}
		temp->next=tail->next;
		delete tail;
		tail=0;
		tail=temp;
	}
	return x;
}
template<class T>
void clist<T>::isinlist(T x)
{
	int flag=0;	   
	Node<T> *temp=tail->next;
	while(temp!=tail)
	{
		if(temp->info==x)
		{
			flag=1;
			break;
		}
		else
			temp=temp->next;
	}
	if(temp->info==x)
		flag=1;
	if(flag==1)
		cout<<"Element Found";
	else
		cout<<"Element Not Found";
}
template<class T>
void clist<T>::deletenode(T x)
{
	Node<T> *temp,*prev;
	if(tail->next==tail && tail->next->info==x)
	{
		delete tail;
		tail=0;
	}
	else if(tail->next==tail && tail->next->info!=x)
	{
		cout<<"Element Not Found"<<endl;
	}
	else if(tail->next->info==x)
	{
		temp=tail->next;
		tail->next=temp->next;
		delete temp;
	}
	else
	{
		prev=tail->next;
		temp=tail->next->next;
		while(temp!=0 && temp->info!=x)
		{
			prev=temp;
			temp=temp->next;
		}
		if(temp!=0)
		{
			prev->next=temp->next;
			if(temp==tail)
			{
				tail=prev;
				delete temp;
			}
		}
		else
			cout<<"Element Not Found";
	}
}
template<class T>
void clist<T>::display()
{
	Node<T> *temp=tail->next;
	do
	{
		cout<<"info-> "<<temp->info<<endl;
		temp=temp->next;
	}
	while(temp!=tail->next);
}
template<class T>
void clist<T>::reverse(clist& l2  )
{
	Node<T> *temp=tail->next;
	do
	{
		l2.addtohead(temp->info);
		temp=temp->next;
	}
	while(temp!=tail->next);
}
int main()
{
	int ch,x;
	char ch1;
	clist<int>l1,l2;
	do
	{
	cout<<"1. ADD TO HEAD"<<endl;
	cout<<"2. ADD TO TAIL"<<endl;
	cout<<"3. DELETE FROM HEAD"<<endl;
	cout<<"4. DELETE FROM TAIL"<<endl;
	cout<<"5. ISINLIST"<<endl;
	cout<<"6. DELETE NODE"<<endl;
	cout<<"7. REVERSE"<<endl;
	cout<<"ENTER YOUR CHOICE"<<endl;
	cin>>ch;
	switch(ch)
	{
		case 1: cout<<"Enter the info part"<<endl;
				cin>>x;
				l1.addtohead(x);
				l1.display();
				break;
		case 2: cout<<"Enter the info part"<<endl;
				cin>>x;
				l1.addtotail(x);
				l1.display();
				break;
		case 3: x=l1.deletefromhead();
				cout<<"The Deleted Info Part"<<endl;
				cout<<x;
				l1.display();
				break;
		case 4: x=l1.deletefromtail();
				cout<<"The Deleted Info Part"<<endl;
				cout<<x;
				l1.display();
				break;
		case 5: cout<<"Enter the element you want to search"<<endl;
				cin>>x;
				l1.isinlist(x);
				l1.display();
				break;
		case 6: cout<<"Enter the info part you want to delete"<<endl;
				cin>>x;
				l1.deletenode(x);
				l1.display();
				break;
		case 7: l1.reverse(l2);
				l2.display();
				break;
	}
	cout<<"Do you Want to continue"<<endl;
	cin>>ch1;
}
while(ch1=='Y' || ch1=='y');
}
	

