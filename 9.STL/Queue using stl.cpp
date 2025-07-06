#include <iostream>
#include <queue>
using namespace std;
queue<int> q; 
void enqueue(int value) 
{
    q.push(value);
    cout << value <<" is pushed:"<< endl;
}

void dequeue() 
{
    if (q.empty()) 
	{
        cout << "Queue is empty." << endl;
    } 
	else 
	{
        cout << q.front() <<" is popped:" <<endl;
        q.pop();
    }
}
void display() 
{
    if (q.empty()) 
	{
        cout << "Queue is empty." << endl;
        return;
    }

    queue<int> temp = q;  
    cout << "Queue elements: ";
    while (!temp.empty()) 
	{
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;
}

int main() 
{
    enqueue(5);
    enqueue(6);
    enqueue(7);
    display();
    dequeue();
    display();
    dequeue();
    dequeue();
    dequeue();  
    return 0;
}

