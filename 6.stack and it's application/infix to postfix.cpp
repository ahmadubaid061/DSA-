#include <iostream>
using namespace std;

// Simple Stack class for characters
class Stack {
    char arr[100];
    int top;
public:
    Stack() { top = -1; }

    void push(char ch) {
        arr[++top] = ch;
    }

    char pop() {
        return arr[top--];
    }

    char peek() {
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }
};

int getPriority(char op) 
{
    if(op == '*' || op == '/')
	{
		return 2;
	 } 
	
    if(op == '+' || op == '-') 
	{
	    return 1;	
	}
    return 0;
}

// Check if character is operator
bool isOperator(char ch) 
{
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

// Function to convert Infix to Postfix
void infixToPostfix(char infix[], char postfix[]) 
{
    Stack st;
    int i = 0, j = 0;

    while(infix[i] != '\0') 
	{
        char ch = infix[i];

        if((ch >= '0' && ch <= '9') || (ch >= 'A' && ch <= 'Z')) 
		{
            postfix[j++] = ch;
        }
        else if(ch == '(') 
		{
            st.push(ch);
        }
        else if(ch == ')') 
		{
            while(!st.isEmpty() && st.peek() != '(') 
			{
                postfix[j++] = st.pop();
            }
            st.pop(); // Remove '('
        }
        else if(isOperator(ch)) 
		{
            while(!st.isEmpty() && getPriority(st.peek()) >= getPriority(ch)) 
			{
                postfix[j++] = st.pop();
            }
            st.push(ch);
        }

        i++;
    }

    while(!st.isEmpty()) 
	{
        postfix[j++] = st.pop();
    }

    postfix[j] = '\0';
}

int main() 
{
    char infix[100];
    char postfix[100];

    cout << "Enter Infix Expression: ";
    cin >> infix;

    infixToPostfix(infix, postfix);

    cout << "Postfix Expression: " << postfix << endl;

    return 0;
}

