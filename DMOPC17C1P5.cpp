#include <bits/stdc++.h>
using namespace std;
#define LSB(n) ((n) & -(n))

typedef pair<int, int> ip;

struct query
{
	int i, l, r;
};

int N, Q, A[1000005], BIT[1000005], ans[1000005];
vector<query> q;
stack<ip> s;

bool comp(query a, query b)
{
	return a.l > b.l;
}

int sum(int n)
{
	int sum = 0;
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
	scanf("%d %d", &N, &Q);
	for(int i = 0; i < N; i++)
		scanf("%d", &A[i]);
	for(int i = 0, l, r; i < Q; i++)
		scanf("%d %d", &l, &r), q.push_back({ i, l - 1, r - 1 });
	sort(q.begin(), q.end(), comp);
	
	// loop through A backwards ("left to right" wtf)
	add(N + 1, 1);
	s.push({ N, N + 1 });
	
	for(int i = N - 1, j = 0; i >= 0; i--)
	{
		if(j >= Q) break;
		while(!s.empty())
		{
			if(s.top().second < A[i])
			{
				add(s.top().first + 1, -1);
				s.pop();
			}
			else
				break;
		}
		
		s.push({ i, A[i] });
		add(i + 1, 1);
		
		for(; j < Q; j++)
		{
			if(q[j].l != i) break;
			ans[q[j].i] = sum(q[j].r + 1);
		}
	}
	
	for(int i = 0; i < Q; i++)
		printf("%d\n", ans[i]);
}
