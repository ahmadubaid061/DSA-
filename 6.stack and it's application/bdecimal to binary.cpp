#include <iostream>
using namespace std;
const int size=5;
class stack
{
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
	int pop()
	{
		if(top==-1)
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
	int convertTobinary(stack* s,int value)
	{
		while(value>0)
		{
			s->push(value%2);
			value=value/2;
		}
		while(top!=-1)
		{
			int x=s->pop();
			cout<<x<<" "; 
		}
	}
};
int main()
{
	stack s;
	s.convertTobinary(&s,10);
	cout<<"\n";
	s.convertTobinary(&s,15);
	return 0;
}
