#include <iostream>
using namespace std;
class Queue
{
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
			if((rear+1)%size==front)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		void enqueue(int value)
		{
			if(isfull())
			{
				cout<<"Queue is full!"<<endl;
				
			}
			else
			{
				if(isempty())
				{
					front=rear=0;
				}
				else
				{
					rear=(rear+1)%size;
				}
				q[rear]=value;
			}
		}
		int dequeue()
		{
			if(isempty())
			{
				cout<<"queue is already empty!"<<endl;
				return -1;
			}
			else
			{
				int x=q[front];
				if(front==rear)
				{
					front=rear=-1;
				}
				else
				{
					front=(front+1)%size;
				}
				return x;
			}
		}
		void display()
		{
		    if (isempty())
		    {
		        cout << "queue is empty!" << endl;
		    }
		    else
		    {
		        cout << "Queue elements: ";
		        int i = front;
		        while (true)
		        {
		            cout << q[i] << " ";    //problem
		            if (i == rear)
		            {
		                break;
		            }
		            i = (i + 1) % size;
		        }
		        cout << endl;
		    }
		}

		
};
int main()
{
	Queue s;
	s.enqueue(2);
	s.enqueue(5);
	s.enqueue(7);
	s.display();
	s.dequeue();
	s.display();
	s.enqueue(6);
	s.enqueue(8);
	s.enqueue(9);
	s.display();
	s.dequeue();
	s.display();
	return 0;
}
