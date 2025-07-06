#include <iostream>
using namespace std;
class Queue
{
	private:
		int size;
		int *q;
		int front;
		int rear;
		public:
			Queue()
			{
				size=5;
				q=new int[size];
				front=rear=-1;
			}
			bool isempty()
			{
				if(rear==-1)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			bool isfull()
			{
				if(rear==size-1)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			void Enqueue(int value)
			{
				if(isfull())
				{
					cout<<"no space!"<<endl;
				}
				else
				{
					if(isempty())
					{
						front=rear=0;
					}
					else
					{
						rear++;
					}
					q[rear]=value;
				}
			}
			int Dequeue()
			{
				if(isempty())
				{
					cout<<"empty!"<<endl;
				}
				else
				{
					int temp=q[front];
					if(front==rear)
					{
						front=rear=-1;
					}
					else
					{
						front++;
					}
					return temp;
				}
			}
			void display()
			{
				if(isempty())
				{
					cout<<"nothing to display!"<<endl;
				}
				else
				{
					for(int i=front;i<=rear;i++)
					{
						cout<<q[i]<<" ";
					}
					cout<<endl;
				}
			}
};
int main()
{
	Queue a;
	a.Enqueue(2);
	a.Enqueue(3);
	a.Enqueue(4);
	a.display();
	int result=a.Dequeue();
	cout<<"display after first Dequeve:"<<endl;
	a.display();
	cout<<"the element popped out is: "<<endl;
	cout<<result<<endl;
	return 0;
	
	
}
