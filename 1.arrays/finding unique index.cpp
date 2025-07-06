//ubaid ahmad    roll_no 2410-0011
#include <iostream>
using namespace std;

int UniqueIndex(int nums[], int size) 
{
    int max_num = nums[0];
    int max_index = 0;
    for (int i = 1; i < size; ++i) 
	{
        if (nums[i] > max_num) 
		{
            max_num = nums[i];
            max_index = i;
        }
    }

    for (int i = 0; i < size; ++i) 
	{
        if (i != max_index && max_num < 2 * nums[i]) 
		{
            return -1;
        }
    }

    return max_index;
}

int main() 
{
    int nums[] = {5,0,3,5,10,30};
    int size = sizeof(nums) / sizeof(nums[0]);

    cout <<"index of the unique number is: "<<UniqueIndex(nums, size) << endl;  
    return 0;
}

