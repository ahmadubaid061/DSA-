#include <iostream>
#include <stack>
using namespace std;

void moveDisk(stack<int>& src, stack<int>& dest, char s, char d, int& moveCount) 
{
    if (src.empty()) 
	{
        int top = dest.top();
        dest.pop();
        src.push(top);
        cout << "Move disk " << top << " from " << d << " to " << s << endl;
        moveCount++;  
        return;
    }
    if (dest.empty()) 
	{
        int top = src.top();
        src.pop();
        dest.push(top);
        cout << "Move disk " << top << " from " << s << " to " << d << endl;
        moveCount++;  
        return;
    }
    if (src.top() > dest.top()) 
	{
        int top = dest.top();
        dest.pop();
        src.push(top);
        cout << "Move disk " << top << " from " << d << " to " << s << endl;
        moveCount++; 
    } 
	else 
	{
        int top = src.top();
        src.pop();
        dest.push(top);
        cout << "Move disk " << top << " from " << s << " to " << d << endl;
        moveCount++;  
    }
}

void towerOfHanoi(int numDisks, char srcRod, char auxRod, char destRod) 
{
    stack<int> src, aux, dest;
    int moveCount = 0;  
    if (numDisks % 2 == 0) 
	{
        swap(destRod, auxRod);
    }

    int totalMoves = 1;
    for (int i = 0; i < numDisks; i++) 
	{
        totalMoves *= 2;
    }
    totalMoves -= 1;

    for (int i = numDisks; i >= 1; i--) 
	{
        src.push(i);
    }

    for (int i = 1; i <= totalMoves; i++) 
	{
        if (i % 3 == 1)
            moveDisk(src, dest, srcRod, destRod, moveCount);
        else if (i % 3 == 2)
            moveDisk(src, aux, srcRod, auxRod, moveCount);
        else if (i % 3 == 0)
            moveDisk(aux, dest, auxRod, destRod, moveCount);
    }

 
    cout << "\nTotal number of moves: " << moveCount << endl;
}

int main() 
{
    int n;
    cout << "Enter number of disks: ";
    cin >> n;

    
    towerOfHanoi(n, 'A', 'B', 'C');  

    return 0;
}

