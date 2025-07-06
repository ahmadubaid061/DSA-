#include <iostream>
using namespace std;

struct Node {
	int data;
	int priority;
	Node* next;
	Node* prev;

	Node(int value, int p) {
		data = value;
		priority = p;
		next = 0;
		prev = 0;
	}
};

class PriorityQueue {
	private:
		Node* front;
		Node* rear;

	public:
		PriorityQueue() {
			front = rear = 0;
		}

		bool isempty() {
			if(front==0) {
				return true;
			} else {
				return false;
			}
		}

		int peek() {
			if (isempty()) {
				cout << "Nothing to print!" << endl;
				return -1;
			} else {
				return front->data;
			}
		}

		// Enqueue based on priority
		void Enqueue(int value, int p) {
			Node* newnode = new Node(value, p);
			if (isempty()) {
				front = rear = newnode;
			} else {
				Node* temp = front;
				while (temp != 0 && temp->priority >= newnode->priority) {
					temp = temp->next;
				}

				if (temp == front) {
					newnode->next = front;
					front->prev = newnode;
					front = newnode;
				} else if (temp == 0) {
					rear->next = newnode;
					newnode->prev = rear;
					rear = newnode;
				} else {
					newnode->next = temp;
					newnode->prev = temp->prev;
					temp->prev->next = newnode;
					temp->prev = newnode;
				}
			}
		}

		int Dequeue() {
			if(isempty()) {
				cout<<"nothing to print!"<<endl;
			} else {
				Node* temp=front;
				front=front->next;
				front->next->prev=0;

				return temp->data;
				delete temp;
			}
		}

		void display() {
			if (isempty()) {
				cout << "Queue is empty!" << endl;
			} else {
				Node* temp = front;
				while (temp != 0) {
					cout << "(" << temp->data << ", p=" << temp->priority << ") ";
					temp = temp->next;
				}
				cout << endl;
			}
		}
};

int main() {
	PriorityQueue pq;

	pq.Enqueue(10, 8);
	pq.Enqueue(8, 6);
	pq.Enqueue(7, 5);
	pq.Enqueue(6, 3);
	pq.Enqueue(5, 2);

	cout << "Priority Queue elements:" << endl;
	pq.display();

	cout << "After first deletion:" << endl;
	int result = pq.Dequeue();
	pq.display();
	cout << "The element value deleted is: " << result << endl;

	int x = pq.peek();
	cout << "The peek value is: " << x << endl;

	return 0;
}

