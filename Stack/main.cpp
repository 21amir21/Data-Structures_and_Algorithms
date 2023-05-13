#include <iostream>
#include "Stack.h"
#include <stack>
#include <string>
using namespace std;

// Question 1 Lab 2
// int main() {
//
//	Stack stack(20);
//
//	string str;
//
//	getline(cin, str);
//
//	for (int i = 0; i < str.length(); i++) {
//		stack.push(str[i]);
//	}
//
//	for (int i = 0; i < str.length(); i++) {
//		str[i] = (char)stack.top();
//		stack.pop();
//	}
//
//	cout << str << endl;
//
//	return 0;
//}

// Q2 Lab 2
// int main() {
//
//	Stack stack(20);
//
//	int num;
//	cout << "Please enter a number: " << endl;
//	cin >> num;
//
//	for (int i = 2; i <= num; i++) {
//		while (num % i == 0) {
//			stack.push(i);
//			num /= i;
//		}
//	}
//
//	stack.Display();
//
//
//	return 0;
//}

// Q3 Lab 3
// int main() {
//
//	cout << "Please enter the length of the series" << endl;
//	int len;
//	cin >> len;
//	Stack stack(len);
//
//	for (int i = 0; i <= len; i++) {
//		if (i == 0) {
//			stack.push(i);
//			cout << "0 ";
//		}
//		else if (i == 1) {
//			stack.push(i);
//		}
//		else {
//			int temp1 = stack.pop();
//			int temp2 = stack.pop();
//			int c = temp1 + temp2;
//			cout << temp1 << " ";
//			stack.push(temp1);
//			stack.push(c);
//		}
//	}
//
//	return 0;
//}

// Q4 Lab 2
// int main() {
//
//	Stack stack(10);
//
//	for (int i = 0; i < 5; i++) {
//		stack.push(i + 1);
//	}
//
//	if (stack.isEmpty() == false) {
//		cout << stack.top();
//	}
//	else {
//		cout << "Stack is Empty" << endl;
//	}
//
//	return 0;
//}

// Q5 Lab 2 // Checking for Balanced Parentheses // VIP ----> rag3oo !!

// arePair is a helper function for isBalanced
bool arePair(char open, char close)
{ // openBracket, closedBracket

    if (open == '{' && close == '}')
    {
        return true;
    }
    else if (open == '(' && close == ')')
    {
        return true;
    }
    else if (open == '[' && close == ']')
    {
        return true;
    }

    return false; // if it doesnt enter any of the above ifs
}

bool isBalanced(string exp)
{

    stack<char> s;

    for (int i = 0; i < exp.length(); i++)
    {

        if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[')
        {
            s.push(exp[i]);
        }
        else if (exp[i] == '}' || exp[i] == ')' || exp[i] == ']')
        {

            if (s.empty() || !arePair(s.top(), exp[i]))
            {
                return false;
            }
            else
            {
                s.pop();
            }
        }
    }

    if (s.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

// int main() {
//
//	string exper;
//	cout << "Enter Expression" << endl;
//	cin >> exper;
//
//	if (isBalanced(exper)) {
//		cout << "Balanced" << endl;
//	}
//	else
//		cout << "Not Balanced" << endl;
//
//	return 0;
//}

// Write a program to convert a Postfix to Prefix expression
bool isOperator(char x)
{
    switch (x)
    {
    case '+':
    case '-':
    case '*':
    case '/':
        return true;
    }
    return false;
}

string postfixToPrefix(string post_exp)
{

    stack<string> s;
    int length = post_exp.length();

    for (int i = 0; i < length; i++)
    {
        if (isOperator(post_exp[i]))
        {
            string op2 = s.top();
            s.pop();
            string op1 = s.top();
            s.pop();
            string temp = post_exp[i] + op1 + op2; // if conver to infix ---> op1 + post_exp[i] + op2;
            s.push(temp);
        }
        else
        {
            s.push(string(1, post_exp[i]));
        }
    }
    return s.top();
}

// int main() {
//
//	string post_exp = "ABC/-AK/L-*";
//	cout << "Prefix: " << postfixToPrefix(post_exp);
//
//	return 0;
//}

// Write a program to convert a Prefix to Postfix expression
bool isOperator(char x)
{
    switch (x)
    {
    case '+':
    case '-':
    case '*':
    case '/':
        return true;
    }
    return false;
}

string prefixToPostfix(string pre_exp)
{

    stack<string> s;
    int length = pre_exp.length();

    for (int i = length - 1; i >= 0; i--)
    {
        if (isOperator(pre_exp[i]))
        {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            string temp = op1 + op2 + pre_exp[i]; // if conver to infix ---> op1 + post_exp[i] + op2;
            s.push(temp);
        }
        else
        {
            s.push(string(1, pre_exp[i]));
        }
    }
    return s.top();
}

// int main() {
//
//	string pre_exp = "*-A/BC-/AKL";
//	cout << "Postfix: " << prefixToPostfix(pre_exp);
//
//	return 0;
//}

// Write a program to evaluate the Postfix expression
bool isOperator(char x)
{
    switch (x)
    {
    case '+':
    case '-':
    case '*':
    case '/':
        return true;
    }
    return false;
}

double evalPostfix(string post_exp)
{
    stack<double> s;
    int length = post_exp.length();

    for (int i = 0; i < length; i++)
    {
        double temp;
        if (isOperator(post_exp[i]))
        {
            double op2 = s.top();
            s.pop();
            double op1 = s.top();
            s.pop();

            if (post_exp[i] == '+')
            {
                temp = op1 + op2;
            }
            else if (post_exp[i] == '-')
            {
                temp = op1 - op2;
            }
            else if (post_exp[i] == '*')
            {
                temp = op1 * op2;
            }
            else if (post_exp[i] == '/')
            {
                temp = op1 / op2;
            }
            s.push(temp);
        }
        else
        {
            if (isdigit(post_exp[i]))
            {
                s.push(post_exp[i] - '0');
            }
        }
    }
    return s.top();
}

int main()
{

    string exp = "231*+9-";
    cout << "Postfix evaluation: " << evalPostfix(exp);
    ;

    return 0;
}
