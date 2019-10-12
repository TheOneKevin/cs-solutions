#include <bits/stdc++.h>
using namespace std;
#define LSB(n) ((n) & -(n))

typedef pair<int, int> ip;

struct query
{
	int i, l, r, k;
};

// a > b
bool comp(query a, query b)
{
	return a.k > b.k;
}

int N, Q;
long long BIT[100002], ans[100002];
vector<query> q;
vector<ip> stuff;

long long sum(int n)
{
	long long sum = 0;
	for(int i = n; i > 0; i -= LSB(i))
		sum += BIT[i];
	return sum;
}

void add(int n, int k)
{
	for(int i = n; i <= N; i += LSB(i))
		BIT[i] += k;
}

int main()
{
	scanf("%d", &N);
	for(int i = 1, a; i <= N; i++)
		scanf("%d", &a), stuff.push_back({a, i});
	scanf("%d", &Q);
	for(int i = 0, l, r, k; i < Q; i++)
		scanf("%d %d %d", &l, &r, &k), q.push_back({i, l + 1, r + 1, k});
	
	sort(stuff.begin(), stuff.end(), greater<ip>());
	sort(q.begin(), q.end(), comp);
	
	int j = 0;
	for(int i = 0; i < Q; i++)
	{
		for(int k = j; k < N; k++) // This is madness, I liked my solution that didn't work better
		{
			if(q[i].k <= stuff[k].first)
			{
				add(stuff[k].second, stuff[k].first);
				j++;
			}
			else
				break;
		}
		ans[q[i].i] = sum(q[i].r) - sum(q[i].l - 1);
	}
	for(int i = 0; i < Q; i++)
		printf("%lld\n", ans[i]);
}
