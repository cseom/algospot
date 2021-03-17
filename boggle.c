#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

int dx[8] = { 0,0,-1,1,-1,-1,1,1 };
int dy[8] = { -1,1,0,0,-1,1,-1,1 };
bool hasWordcheck;

void hasWord(int x, int y, string ans, int cnt, string word, string board[5])
{
	if (!word.compare(ans))
	{
		hasWordcheck = true;
		return;
	}
	if (hasWordcheck)
		return;
	for (int k = 0; k < 8; k++)
	{
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5)
		{
			if (board[nx][ny] == word[cnt])
				hasWord(nx, ny, ans + board[nx][ny], cnt + 1, word, board);
		}
	}
	return;
}

int main(void)
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		int n;
		string board[5];
		for (int i = 0; i < 5; i++)
			cin >> board[i];
		cin >> n;
		vector<string> word(n);
		for (int i = 0; i < n; i++)
			cin >> word[i];
		for (int k = 0; k < n; k++)
		{
			hasWordcheck = false;
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					if (word[k][0] == board[i][j])
					{
						string firstword = "";
						firstword += word[k][0];
						hasWord(i, j, firstword, 1, word[k], board);
						if (hasWordcheck)
							break;
					}
				}
				if (hasWordcheck)
					break;
			}
			cout << word[k] << ' ';
			if (hasWordcheck)
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}
}
