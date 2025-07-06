//ubaid ahmad     2410-0011
//Didar karim     2410-0098
//Hasan shah      2410-0099
#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

// Constants for array sizes
const int MAX_UNIVERSITIES = 10;
const int MAX_SCHOLARSHIPS = 10;
const int MAX_PROGRAMS = 5;
const int MAX_STRING_LENGTH = 100;

// Data Models
struct University {
    int id;
    char name[MAX_STRING_LENGTH];
    double gpa_requirement;
    char location[MAX_STRING_LENGTH];
    char programs[MAX_PROGRAMS][MAX_STRING_LENGTH];
    int num_programs; 
    int ranking;
    double tuition;
};

struct Scholarship 
{
    int id;
    char name[MAX_STRING_LENGTH];
    double min_gpa;
    char major[MAX_STRING_LENGTH];
    double award;
    char deadline[MAX_STRING_LENGTH];
};

struct User 
{
    int id;
    char name[MAX_STRING_LENGTH];
    double gpa;
    char major[MAX_STRING_LENGTH];
    char location[MAX_STRING_LENGTH];
};

// Stack for Recommendation History (based on task 2 stack using linked list.cpp)
struct StackNode 
{
    University data;
    StackNode* next;
    StackNode* prev;
    StackNode(University value, StackNode* next = NULL, StackNode* prev = NULL)
        {
        	data=value;
        	next=next;
        	prev=prev;
		}
};

class Stack 
{
private:
    StackNode* head;
    StackNode* tail;
public:
    Stack() 
	{
		head=NULL;
		tail=NULL;
	}

    bool isEmpty() 
	{
        if(head==tail)
        {
        	return true;
		}
		else
		{
			return false;
		}
    }

    void push(University value) 
	{
        StackNode* newnode = new StackNode(value);
        if (head != NULL) 
		{
            head->prev = newnode;
            newnode->next = head;
        }
        head = newnode;
        if (tail == NULL) 
		{
            tail = newnode;
        }
    }

    void pop() 
	{
        if (isEmpty()) 
		{
            cout << "Stack is empty!" << endl;
        } 
		else 
		{
            StackNode* temp = head;
            head = head->next;
            if (head != NULL) 
			{
                head->prev = NULL;
            } else {
                tail = NULL;
            }
            delete temp;
        }
    }

    void displayRecent() 
	{
        if (isEmpty()) 
		{
            cout << "No recommendations in history!" << endl;
        } 
		else 
		{
            cout << "Most Recent Recommendation: " << head->data.name 
                 << " (Ranking: " << head->data.ranking << ")" << endl;
        }
    }

