//ubaid ahmad    roll_no 2410-0011
#include <iostream>
using namespace std;

int pivot(int nums[], int size) 
{
    int totalSum = 0, leftSum = 0;
    for (int i = 0; i < size; i++)
        totalSum += nums[i];
    for (int i = 0; i < size; i++) 
    {
        if (leftSum == totalSum - leftSum - nums[i]) 
        {
        	return i;
		}
        leftSum += nums[i];
    }
    return -1;
}
int main() 
{
    int nums[] = {4,4,4,4,2,9,5,6,7};
    int size = sizeof(nums) / sizeof(nums[0]);
    cout << "Pivot Index: " << pivot(nums, size) << endl;
    return 0;
}
