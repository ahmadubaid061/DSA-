#include <iostream>
using namespace std;
class Stack 
{
    int arr[100];
    int top;
public:
    Stack() 
	{ 
	    top = -1; 
	}

    void push(int num) 
	{
        arr[++top] = num;
    }

    int pop() 
	{
        return arr[top--];
    }
};

// Check if character is operator
bool isOperator(char ch) 
{
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

// Function to evaluate postfix expression
int evaluatePostfix(char postfix[]) 
{
    Stack st;
    int i = 0;

    while(postfix[i] != '\0') 
	{
        char ch = postfix[i];

        if(ch >= '0' && ch <= '9') 
		{
            st.push(ch - '0'); 
        }
        else if(isOperator(ch)) 
		{
            int b = st.pop();
            int a = st.pop();
            int result = 0;

            if(ch == '+') result = a + b;
            else if(ch == '-') result = a - b;
            else if(ch == '*') result = a * b;
            else if(ch == '/') result = a / b;

            st.push(result);
        }

        i++;
    }

    return st.pop(); 
}

int main() 
{
    char postfix[100];

    cout << "Enter Postfix Expression (e.g., 324*+5-): ";
    cin >> postfix;

    int result = evaluatePostfix(postfix);
    cout << "Answer: " << result << endl;

    return 0;
}

