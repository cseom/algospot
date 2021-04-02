#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int n;
int longest;
int x[100], y[100], radius[100];

struct TreeNode
{
	vector<TreeNode*> children;
};

int height(TreeNode* root)
{
	vector<int> heights;
	for (int i = 0; i < root->children.size(); i++)
		heights.push_back(height(root->children[i]));
	if (heights.empty())
		return 0;
	sort(heights.begin(), heights.end());

	if (heights.size() >= 2)
		longest = max(longest, 2 + heights[heights.size() - 2] + heights[heights.size() - 1]);
	return heights.back() + 1;
}

int solve(TreeNode* root)
{
	longest = 0;

	int h = height(root);
	return max(longest, h);
}

int sqr(int k)
{
	return k * k;
}

int sqrdist(int a, int b)
{
	return sqr(x[a] - x[b]) + sqr(y[a] - y[b]);
}

bool enclose(int a, int b)
{
	return radius[a] > radius[b] && sqrdist(a, b) < sqr(radius[a] - radius[b]);
}

bool isChild(int parent, int child)
{
	if (!enclose(parent, child))
		return false;
	for (int i = 0; i < n; i++)
	{
		if (i != parent && i != child && enclose(parent, i) && enclose(i, child))
			return false;
	}
	return true;
}

TreeNode* getTree(int root)
{
	TreeNode* ret = new TreeNode();
	for (int ch = 0; ch < n; ch++)
	{
		if (isChild(root, ch))
			ret->children.push_back(getTree(ch));
	}
	return ret;
}

int main(void)
{
	int tc;
	scanf("%d", &tc);
	while (tc--)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d %d %d", &x[i], &y[i], &radius[i]);
		TreeNode* T = getTree(0);
		printf("%d\n", solve(T));
	}
	return 0;
}
