#include<iostream>
using namespace std;
template<class T>
class Dnode
{
  public:
  T info;
  Dnode *prev,*next;
  Dnode(T x,Dnode *n=0,Dnode *p=0)
  {
    info=x;
	prev=p;
	next=n;
  }
};

template<class T>
class Dlist
{
  Dnode<T> *head,* tail;
  public:
  Dlist()
  {
    head=tail=0;
  }
  
  ~Dlist()
  {
    Dnode<T> *p;
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
	return 0;
  }
  
  void addtohead(T x);
  void addtotail(T x);
  T deletefromhead();
  T deletefromtail();
  void deletenode(T x);
  int isinlist(T x);
  void reverse();
  void concatenate(Dlist<T> &d2);
  void display();
};

template <class T>
void Dlist<T>::addtohead(T x)
{
  Dnode<T> *temp=new Dnode<T>(x);
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

template<class T>
void Dlist<T>::addtotail(T x)
{
  Dnode<T> *temp=new Dnode<T>(x);
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

template <class T>
T Dlist<T>::deletefromhead()
{
  T x=head->info;
  if(head==tail)
  {
    delete head;
	head=tail=0;
  }
  else
  {
    head=head->next;
	delete head->prev;
	head->prev=0;
  }
  return x;
  }

template <class T>
T Dlist<T>::deletefromtail()
{
  T x=tail->info;
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
  return x;
}

template<class T>
void Dlist<T>::deletenode(T x)
{
  Dnode<T> *temp;
  if(head==tail && head->info==x)
  {
    delete head;
	head=tail=0;
  }
  else if(head->info==x)
  {
    deletefromhead();
  }
  else
  {
    temp=head->next;
	while(temp!=0 && temp->info!=x)
	temp=temp->next;
	if(temp!=0)
	{
	  temp->prev->next=temp->next;
	  if(temp!=tail)
	  temp->next->prev=temp->prev;
	  else
	  tail=temp->prev;
	  delete temp;
	}
	else
	cout<<"Element not found\n";
  }
}

template <class T>
int Dlist<T>::isinlist(T x)
{
  Dnode<T> *temp=0;
  for(temp=head;temp!=0;temp=temp->next)
  if(temp->info==x)
  return 1;
  return 0;
}

template <class T>
void Dlist<T>::reverse()
{
  int c=0;
  Dnode<T> *temp,*temp1,*temp2;
  for(temp=head;temp!=0;temp=temp->next)
  c++;
  T x;
  temp1=head;
  temp2=tail;
  for(int i=0;i<c/2;i++)
  {
    x=temp1->info;
	temp1->info=temp2->info;
	temp2->info=x;
	temp1=temp1->next;
	temp2=temp2->prev;
  }
}

template <class T>
void Dlist<T>:: concatenate(Dlist<T> &d2)
{
  Dnode<T> *temp;
  for(temp=d2.head;temp!=0;temp=temp->next)
  {
    addtotail(temp->info);
  }
}

template <class T>
void Dlist<T>::display()
{
  Dnode<T> *temp;
  if(isempty())
  {
    cout<<"underflow\n";
	return;
  }
  for(temp=head;temp!=0;temp=temp->next)
  cout<<temp->info<<" ";
}


int main()
{
  int x;
  char ch;
  Dlist<int> d1,d2;
  do
  {
    cout<<"Enter your choice\n 1. Press 1 for add to head\n 2. Press 2 for add to tail\n 3. Press 3 to delete from head\n 4. Press 4 to delete from tail\n 5. Press 5 to delete node\n 6. Press 6 for is in list\n 7. Press 7 for reverse\n 8. Press 8 for concatenation\n";
	cin>>x;
	
	switch(x)
	{
	  case 1: int d;
	          cout<<"Add to head\n";
			  cin>>d;
	          d1.addtohead(d);
			  cout<<"After adding to head\n";
	          d1.display();
			  break;
			  
	  case 2: int p;
	          cout<<"Add to tail\n";
			  cin>>p;
	          d1.addtotail(p);
			  cout<<"After adding to tail\n";
	          d1.display();
			  break;
			  
	  case 3: d1.deletefromhead();
	          cout<<"After deleting from head\n";
			  d1.display();
			  break;
	  
	  case 4: d1.deletefromtail();
	          cout<<"After deleting from tail\n";
			  d1.display();
			  break;
	  
	  case 5: int i;
	          cout<<"Enter the node which you want to delete\n";
	          cin>>i;
			  d1.deletenode(i);
			  cout<<"After deleting node\n";
			  d1.display();
			  break;
	  		  
	  case 6: int j;
	          int f;
	          cout<<"Enter the node which you want to search\n";
			  cin>>j;
			  f=d1.isinlist(j);
			  if(f==1)
			  cout<<"Element found\n";
			  else 
			  cout<<"Element not found\n";
			  break;
	  
	  case 7: d1.reverse();
	          cout<<"After reversing the linked list\n";
			  d1.display();
			  break;
	  
	  case 8: d1.concatenate(d2);
	          cout<<"After concatenation\n";
			  d1.display();
			  break;
			  		  
	  default: cout<<"Wrong choice\n";
	           break;
	}
	cout<<"\ndo you want to continue? Press 'y' if yes\n";
	cin>>ch;
   }while(ch=='y');
}

