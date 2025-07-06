#include <iostream>
using namespace std;
int linearSearch(int arr[],int size,int key)
{
	for(int i=0;i<size;i++)
	{
		if(arr[i]==key)
		{
			return i;
		}
	
	}
	return -1;
}
int main()
{
	int arr[]={2,3,4,5,6,7,8};
	int key=7;
	int size=sizeof(arr)/sizeof(arr[0]);
	int result=linearSearch(arr,size,key);
	cout<<"the term "<<key<<" is present at index: "<<result<<endl;
	return 0;
	
}
