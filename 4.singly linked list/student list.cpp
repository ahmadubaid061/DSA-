#include <iostream>
#include <string>
using namespace std;

struct student 
{
    string S_name;
    int Roll_no;
    string Department;
    int Gpa;
    student* next;
    
    student(string name, int roll, string dep, int gpa) 
	{
        S_name = name;
        Roll_no = roll;
        Department = dep;
        Gpa = gpa;
        next = NULL;
    }
};

class studentlist 
{
private:
    student* head;
    student* tail;

public:
    studentlist() 
	{
        head = tail = NULL;
    }

    ~studentlist() 
	{
        student* temp = head;
        while (temp != NULL) 
		{
            student* next = temp->next;
            delete temp;
            temp = next;
        }
        head = tail = NULL;
    }

    void insertAthead(string name, int roll, string dep, int gpa) 
	{
        student* newstudent = new student(name, roll, dep, gpa);
        newstudent->next = head;
        head = newstudent;
        if (tail == NULL) 
		{ 
            tail = newstudent;
        }
    }

    void insertAttail(string name, int roll, string dep, int gpa) 
	{
        student* newstudent = new student(name, roll, dep, gpa);
        if (head == NULL) 
		{
            head = tail = newstudent;
        } 
		else 
		{
            tail->next = newstudent;
            tail = newstudent;
        }
    }

    void insertAfter(student* prevStudent, string name, int roll, string dep, int gpa) 
	{
        if (prevStudent == NULL) 
		{
            cout << "Previous node should not be null." << endl;
            return;
        }
        student* newstudent = new student(name, roll, dep, gpa);
        newstudent->next = prevStudent->next;
        prevStudent->next = newstudent;
        if (newstudent->next == NULL) 
		{ 
            tail = newstudent;
        }
    }

    // Search by name
    student* searchstudent(string name) 
	{
        student* temp = head;
        while (temp != NULL) 
		{
            if (temp->S_name == name) 
			{
                return temp;
            }
            temp = temp->next; 
        }
        return NULL; 
    }

    // Search by roll number
    student* searchstudentRollNo(int roll) 
	{
        student* temp = head;
        while (temp != NULL) 
		{
            if (temp->Roll_no == roll) 
			{
                return temp;
            }
            temp = temp->next; 
        }
        return NULL; 
    }

    void display() 
	{
        if (head == NULL) 
		{
            cout << "List is empty." << endl;
            return;
        }
        student* temp = head;
        while (temp != NULL) 
		{
            cout << "Name: " << temp->S_name << ", Roll No: " << temp->Roll_no
                 << ", GPA: " << temp->Gpa << ", Department: " << temp->Department << endl;
            temp = temp->next;
        }
    }
};

int main() 
{
    studentlist s;
    s.insertAthead("ubaid", 11, "CS", 3);
    s.insertAttail("ahmad", 31, "AI", 2);

    // Search by name
    student* ubaid = s.searchstudent("ubaid");
    if (ubaid != NULL) 
	{
        s.insertAfter(ubaid, "ali", 12, "SE", 4);
    } 
	else {
        cout << "Student 'ubaid' not found." << endl;
    }

    // Search by roll number
    student* roll_no = s.searchstudentRollNo(11); 
    if (roll_no != NULL) 
	{
        s.insertAfter(roll_no, "bakhti", 14, "CyberS", 4);
    } 
	else {
        cout << "Student with roll number 11 not found." << endl;
    }

    s.display();
    return 0;
}
