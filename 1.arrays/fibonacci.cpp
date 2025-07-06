#include <iostream>
using namespace std;
int fibonacci(int x)
{
	if (x <= 0) {
        return 0; 
    } 
	else if (x == 1) 
	{
        return 1; 
    }
	return fibonacci(x-1)+fibonacci(x-2);
}
int main()
{
	int x=9;
	cout<<"the 9th term of fibonacci series is: "<<fibonacci(x)<<endl;
	return 0;
}
