#include <bits/stdc++.h>
using namespace std;
#define INF 0x3F3F3F3F
#define LSB(n) ((n) & -(n))
#define pow2(n) (1 << (n))
#define mid(n, m) (((m)+(n))/2)
#define ilog2(n) sizeof(int) * 8 - __builtin_clz(n) - 1
#define sl(x) (2*(x))
#define sr(x) (sl(x)+1)
#define loop(x, a, b) for(int x = a; x < b; x++)
#define sc(x) do{while((x=getchar())<'0');for(x-='0';'0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
typedef long long ll;
typedef struct{int x,y;}vec;
typedef pair<int, int> ip;

int T, N;

int main()
{
	scanf("%d", &T);
	for(int z = 0; z < T; z++)
	{
		scanf("%d", &N);
		stack<int> s, l, nn;
		int cur = 1;
		for(int i = 1, a; i <= N; i++)
		{
			scanf("%d", &a);
			nn.push(a);
		}
		while(!nn.empty())
		{
			int a = nn.top();
			nn.pop();
			if(a != cur)
			{
				while(!s.empty())
				{
					if(s.top() == cur)
					{
						l.push(s.top());
						s.pop();
						cur++;
					}
					else break;
				}
				s.push(a);
			}
			else
			{
				l.push(a);
				cur++;
			}
		}
		while(!s.empty())
		{
			l.push(s.top());
			s.pop();
		}
		
		int ppp = N;
		bool yesno = true;
		while(!l.empty())
		{
			if(l.top() == ppp)
				yesno &= true;
			else
				yesno &= false;
			l.pop();
			ppp--;
		}
		
		printf(yesno ? "Y\n" : "N\n");
	}
}