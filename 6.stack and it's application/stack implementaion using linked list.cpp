#include <iostream>
using namespace std;
struct node
{
	int data;
	node* Next;
	node* Prev;
	node(int value,node* next=0,node* prev=0)
	{
		data=value;
		Next=next;
		Prev=prev;
	}
	
};
class stack
{
	private:
		node* head;
		node* tail;
		public:
			stack()
			{
				head=tail=0;
				
			}
			
			bool isempty()
			{
				if(head==0)
			    {
			    	return true;
				}
				else
				{
					return false;
				}
			}
			//or simply 
			//bool isEmpty()
			//{
			//	return (head==0);
			//}
			
			void push(int value)
			{
				
				node* newnode=new node(value);
				if(head!=0)
				{
					head->Prev=newnode;
					newnode->Next=head;
				}
				head=newnode;
				
			}
			void pop()
			{
				if(isempty())
				{
					cout<<"stack is empty stack is empty!"<<endl;
				}
				else
				{
					node* temp=head;
					head=head->Next;
					if(!isempty())
					{
						head->Prev=0;
					}
				    delete temp;
				}
			}
			void display()
			{
				if(isempty())
				{
					cout<<"stack is empty stack is empty!"<<endl;
				}
				else
				{
					node* temp=head;
					while(temp!=0)
					{
						
					    cout<<temp->data<<" ";
					    temp=temp->Next;
					}
					cout<<endl;
				}
			}
};
int main()
{
	stack s;
	s.push(5);
	s.push(6);
	s.push(8);
	s.push(10);
	s.display();
	cout<<"----------after first pop:"<<endl;
	s.pop();
	s.display();
	cout<<"\n---------after second pop"<<endl;
	s.pop();
	s.display();
	return 0;
}
