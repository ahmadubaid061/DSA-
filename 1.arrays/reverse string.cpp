#include <iostream>
#include <vector>
using namespace std;
void reversestr(vector<int> &s)
{
	int left=0;
	int right=s.size()-1;
	while(left<right)
	{
		swap(s[left],s[right]);
		left++;
		right--;
	}
}
int main()
{
	vector<int> s={1,2,3,4,5,6};
	reversestr( s);
	for(int i:s)
	{
		cout<<i<<" ";
	}
	cout<<endl;
	return 0;
}
