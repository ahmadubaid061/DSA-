#include <iostream>
using namespace std;
struct node
{
	int data;
	node* Prev;
	node* Next;
	node(int value,node* prev=0,node* next=0)
	{
		data =value;
		Prev=prev;
		Next=next;
	}
};
class doublylist
{
	public:
		node* head;
		node* tail;
		doublylist()
		{
			head=tail=0;
		}
		//insert at tail
		void insert(int value)
		{
			if(tail!=0)
			{
				tail->Next=new node(value,tail,0);
				tail=tail->Next;
			}
			else
			{
				head=tail=new node(value);
			}
		}
//		find node with mXIMUM VALUE
		node* max()
		{
			if(head==0)
			{
				return 0;
			}
			else
			{
				node* max_node=head;
				int max_value=0;
				node* temp=head;
				while(temp!=0)
				{
					if(temp->data>max_value)
					{
						max_value=temp->data;
						max_node=temp;
					}
					temp=temp->Next;
				}
				return max_node;
			}
			
		}
		//Delete max_node
		void deletemax()
		{
			node* max_node=max();
			if(max_node==0)
			{
				cout<<"list is empty"<<endl;
				return;
			}
			else if(head==tail)
			{
				delete head;
				head=tail=0;
			}
			else if(max_node==head)
			{
				head=head->Next;
				head->Prev=0;
				delete max_node;
				
			}
			else if (max_node == tail) 
			{
                tail = tail->Prev;
                tail->Next = 0;
                delete max_node;
            }
			else
			{
				max_node->Next->Prev=max_node->Prev;
				max_node->Prev->Next=max_node->Next;
				delete max_node;
				
				
			}
			
		}
//		DISPLAY LIST
    void display()
    {
    	node* temp=head;
    	while(temp!=0)
    	{
    		cout<<temp->data<<" ";
    		temp=temp->Next;
		}
		cout<<endl;
	}
	
};
int main()
{
	doublylist list;
	list.insert(20);
	list.insert(25);
	list.insert(15);
	list.insert(35);
	list.display();
	node* result=list.max();
	cout<<"the maximum value node is: "<<result->data<<endl;
	list.deletemax();
//	CHECKING IF DELETED OR NOT
	cout<<"AFTER DELETING MAXIMUM :"<<endl;
	list.display();
	
	result=list.max();
	cout<<"the maximum is: "<<result->data<<endl;
	return 0;
}
