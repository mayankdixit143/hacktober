#include<iostream>
using namespace std;
template <class T1>

class node
{
  public:
  T1 info1;
  node *next;
  node(T1 x,node *n=0)
  {
    info1=x;
	next=n;
  }
  
  node()
  {
    info1=0;
	next=0;
  }
  
  ~node()
  {
    cout<<"destructor is called\n";
  }
};

template <class T1>
class sllist
{
  node<T1> *head,*tail;
  public:
  sllist()
  {
    head=tail=0;
  }
  
  ~sllist()
  {
    node<T1> *p;
    cout<<"destructor is called\n";
	while(head!=0)
	{
	  p=head->next;
	  delete head;
	  head=p;
	}
  }
  
  int isempty()
  {
    if(head==0)
	return 1;
	else
	return 0;
  }
  
  void addtohead(T1 x);
  void addtotail(T1 x);
  T1 deletefromhead();
  T1 deletefromtail();
  void deletenode(T1 x);
  int isinlist(T1 x);
  void reverse(sllist<T1> &s2);
  void concatenate(sllist<T1> &s2);
  void deleteinode(int n);
  void display();
};

template <class T1>
void sllist<T1>::addtohead(T1 x)
{
  node<T1> *temp=new node<T1>(x);
  if(isempty())
  head=tail=temp;
  else
  temp->next=head;
  head=temp;
}

template <class T1>
void sllist<T1>::addtotail(T1 x)
{
  node<T1> *temp=new node<T1>(x);
  if(isempty())
  head=tail=temp;
  else
  tail->next=temp;
  tail=temp;
}

template <class T1>
T1 sllist<T1>::deletefromhead()
{
  T1 x=head->info1;
  node<T1> *temp;
  if(head==tail)
  {
    delete head;
	head=tail=0;
  }
  else
  {
    temp=head;
	head=head->next;
	delete temp;
  }
}

template <class T1>
T1 sllist<T1>::deletefromtail()
{
  T1 x=tail->info1;
  node<T1> *temp;
  if(head==tail)
  {
    delete head;
	head=tail=0;
  }
  else
  {
    temp=head;
	while(temp->next!=tail)
	temp=temp->next;
	tail=temp;
	delete tail->next;
	tail->next=0;
  }
  return x;
}

template <class T1>
int sllist<T1>::isinlist(T1 x)
{
  node<T1> *temp=0;
  for(temp=head;temp!=0;temp=temp->next)
  if(temp->info1==x)
  return 1;
  return 0;
}

template <class T1>
void sllist<T1>::deletenode(T1 x)
{
  if(head==tail && head->info1==x)
  {
     delete head;
	 head=tail=0;
  }
  else if(head->info1==x)
  {
    deletefromhead();
  }
  else
  { 
    node<T1> *prev;
	node<T1> *temp;
    prev=head;
	temp=prev->next;
	while(temp!=0 && temp->info1!=x)
	{
	  prev=temp;
	  temp=temp->next;
	}
	if(temp!=0)
	{
	  prev->next=temp->next;
	  if(temp==tail)
	  tail=prev;
	delete temp;
	}
	else
	cout<<"Element not found\n";
  }
}

template <class T1>
void sllist<T1>::reverse(sllist<T1> &s2)
{
  node<T1> *temp=head;
  while(temp!=0)
  {
    s2.addtohead(temp->info1);
	temp=temp->next;
  }
}

template <class T1>
void sllist<T1>::concatenate(sllist<T1> &s2)
{
  node<T1> *temp=s2.head;
  for(temp=s2.head;temp!=0;temp=temp->next)
  {
    addtotail(temp->info1);
  }
}
  
template <class T1>
void sllist<T1>::deleteinode(int n)
{
  node<T1> *temp=head;
  int count=1;
  while(temp!=0 && count!=n)
  {
    ++count;
	temp=temp->next;
  }
  if(temp!=0)
  deletenode(temp->info1);
  else
  cout<<"The node does not exist\n";
}

template <class T1>
void sllist<T1>::display()
{
  node<T1> *temp=new node<T1>();
  if(isempty())
  {
    cout<<"underflow\n";
  }
  for(temp=head;temp!=0;temp=temp->next)
  cout<<temp->info1<<" ";
}

int main()
{
  int x;
  char ch;
  sllist<int> s1,s2;
  do
  {
    cout<<"Enter your choice\n 1. Press 1 for add to head\n 2. Press 2 for add to tail\n 3. Press 3 to delete from head\n 4. Press 4 to delete from tail\n 5. Press 5 to delete node\n 6. Press 6 to search the node in the linked list\n 7. Press 7 for reverse\n 8. Press 8 for concatenation\n 9. Press 9 to delete i node\n";
	cin>>x;
	
	switch(x)
	{
	  case 1: int s;
	          cout<<"Add to head\n";
			  cin>>s;
	          s1.addtohead(s);
			  cout<<"After adding to head\n";
	          s1.display();
			  break;
			  
	  case 2: int p;
	          cout<<"Add to tail\n";
			  cin>>p;
	          s1.addtotail(p);
			  cout<<"After adding to tail\n";
	          s1.display();
			  break;
			  
	  case 3: s1.deletefromhead();
	          cout<<"After deleting from head\n";
			  s1.display();
			  break;
	  
	  case 4: s1.deletefromtail();
	          cout<<"After deleting from tail\n";
			  s1.display();
			  break;
	  
	  case 5: int i;
	          cout<<"Enter the node which you want to delete\n";
	          cin>>i;
			  s1.deletenode(i);
			  cout<<"After deleting node\n";
			  s1.display();
			  break;
			  
	  case 6: int j;
	          int f;
	          cout<<"Enter the node which you want to search\n";
			  cin>>j;
			  f=s1.isinlist(j);
			  if(f==1)
			  cout<<"Element found\n";
			  else 
			  cout<<"Element not found\n";
			  break;
			 
	  case 7: s1.reverse(s2);
	          cout<<"After reversing the linked list\n";
			  s2.display();
			  break;
			  
	  case 8: s1.concatenate(s2);
	          cout<<"after concatenation\n";
			  s1.display();
			  break;
			  	    
	  case 9: int d;
	          cout<<"Enter the node which you want to delete\n";
	          cin>>d;
	          s1.deleteinode(d);
	          cout<<"After deleting i node\n";
			  s1.display();
			  
	  default: cout<<"Wrong choice\n";
	           break;
	}
	cout<<"\ndo you want to continue? Press 'y' if yes\n";
	cin>>ch;
   }while(ch=='y');
}
   
  

