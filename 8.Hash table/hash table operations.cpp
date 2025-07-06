#include <iostream>
using namespace std;
const int size=5;
int roll[size];
string name[size];
void adddetails(int roll_no,string Name)
{
	int i;
	int hkey=roll_no%size;
	for(i=0;i<size;i++)
	{
		int index=(hkey+i)%size;
		if(roll[index]==NULL)
		{
			roll[index]=roll_no;
			name[index]=Name;
			cout<<"student details added at index:"<<index<<endl;
			break;
		}
	}
	if(i==size)
	cout<<"array is full!"<<endl;
}
int search(int value)
{
	int i;
	int hkey=value%size;
	
	for(i=0;i<size;i++)
	{
		int index=(hkey+i)%size;
		if(roll[index]==value)
		{			
			cout<<"student details found at index:"<<index<<" \nstudent roll no is:"<<roll[index]<<" \nstudent name is: "<<name[index]<<endl;
			break;
		}	
	}
}
void deletestudent(int value) 
{
    int hkey = value % size;
    for (int i = 0; i < size; i++) 
	{
        int index = (hkey + i) % size;
        if (roll[index] == value) {
            roll[index] = NULL; 
            name[index] = "";
            cout << "Student deleted from index: " << index << endl;
            return;
        }
        if (roll[index] == NULL)
            break;
    }
    cout << "Student not found to delete!" << endl;
}
void display()
{
	int i;
	for(i=0;i<size;i++)
	{
		if(name[i]==""&&roll[i]==NULL)
		{
			cout<<"\nstudent is removed!"<<endl;
		}
		else
		{
			cout<<" \n student :"<<i+1<<endl;
			cout<<"name :"<<name[i]<<"\nroll_no: "<<roll[i]<<endl;
		}		
	}
}
int main()
{
	adddetails(21,"ahmad");
	adddetails(22,"bakhti");
	adddetails(25,"ali");
	adddetails(23,"ubaid");
	adddetails(24,"umar");
	adddetails(26,"arv");
	display();
	search(23);
	deletestudent(23);
	cout<<"\n\n After DELETION"<<endl;
	display();
	return 0;
}
