#include <iostream>
using namespace std;
void inser(int arr[],int size)
{
	for(int i=1;i<size;i++)
	{
		int curr=arr[i];
		int prev=i-1;
		while(prev>=0&&arr[prev]>curr)
		{
			arr[prev+1]=arr[prev];
			prev--;
		}
		arr[prev+1]=curr;
	}
}
int main()
{
	int size=5;
	int arr[size]={2,5,1,3,6};
	inser(arr,size);
	for(int i=0;i<size;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return 0;
}
