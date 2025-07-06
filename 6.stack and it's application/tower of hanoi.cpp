#include <iostream>
using namespace std;

void towerOfHanoi(int n, char source, char helper, char destination) 
{
    if(n == 1) 
	{
        cout << "Move disk 1 from " << source << " to " << destination << endl;
        return;
    }

    // Move n-1 disks from source to helper
    towerOfHanoi(n - 1, source, destination, helper);

    // Move nth disk from source to destination
    cout << "Move disk " << n << " from " << source << " to " << destination << endl;

    // Move n-1 disks from helper to destination
    towerOfHanoi(n - 1, helper, source, destination);
}

int main() 
{
    int N = 4;
    cout << "Steps to solve Tower of Hanoi for " << N << " disks:\n\n";
    towerOfHanoi(N, 'A', 'B', 'C');  
    return 0;
}

