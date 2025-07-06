#include <iostream>
using namespace std;
int binarySearch(int arr[],int first,int last,int key)
{
	while(first<=last)
	{
		int mid=first+(last-first)/2;
		if(arr[mid]==key)
		{
			return mid;
		}
		if(arr[mid]<key)
		{
			first=mid+1;
		}
		else
		{
			last=mid-1;
		}
	}
	return -1;
}
int main()
{
	int arr[]={1,2,3,4,5,6};
	int key=3;
	int first=0;
	int size=sizeof(arr)/sizeof(arr[0]);
	int last=size-1; 
	int result=binarySearch(arr,first,last,key);
	cout<<"the result is :"<<result<<endl;
	
	return 0;
}
