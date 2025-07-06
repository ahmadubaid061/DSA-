#include <iostream>
using namespace std;
class unique
{
	private:
		int Unique;
		public:
			unique()
			{
				Unique=0;
			}
			int UniqueElement(int arr[],int size)
			{
				Unique=arr[0];
				for(int i=0;i<size;i++)
				{
				    if(arr[i]>Unique)
					{
						Unique=arr[i];
					}	
				}
				for(int i=0;i<size;i++)
				{
					if(arr[i]!=Unique&&arr[i]*2<=Unique)
					{
						return Unique;
					}
					return -1;
				}
				
			}
};
int main()
{
	int arr[]={2,3,4,5,15,6};
	int size=sizeof(arr)/sizeof(arr[0]);
	unique u;
	int result=u.UniqueElement(arr,size);
	cout<<"unique element is: "<<result<<endl;
	return 0;
}
