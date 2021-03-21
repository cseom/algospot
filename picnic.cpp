#include <iostream>
#include <cstring>
using namespace std;

bool friends[10][10];
bool taken[10];
int n, m;

int CountPairings()
{
	int firstFree = -1;
	for (int i = 0; i < n; i++)
	{
		if (!taken[i])
		{
			firstFree = i;
			break;
		}
	}
	if (firstFree == -1)
		return 1;
	int ret = 0;
	for (int PairWith = firstFree + 1; PairWith < n; PairWith++)
	{
		if (friends[firstFree][PairWith] && !taken[firstFree] && !taken[PairWith])
		{
			taken[firstFree] = taken[PairWith] = true;
			ret += CountPairings();
			taken[firstFree] = taken[PairWith] = false;
		}
	}
	return ret;
}


int main(void)
{
	int tc;
	scanf("%d", &tc);
	while (tc--)
	{
		memset(friends, false, sizeof(friends));
		memset(taken, false, sizeof(taken));
		scanf("%d %d", &n, &m);
		for (int i = 0; i < m; i++)
		{
			int student1, student2;
			scanf("%d %d", &student1, &student2);
			friends[student1][student2] = true;
			friends[student2][student1] = true;
		}
		printf("%d\n", CountPairings());
	}
}
