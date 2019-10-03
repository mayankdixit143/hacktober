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
	
template <class T>
class Stack
{
	Node<T> *head;
	public:
	Stack()
	{
		head=0;
	}
	int isempty()
	{
		if(head==0)
			return 1;
		else
			return 0;
	}
	void push(T x)
	{
		Node<T> *temp=new Node<T>(x);
		if(isempty())
		{
			head=temp;
		}
		else
		{
			temp->next=head;
			head=temp;
		}
	}
	int pop()
	{
		Node<T> *temp;
		int x=head->info;
		if(isempty())
		{
			delete head;
			head=0;
		}
		else
		{
			temp=head;
			head=head->next;
			delete temp;
		}
		return x;
	}
	T topele()
	{
		T x=head->info;
		return x;
	}
	void display()
	{
		Node<T> *temp=head;
		while(temp!=0)
		{
			cout<<"info->"<<temp->info<<endl;
			temp=temp->next;
		}
	}
};


int main()
{
	Stack<int> S1;
	int x,ch;
	char ch1;
	do
	{
	cout<<"1. Push"<<endl;
	cout<<"2. Pop"<<endl;
	cout<<"3. Top Element"<<endl;
	cout<<"Enter your choice"<<endl;
	cin>>x;
	switch(x)
	{
		case 1: cout<<"Enter the element"<<endl;
				cin>>ch;
				S1.push(ch);
				S1.display();
				break;
		case 2: ch=S1.pop();
				cout<<"Popped Element "<<ch<<endl;
				S1.display();
				break;
		case 3: if(S1.isempty())
					cout<<"Stack is Empty"<<endl;
				else
				{
					ch=S1.topele();
					cout<<"Top Element is"<<ch<<endl;
					S1.display();
				}
				break;
	}
	cout<<"Do you want to enter again"<<endl;
	cin>>ch1;
	}
	while(ch1=='Y' || ch1=='y');
}

