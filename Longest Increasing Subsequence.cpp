#include <bits/stdc++.h>
using namespace std;
#define INF 0x3F3F3F3F
#define LSB(n) ((n) & -(n))
#define pow2(n) (1 << (n))
#define mid(n, m) (((m)+(n))/2)
#define _log2(n) sizeof(int) * 8 - __builtin_clz(n) - 1
typedef pair<int, int> ip;

int N;
vector<int> v;

int main()
{
	scanf("%d", &N);
	for(int i = 0, a; i < N; i++)
	{
		scanf("%d", &a);
		if(v.empty() || v.back() < a)
			v.push_back(a);
		else
		{
			auto it = lower_bound(v.begin(), v.end(), a);
			v[it - v.begin()] = a;
		}
	}
	
	printf("%d", v.size());
}
