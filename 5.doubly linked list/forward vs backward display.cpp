#include <iostream>
using namespace std;
struct node
{
	int data;
	node* next;
	node* prev;
	node(int value,node* pre=0, node* nex=0)
	{
		data=value;
		next=nex;
		prev=pre;
	}
};
class doublylist
{
	public:
		node* head;
		node* tail;
		doublylist()
		{
			head=tail=0;
		}
		void insert(int value)
		{
			if(tail!=0)
			{
				tail->next=new node(value,tail,0);
				tail=tail->next;
			}
			else
			head=tail=new node(value);
		}
		void displaybackward()
		{
			node* temp=tail;
			while(temp!=0)
			{
				cout<<temp->data<<" ";
				temp=temp->prev;
			}
			cout<<endl;
		}
		void displayforward()
		{
			node* temp=head;
			while(temp!=0)
			{
				cout<<temp->data<<" ";
				temp=temp->next;
			}
			cout<<endl;
		}
};
int main()
{
	doublylist list;
	list.insert(11);
	list.insert(12);
	list.insert(10);
	list.insert(16);
	list.insert(19);
	cout<<"forward diplay:"<<endl;
	list.displayforward();
	cout<<"\nBackward display: "<<endl;
	list.displaybackward();
	cout<<endl;
	return 0;
	
}
