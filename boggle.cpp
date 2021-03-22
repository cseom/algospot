#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

int dx[8] = { 0,0,-1,1,-1,-1,1,1 };
int dy[8] = { -1,1,0,0,-1,1,-1,1 };
bool cache[5][5][10];
char board[5][5];

bool hasWord(int x, int y, const string &word, int idx)
{
	cache[x][y][idx] = true;
	if (y < 0 || x < 0 || x >= 5 || y >= 5)
		return false;
	if (board[x][y] != word[0])
		return false;
	if (word.size() == 1)
		return true;
	for (int dir = 0; dir < 8; dir++)
	{
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5)
			continue;
		if (cache[nx][ny][idx + 1])
			continue;
		if (hasWord(nx, ny, word.substr(1), idx + 1))
			return true;
	}
	return false;
}

int main(void)
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		int n;
		for (int i = 0; i < 5; i++)
			cin >> board[i];
		cin >> n;
		vector<string> word(n);
		for (int i = 0; i < n; i++)
			cin >> word[i];
		for (int i = 0; i < n; i++)
		{
			memset(cache, false, sizeof(cache));

			bool checkWord = false;
			for (int j = 0; j < 5; j++)
			{
				for (int k = 0; k < 5; k++)
				{
					if (hasWord(j, k, word[i], 0))
					{
						checkWord = true;
						break;
					}
				}
				if (checkWord)
					break;
			}
			cout << word[i] << ' ';
			if (checkWord)
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}
}
