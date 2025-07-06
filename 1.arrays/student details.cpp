#include <iostream>
#include <string>
using namespace std;
class student
{
	public:
		string name;
		int regNo;
	    string courses[5];
	void getStudent(student* s)
	{
		cout<<"\nenter student name: ";
		cin.ignore();
		getline(cin,s->name);
		cout<<"\nenter registration number: ";
		cin>>s->regNo;
		cin.ignore();
		cout<<"\nenter 5 courses : ";
		for(int i=0;i<5;i++)
		{
			getline(cin,s->courses[i]);
		}
	}
	void displayStudent(student* s)
	{
		cout<<"\nName  is:  "<<s->name<<endl;
		cout<<"Reg_No is:   "<<s->regNo<<endl;
		cout<<"courses are: ";
		for(int i=0;i<5;i++)
		{
			cout<<s->courses[i]<<", ";
		}
		cout<<endl;
	}
};

int main()
{
	student s;
	for(int i=1;i<=5;i++)
	{
		cout<<"\n......STUDENT:"<<i<<"....."<<endl;
		s.getStudent(&s);
		cout<<"\nstudent details are:"<<endl;
		s.displayStudent(&s);
	}
	return 0;
}
