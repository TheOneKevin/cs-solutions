#include <bits/stdc++.h>
using namespace std;
#define LSB(n) ((n) & -(n))

struct query
{
	int i, l, r, k;
};

bool comp(query a, query b)
{
	return a.k == b.k ? a.l > b.l /* Make sure all 0's go first */ : a.k > b.k;
}

int T;
long long BIT[100002], ans[100002];
vector<query> q;

long long sum(int n)
{
	long long sum = 0;
	for(int i = n; i > 0; i -= LSB(i))
		sum += BIT[i];
	return sum;
}

void add(int n, int k)
{
	for(int i = n; i <= T; i += LSB(i))
		BIT[i] += k;
}

int main()
{
	scanf("%d", &T);
	for(int i = 1, b; i <= T; i++)
		scanf("%d", &b), q.push_back({ 0, 0, i, b }), q.push_back({ i, 1, i, b });
	sort(q.begin(), q.end(), comp);
	for(int i = 0; i < 2 * T; i++)
	{
		if(q[i].i != 0)
			ans[q[i].i - 1] = sum(q[i].r) - sum(q[i].l - 1);
		else
			add(q[i].r, 1);
	}
	
	double sum = 0;
	for(int i = 0; i < T; i++)
		sum += ans[i] + 1;
	printf("%.2lf\n", sum / (double) T);
}