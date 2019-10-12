#include <bits/stdc++.h>
using namespace std;
#define INF 0x3F3F3F3F
#define LSB(n) ((n) & -(n))
#define pow2(n) (1 << (n))
#define mid(n, m) (((m)+(n))/2)
#define _log2(n) sizeof(int) * 8 - __builtin_clz(n) - 1
typedef pair<int, int> ip;

deque<ip> q;
unordered_map<int, int> m;
int Q;

int main()
{
	scanf("%d", &Q);
	for(int i = 0, a; i < Q; i++)
	{
		char c;
		scanf(" %c %d", &c, &a);
		switch(c)
		{
			case 'F':
				m[a] = i;
				q.push_front({ a, i });
				break;
			case 'E':
				m[a] = i;
				q.push_back({ a, i });
				break;
			case 'R':
				m[a] = -1;
				break;
		}
	}
	
	for(ip v : q)
		if(m[v.first] == v.second)
			printf("%d\n", v.first);
}