    ~Stack() 
	{
        while (head != NULL) 
		{
            StackNode* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Queue for Scholarship Applications 
struct QueueNode 
{
    Scholarship data;
    QueueNode* next;
    QueueNode* prev;
    
    QueueNode(Scholarship value) 
	{
		data=value;
		next=NULL;
		prev=NULL;
	} 
};

class Queue 
{
private:
    QueueNode* front;
    QueueNode* rear;
public:
	Queue()
	{
		front=NULL;
		rear=NULL;
	}

    bool isEmpty() 
	{
		if(front==NULL)
		{
			return true;
		}  
		else
		{
			return false;
		 } 
    }

    void enqueue(Scholarship value) 
	{
        QueueNode* newnode = new QueueNode(value);
        if (isEmpty()) 
		{
            front = rear = newnode;
        } 
		else 
		{
            rear->next = newnode;
            newnode->prev = rear;
            rear = newnode;
        }
    }

    void display() 
	{
        if (isEmpty()) 
		{
            cout << "No applications yet!" << endl;
        } 
		else 
		{
            QueueNode* temp = front;
            cout << "Your Applications:" << endl;
            while (temp != NULL) 
			{
                cout << "- " << temp->data.name << " ($" << temp->data.award << ")" << endl;
                temp = temp->next;
            }
        }
    }

    ~Queue() 
	{
        while (front != NULL) 
		{
            QueueNode* temp = front;
            front = front->next;
            delete temp;
        }
    }
};

// BST for Universities 
struct BSTNode 
{
    University data;
    BSTNode* left;
    BSTNode* right;
    BSTNode(University value) 
	{
		data=value;
		left=NULL;
		right=NULL;
	}
};

class BST 
{
public:
    BSTNode* root;
    BST()
	{
		root=NULL;
	 } 

    BSTNode* insert(BSTNode* node, University value) 
	{
        if (node == NULL) 
		{
            return new BSTNode(value);
        }
        if (value.ranking < node->data.ranking) 
		{
            node->left = insert(node->left, value);
        } 
		else 
		{
            node->right = insert(node->right, value);
        }
        return node;
    }

    void insert(University value) 
	{
        root = insert(root, value);
    }

    void inorderTraversal(BSTNode* node, University* result, int& count) 
	{
        if (node != NULL) 
		{
            inorderTraversal(node->left, result, count);
            result[count++] = node->data;
            inorderTraversal(node->right, result, count);
        }
    }

    int getSorted(University* result) 
	{
        int count = 0;
        inorderTraversal(root, result, count);
        return count;
    }

    void deleteTree(BSTNode*& node) 
	{
        if (node == NULL) return;
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
        node = NULL;
    }

    ~BST() 
	{
        deleteTree(root);
    }
};

// Feature Implementations
void findUniversities(BST& bst, double gpa, const char* location, const char* program, University* results, int& resultCount) {
    University all[MAX_UNIVERSITIES];
    int numUniversities = bst.getSorted(all);
    resultCount = 0;
    for (int i = 0; i < numUniversities; i++) 
	{
        if (all[i].gpa_requirement <= gpa && strcmp(all[i].location, location) == 0) 
		{
            for (int j = 0; j < all[i].num_programs; j++) 
			{
                if (strcmp(all[i].programs[j], program) == 0) 
				{
                    results[resultCount++] = all[i];
                    break;
                }
            }
        }
    }
}

void findScholarships(const Scholarship* scholarships, int numScholarships, double gpa, const char* major, Scholarship* results, int& resultCount) {
    resultCount = 0;
    for (int i = 0; i < numScholarships; i++) 
	{
        if (scholarships[i].min_gpa <= gpa && strcmp(scholarships[i].major, major) == 0) 
		{
            results[resultCount++] = scholarships[i];
        }
    }
    // Sort by award amount (descending) using STL sort
    for (int i = 0; i < resultCount - 1; i++) {
        for (int j = 0; j < resultCount - i - 1; j++) 
		{
            if (results[j].award < results[j + 1].award) 
			{
                Scholarship temp = results[j];
                results[j] = results[j + 1];
                results[j + 1] = temp;
            }
        }
    }
}

void getRecommendations(BST& bst, User& user, Stack& recStack, University* results, int& resultCount) 
{
    University all[MAX_UNIVERSITIES];
    int numUniversities = bst.getSorted(all);
    resultCount = 0;
    for (int i = 0; i < numUniversities; i++) 
	{
        for (int j = 0; j < all[i].num_programs; j++) 
		{
            if (strcmp(all[i].programs[j], user.major) == 0) 
			{
                results[resultCount++] = all[i];
                recStack.push(all[i]);
                break;
            }
        }
    }
}

void loadSampleData(BST& bst, Scholarship* scholarships, int& numScholarships) 
{
    University u1, u2, u3,u4;
    u1.id = 1;
    strcpy(u1.name, "MIT");
    u1.gpa_requirement = 3.5;
    strcpy(u1.location, "USA");
    strcpy(u1.programs[0], "CS");
    strcpy(u1.programs[1], "Engineering");
    u1.num_programs = 2;
    u1.ranking = 1;
    u1.tuition = 50000;

  
    u2.id = 2;
    strcpy(u2.name, "Stanford");
    u2.gpa_requirement = 3.6;
    strcpy(u2.location, "USA");
    strcpy(u2.programs[0], "CS");
    strcpy(u2.programs[1], "Biology");
    u2.num_programs = 2;
    u2.ranking = 2;
    u2.tuition = 52000;

    u3.id = 3;
    strcpy(u3.name, "Harvard");
    u3.gpa_requirement = 3.7;
    strcpy(u3.location, "UK");
    strcpy(u3.programs[0], "Biology");
    strcpy(u3.programs[1], "Law");
    u3.num_programs = 2;
    u3.ranking = 3;
    u3.tuition = 55000;
    
    u4.id = 4;
    strcpy(u4.name, "Case");
    u4.gpa_requirement = 2.5;
    strcpy(u4.location, "Pakistan");
    strcpy(u4.programs[0], "CS");
    strcpy(u4.programs[1], "Engineering");
    strcpy(u4.programs[2], "Cyber Security");
    u4.num_programs = 3;
    u4.ranking = 20;
    u4.tuition = 100000;

    bst.insert(u1);
    bst.insert(u2);
    bst.insert(u3);
    bst.insert(u4);

    Scholarship s1, s2;
    s1.id = 1;
    strcpy(s1.name, "Merit Scholarship");
    s1.min_gpa = 3.0;
    strcpy(s1.major, "CS");
    s1.award = 10000;
    strcpy(s1.deadline, "2025-12-31");

    s2.id = 2;
    strcpy(s2.name, "Engineering Grant");
    s2.min_gpa = 3.2;
    strcpy(s2.major, "Engineering");
    s2.award = 8000;
    strcpy(s2.deadline, "2025-11-30");

    scholarships[0] = s1;
    scholarships[1] = s2;
    numScholarships = 2;
}

int main() 
{
    BST universities;
    Scholarship scholarships[MAX_SCHOLARSHIPS];
    int numScholarships = 0;
    Queue applications;
    Stack recStack;

    loadSampleData(universities, scholarships, numScholarships);

    User user; 
    cout << "\n|------------------------------------------------------|";
    cout << "\n ----------WELCOME TO STUDENT SUPPORT PROGRAM----------\n";
    cout << "|------------------------------------------------------|";
    while (true) 
	{
        cout << "\nMenu:\n1. Find Universities\n2. Find Scholarships\n3. Apply for Scholarship\n4. View Applications\n5. Get Recommendations\n6. View Recent Recommendation\n7. Exit\nEnter choice: ";
        int choice;
        cin >> choice;
        cin.ignore();

        if (choice == 7) 
		{
            cout << "Goodbye!\n";
            break;
        }

        switch (choice) 
		{
            case 1: 
			{
                cout << "Enter GPA: ";
                double gpa;
                cin >> gpa;
                cin.ignore();
                cout << "Enter Location (e.g., UK,USA,Pakistan): ";
                char location[MAX_STRING_LENGTH];
                cin.getline(location, MAX_STRING_LENGTH);
                cout << "Enter Program (e.g., CS,Engineering,Biologo,Law): ";
                char program[MAX_STRING_LENGTH];
                cin.getline(program, MAX_STRING_LENGTH);

                University results[MAX_UNIVERSITIES];
                int resultCount;
                findUniversities(universities, gpa, location, program, results, resultCount);
                cout << "\nMatching Universities:\n";
                if (resultCount == 0) cout << "None found.\n minumum gpa requirement for\nUK is :3.7\nUSA is:3.5 \nPakistan is:2.5 ";
                for (int i = 0; i < resultCount; i++) 
				{
                    cout << "- " << results[i].name << " (Ranking: " << results[i].ranking 
                         << ", Tuition: $" << results[i].tuition << ")\n";
                }
                break;
            }
            case 2: 
			{
                cout << "Enter GPA: ";
                double gpa;
                cin >> gpa;
                cin.ignore();
                cout << "Enter Major (e.g., CS,E): ";
                char major[MAX_STRING_LENGTH];
                cin.getline(major, MAX_STRING_LENGTH);

                Scholarship results[MAX_SCHOLARSHIPS];
                int resultCount;
                findScholarships(scholarships, numScholarships, gpa, major, results, resultCount);
                cout << "\nMatching Scholarships:\n";
                if (resultCount == 0) cout << "None found.\n";
                for (int i = 0; i < resultCount; i++) 
				{
                    cout << "- " << results[i].name << " ($" << results[i].award 
                         << ", Deadline: " << results[i].deadline << ")\n";
                }
                break;
            }
            case 3: 
			{
                cout << "Enter Scholarship amount to apply:\ni.e 8000\n  10000 ";
                int amount;
                cin >> amount;
                bool found = false;
                for (int i = 0; i < numScholarships; i++) 
				{
                    if (scholarships[i].award ==amount ) 
					{
                        applications.enqueue(scholarships[i]);
                        cout << "Applied for " << scholarships[i].name << "!\n";
                        found = true;
                        break;
                    }
                }
                if (!found) 
				{
                    cout << "Scholarship not found.\n";
                }
                break;
            }
            case 4: 
			{
                applications.display();
                break;
            }
            case 5: 
			{
                University results[MAX_UNIVERSITIES];
                int resultCount;
                getRecommendations(universities, user, recStack, results, resultCount);
                cout << "\nRecommended Universities:\n";
                if (resultCount == 0) cout << "None found.\n";
                for (int i = 0; i < resultCount; i++) 
				{
                    cout << "- " << results[i].name << " (Ranking: " << results[i].ranking << ")\n";
                }
                break;
            }
            case 6: 
			{
                recStack.displayRecent();
                break;
            }
            default:
                cout << "Invalid choice.\n";
        }
    }
    return 0;
}
