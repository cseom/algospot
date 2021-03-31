#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

bool wellMatched(const string& formula)
{
	const string opening("({[");
	const string closing(")}]");

	stack<char> openStack;
	for (int i = 0; i < formula.size(); i++)
	{
		if (opening.find(formula[i]) != -1)
			openStack.push(formula[i]);
		else
		{
			if (openStack.empty())
				return false;
			if (opening.find(openStack.top()) != closing.find(formula[i]))
				return false;
			openStack.pop();
		}
	}
	return openStack.empty();
}

int main(void)
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		string formula;
		cin >> formula;
		if (wellMatched(formula))
			cout << "YES\n";
		else
			cout << "NO\n";

	}

	return 0;
}
