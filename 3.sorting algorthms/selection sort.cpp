#include <iostream>
using namespace std;
void bubblesort(int arr[],int size)
{
	for(int i=0;i<size-1;i++)
	{
		for(int j=0;j<size-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				swap(arr[j],arr[j+1]);
			}
		}
	}
}
int main()
{
	int arr[]={8,6,5,4,3,2,1};
	int size=sizeof(arr)/sizeof(arr[0]);
	bubblesort(arr,size);
	cout<<"the sorted array is: ";
	for(int i=0;i<size;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return 0;
}

