#include <bits/stdc++.h>
using namespace std;
#define LSB(n) ((n) & -(n))
#define idx vt[i]

typedef pair<int, int> ip;

int N, c, x[1000005], rk[1000005], id[1000005], BIT[1000005], vt[1000005];
char op[1000005];
vector<ip> v;

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

int find_k(int xi)
{
	int p = 0, t = 0;
	for(int i = 20; i >= 0; i--)
	{
		p += (1 << i);
		if(p >= c || t + BIT[p] >= xi)
			p -= (1 << i);
		else
			t += BIT[p];		
	}
	return p + 1;
}

int main()
{
	scanf("%d", &N);
	for(int i = 1, rt; i <= N; i++)
	{
		scanf(" %c %d", &op[i], &x[i]);
		if(op[i] == 'Q') continue;
		scanf("%d", &rt);
		v.push_back({rt, i});
	}
	
	sort(v.begin(), v.end(), greater<ip>());
	
	// Coord. compression
	for(auto e : v)
	{
		c++;
		vt[e.second] = c;
	}
	
	for(int i = 1; i <= N; i++)
	{
		if(op[i] == 'N')
		{
			add(idx, 1);
			rk[x[i]] = idx;
			id[idx] = x[i];
		}
		
		else if(op[i] == 'M')
		{
			add(rk[x[i]], -1);
			add(idx, 1);
			rk[x[i]] = idx;
			id[idx] = x[i];
		}
		
		else if(op[i] == 'Q')
		{
			int t = find_k(x[i]);
			printf("%d\n", id[t]);
		}
	}
}
