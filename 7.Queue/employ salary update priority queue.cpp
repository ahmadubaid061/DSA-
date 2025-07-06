#include <iostream>
#include <string>
using namespace std;
struct node 
{
    string name;
    int work_hour;
    double salary;
    int priority;
    node* next;
    node* prev;

    node(string n, int p, int h, double s) 
	{
        name = n;
        priority = p;
        work_hour = h;
        salary = s;
        next = 0;
        prev = 0;
    }
};

class employ 
{
	private:
	node* head;
	node* tail;
	
	public:
	employ() 
	{
	    head = tail = 0;
	}
	
	bool isempty() 
	{
	    return head == 0;
	}
	
	void enqueue(string n, int p, int h, double s) 
	{
	    node* newnode = new node(n, p, h, s);
	    if (isempty()) 
		{
	        head = tail = newnode;
	    } else {
	        node* temp = head;
	        while (temp != 0 && temp->priority >= newnode->priority) 
			{
	            temp = temp->next;
	        }
	
	        if (temp == head) 
			{ 
	            newnode->next = head;
	            head->prev = newnode;
	            head = newnode;
	        } 
	        else if (temp == 0) 
			{ 
	            tail->next = newnode;
	            newnode->prev = tail;
	            tail = newnode;
	        } 
	        else 
			{
	            newnode->next = temp;
	            newnode->prev = temp->prev;
	            temp->prev->next = newnode;
	            temp->prev = newnode;
	        }
	    }
}

    double calculateSalary() 
	{
        double salary = 0;
        node* temp = head;
        while (temp != 0) 
		{
            salary += temp->salary;
            temp = temp->next;
        }
        return salary;
    }

    double increaseSalary() 
	{
        double salaryAfter = 0;
        node* temp = head;
        while (temp != 0) 
		{
            temp->salary += (temp->salary * temp->priority) / 100.0; 
            salaryAfter += temp->salary;
            temp = temp->next;
        }
        return salaryAfter;
    }

    void decreaseWorkHours() 
	{
        node* temp = head;
        while (temp != 0) 
		{
            if (temp->work_hour > 40) 
			{
                temp->work_hour = temp->work_hour * 0.9; 
            }
            temp = temp->next;
        }
    }

    void displayMoreThan40Hours() 
	{
        node* temp = head;
        while (temp != 0) 
		{
            if (temp->work_hour > 40) 
			{
                cout << "Name: " << temp->name << endl;
                cout << "Work Hours: " << temp->work_hour << endl;
                cout << "Salary: " << temp->salary << endl;
                cout << "Priority: " << temp->priority << endl;
                cout << "--------------------------" << endl;
            }
            temp = temp->next;
        }
    }
};

int main() 
{
    employ e;

    
    e.enqueue("Alice", 5, 45, 50000);
    e.enqueue("ubaid", 3, 42, 48000);
    e.enqueue("ahmad", 7, 38, 55000);
    e.enqueue("ali", 2, 41, 46000);
    e.enqueue("mujtaba", 4, 39, 47000);
    e.enqueue("didar", 1, 43, 49000);
    e.enqueue("hasan", 6, 40, 60000);
    e.enqueue("bakhti", 2, 44, 51000);
    e.enqueue("sonia shah", 8, 36, 62000);
    e.enqueue("alisha", 3, 46, 53000);

    cout << "Total Salary before Increase: " << e.calculateSalary() << endl;

    double salaryAfter = e.increaseSalary();
    cout << "Total Salary after Increase: " << salaryAfter << endl;

    e.decreaseWorkHours();

    cout << "\nEmployees working more than 40 hours after adjustment:\n";
    e.displayMoreThan40Hours();

    return 0;
}

