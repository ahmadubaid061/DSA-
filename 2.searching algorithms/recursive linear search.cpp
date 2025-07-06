#include <iostream>
using namespace std;
int linearSearch(int arr[],int size,int key,int i=0)
{
	if(i==size)
	{
		return -1;
	}
	if(arr[i]==key)
	{
		return i;
	}
	linearSearch(arr,size,key,i+1);
}
int main()
{
	int arr[]={2,3,4,5,6,7,8};
	int key=7;
	int size=sizeof(arr)/sizeof(arr[0]);
	int result=linearSearch(arr,size,key);
	if(result==-1)
	{
		cout<<"the element is not found in the array!"<<endl;
	}
	else
	{
		cout<<"the element "<<key<<" is present at index: "<<result<<endl;
	}
	
	return 0;
}
