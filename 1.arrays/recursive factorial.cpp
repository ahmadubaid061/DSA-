#include <iostream>
using namespace std;
int fac(int numb)
{
	if(numb<=1)
 	  return 1;
	else
	return numb*fac(numb-1);
}
int main()
{
	int numb=5;
	int factorial=fac(numb);
	cout<<"the factorial of ("<<numb<<") is: "<<factorial<<endl;
	return 0;
}
