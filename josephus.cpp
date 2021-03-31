#include <iostream>
#include <list>
using namespace std;

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
