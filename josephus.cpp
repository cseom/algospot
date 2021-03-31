#include <iostream>
#include <queue>
#include <algorithm>
#include <list>
using namespace std;

/*
void josephus(int n, int k)
{
	queue<int> survivors;

	for (int i = 1; i <= n; i++)
		survivors.push(i);
	while (n > 2)
	{
		survivors.pop();
		n--;
		for (int i = 0; i < k - 1; i++)
		{
			int people = survivors.front();
			survivors.pop();
			survivors.push(people);
		}
	}
	int small = min(survivors.front(), survivors.back());
	int big = max(survivors.front(), survivors.back());
	printf("%d %d\n", small, big);
}
*/

void josephus(int n, int k)
{
	list<int> survivors;

	for (int i = 1; i <= n; i++)
		survivors.push_back(i);

	list<int>::iterator kill = survivors.begin();
	while (n > 2)
	{
		kill = survivors.erase(kill);
		if (kill == survivors.end())
			kill = survivors.begin();
		n--;
		for (int i = 0; i < k - 1; i++)
		{
			kill++;
			if (kill == survivors.end())
				kill = survivors.begin();
		}
	}
	printf("%d %d\n", survivors.front(), survivors.back());
}

int main(void)
{
	int tc;
	scanf("%d", &tc);
	while (tc--)
	{
		int n, k;
		scanf("%d %d", &n, &k);
		josephus(n, k);
	}

	return 0;
}
