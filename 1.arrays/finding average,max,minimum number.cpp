#include <iostream>
using namespace std;
void calAve(int *arr,int size,int &sum,int &Average)
{
	for(int i=0;i<size;i++)
	{
		sum+=arr[i];
	}
	Average=sum/size;
}
void maxTem(int* arr,int size,int &highestTem)
{
	highestTem=arr[0];
	for(int i=0;i<size;i++)
	{
		if(arr[i]>highestTem)
		{
			highestTem=arr[i];
		}
	}
}
void minTem(int* arr,int size,int &lowestTem)
{
	lowestTem=arr[0];
	for(int i=0;i<size;i++)
	{
		if(arr[i]<lowestTem)
		{
			lowestTem=arr[i];
		}
	}
}
int main()
{
	int size=5;
	int arr[size]={23,45,37,33,44};
	int sum=0;
	int Average=0;
	int highestTem=0;
	int lowestTem=0;
	calAve(arr,size,sum,Average);
	cout<<" average is: "<<Average<<endl;
	maxTem(arr,size,highestTem);
	cout<<" amximum temprature is: "<<highestTem<<endl;
	minTem(arr,size,lowestTem);
	cout<<" minimum temprature is: "<<lowestTem<<endl;
	return 0;	
}
