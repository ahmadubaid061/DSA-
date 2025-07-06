#include <iostream>
using namespace std;
struct Node
{
	int data;
	Node* next;
	Node* prev;
	Node(int value)
	{
		data=value;
		next=0;
		prev=0;
	}
	
};
class Queue
{
	private:
	Node* front;
	Node* rear;
	public:
		Queue()
		{
			front=rear=0;
		}
		//isempty
		bool isempty()
		{
			if(front==0)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		//return peek
		int peek()
		{
			if(isempty())
			{
				cout<<"nothing to print!"<<endl;
			}
			else
			{
				return front->data;
			}
		}
		//ENQUEVE
        void Enqueue(int value)
        {
        	Node* newnode=new Node(value);
        	if(isempty())
        	{
        		front=rear=newnode;
			}
			else
			{
				rear->next=newnode;
				newnode->prev=rear;
				rear=newnode;
			}
		}
		//Dequeue
		int Dequeue()
		{
			if(isempty())
			{
				cout<<"nothing to print!"<<endl;
			}
			else
			{
				Node* temp=front;
				front=front->next;
				front->next->prev=0;
				
				return temp->data;
				delete temp;
			}
		}
		//display
		void display()
		{
			if(isempty())
			{
				cout<<"Queue is empty!"<<endl;
			}
			else
			{
				Node* temp=front;
				while(temp!=0)
				{
					cout<<temp->data<<" ";
					temp=temp->next;
				}
				cout<<endl;
			}
		}
		
};
int main()
{
	Queue q;
	q.Enqueue(5);
	q.Enqueue(6);
	q.Enqueue(7);
	q.display();
	cout<<"after first deletion: "<<endl;
	int result=q.Dequeue();
	q.display();
	cout<<"the element value deleted is: "<<result<<endl;
	int x=q.peek();
	cout<<"the peek value is: "<<x<<endl;
	return 0;
}
