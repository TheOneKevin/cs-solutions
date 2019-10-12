#include <bits/stdc++.h>
using namespace std;
// Change me!
#define INF 0x3F3F3F3F
#define MOD 1000000007
// All other macros.
#define pow2(n) (1<<(n))
#define ilg2(n) sizeof(n)*8-__builtin_clz(n)-1
#define mid(n,m)(((m)+(n))/2)
#define ff first
#define ss second
#define cintie(x) { cin.sync_with_stdio(x); cin.tie(x); }
// Typedefs
typedef long long ll;
typedef struct{int x,y;}vec;
typedef struct{double x,y;}vecf;
typedef pair<int, int> ip;

int N;
ll ans;
stack<ip> s;

int main()
{
	scanf("%d", &N);
	for(int i = 0, a; i < N; i++)
	{
		scanf("%d", &a);
		while(!s.empty() && s.top().ff < a)
		{
			ans+=s.top().ss;
			s.pop();
		}
		if(!s.empty() && s.top().ff == a)
		{
			ans += s.top().ss;
			if(s.size() > 1) ans++;
			ip p = s.top(); s.pop();
			s.push({p.ff, p.ss+1});
		}
		else
		{
			if(!s.empty())
				ans++;
			s.push({a,1});
		}
	}
	printf("%lld", ans);
}