#include <iostream>
using namespace std;

const int TABLE_SIZE = 7;

class Node 
{
public:
    int data;
    Node* next;

    Node(int value) 
	{
        data = value;
        next = NULL;
    }
};

class LinkedList 
{
private:
    Node* head;

public:
    LinkedList() 
	{
        head = NULL;
    }
     bool search(int value) 
	{
        Node* temp = head;
        while (temp != NULL) 
		{
            if (temp->data == value)
                return true;
            temp = temp->next;
        }
        return false;
    }
    void insert(int value) 
	{
        if (!search(value)) 
		{
            Node* newNode = new Node(value);
            newNode->next = head;
            head = newNode;
        } else {
            cout << "Value " << value << " already exists in chain.\n";
        }
    }

    
    void delet(int value) 
	{
        Node* temp = head;
        Node* prev = NULL;

        while (temp != NULL) 
		{
            if (temp->data == value) 
			{
                if (prev == NULL) 
				{
                    head = temp->next;
                } else {
                    prev->next = temp->next;
                }
                delete temp;
                cout << "Value " << value << " deleted.\n";
                return;
            }
            prev = temp;
            temp = temp->next;
        }

        cout << "Value " << value << " not found to delete.\n";
    }
    void display() 
	{
        Node* temp = head;
        while (temp != NULL) 
		{
            cout << temp->data << "  ";
            temp = temp->next;
            
        }
//        cout << "NULL";
    }
};
class hashtable
{
	private:
	LinkedList table[TABLE_SIZE];
	public:
		void insert(int key)
		{
			int index=key%TABLE_SIZE;
			table[index].insert(key);
		}
		void search(int key)
		{
			int index=key%TABLE_SIZE;
			if (table[index].search(key))
		        cout << "Key " << key << " found at index " << index << endl;
		    else
		        cout << "Key " << key << " not found.\n";

		}
		void remove(int key) 
		{
	        int index = key%TABLE_SIZE;
	        table[index].delet(key);
        }
        void display() 
		{
	        cout << "\n--- Hash Table Contents ---\n";
	        for (int i = 0; i < TABLE_SIZE; i++) 
			{
		        cout << "Index " << i << ": ";
		        table[i].display();
		        cout << endl;
    		}
    	}
};
int main()
{
	hashtable t;

    t.insert(14);
    t.insert(15);
    t.insert(4);
    t.insert(20);
    t.insert(5);
    t.insert(6);
    t.insert(18);

    t.display();

    t.search(20);
    t.search(9);

//     t.delet(20);
//    cout<<"DISPLAY AFTER DELETION:\n"<<endl;
//    t.display();

    return 0;
}

