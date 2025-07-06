#include <iostream>
#include <stack>
#include <string>
using namespace std;
bool isPalindrome(const string& str) 
{
    stack<char> s;
   
    for (int i = 0; i < str.length(); i++) 
	{
        s.push(str[i]);
    }
    for (int i = 0; i < str.length(); ++i) 
	{
        if (str[i] != s.top()) 
		{
            return false; 
        }
        s.pop();
    }

    return true;  
}

int main() 
{
    string str="EYE";
    string str2="DSA";
    cout<<"the string: "<<str;
    if (isPalindrome(str)) 
	{
        cout << " is a palindrome." << endl;
    } 
	else 
	{
        cout << " is not a palindrome." << endl;
    }
    cout<<"the string: "<<str2;
    if (isPalindrome(str2)) 
	{
        cout << " is a palindrome." << endl;
    } 
	else 
	{
        cout << " is not a palindrome." << endl;
    }
    return 0;
}

