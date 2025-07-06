#include <iostream>
using namespace std;
double power(int base,int exponent)
{
	if(exponent==0)
	{
		return 1;
	}
	return base * power(base, exponent - 1);
}
int main()
{
	int base=5;
	int exponent=2;
	cout<<"5 ^ 2: "<<power(base,exponent)<<endl;
	return 0;
}
