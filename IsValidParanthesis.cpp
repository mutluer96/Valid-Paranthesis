#include<iostream>
#include<stack>
#include<string>

using namespace std;

bool isValid(string str)
{
	stack<char> kutu;
	int len = str.length();
	for (int i = 0; i < len; i++)
	{
		if (str[i] == '(' || str[i] == '{' || str[i] == '[') kutu.push(str[i]);
		else if (str[i] == ')' || str[i] == '}' || str[i] == ']')
		{
			if (kutu.empty()) return false;
			else if (str[i] == ')'&&kutu.top() != '(') return false;
			else if (str[i] == '}'&&kutu.top() != '{') return false;
			else if (str[i] == ']'&&kutu.top() != '[') return false;
			else kutu.pop();
				
		}

	}
	if (kutu.empty()) return true;
	else return false;

}

int main()
{
	string tryo = "3-[4]{[(4+7)]}[]";
	cout << "The string to be checked whether paranthesis' are valid or not is: " + tryo + " \n";
	bool v = isValid(tryo);
	if (v == true)
	{
		cout << "valid\n";
	}
	else
		cout << "not valid\n";
	
	system("Pause");
	return 0;
}