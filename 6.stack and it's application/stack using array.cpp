#include <iostream>
using namespace std;
const int size=5;
class stack
{
	private:
	int arr[size];
	int top;
	public:
		stack()
		{
			top=-1;
		}
		void push(int value)
		{
			if(top>=size-1)
			{
				cout<<"stack overflow!"<<endl;
			}
			else
			{
				top=top+1;
				arr[top]=value;
			}
		}
		bool isEmpty()
		{
			if(top==-1)
			{
				return true;
			}
			else 
			{
				return false;
			}
		}
		int pop()
		{
			if(isEmpty())
			{
				cout<<"staack is empty!";
			}
			else
			{
				int x=arr[top];
				top--;
				return x;
			}
		}
		void display()
		{
			if(top==-1)
			{
				cout<<"array is empty!"<<endl;
			}
			else
			{
			    cout<<"the stack elements are: ";
				for(int i=0;i<=top;i++)
				{
					cout<<arr[i]<<" ";
				}
				cout<<endl;
			}
		}
};
int main()
{
	stack s;
	int size=5;
	s.push(2);
	s.push(4);
	s.push(5);
	s.push(6);
	s.push(7);
	s.push(8);
	cout<<"-----------total elements: "<<endl;
	s.display();
	cout<<"\n----------after one pop: "<<endl;
	s.pop();
	s.display();
	cout<<"\n----------after second pop:"<<endl;
	s.pop();
	s.display();
//    int arr[size]={2,3,4,5,6};
//    for(int i=0;i<5;i++)
//    {
//    	s.push(arr[i]);
//    	cout<<"after"<<i+1<<" push"<<endl;
//    	s.display();
//    	
//	}
//	s.display();
	return 0;
}
