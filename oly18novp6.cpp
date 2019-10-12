#include <bits/stdc++.h>
using namespace std;
// Change me!
#define INF 0x3F3F3F3F
#define MOD 1000000007
// All other macros.
#define LSB(n)  ((n)&-(n))
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

int N, M;
ll a[100005], bt[100005];
set<int> st;

ll sum(int x)
{
	ll s = 0;
	for(int i = x; i > 0; i -= LSB(i))
		s += bt[i];
	return s;
}

void add(int x, ll v)
{
	for(int i = x; i <= N; i += LSB(i))
		bt[i] += v;
}

int main()
{
	scanf("%d", &N);
	for(int i = 1; i <= N; i++)
	{
		scanf("%lld", &a[i]);
		add(i, a[i]);
		if(a[i] > 0) st.insert(i);
	}
	
	scanf("%d", &M);
	for(int i = 0, t, l, r; i < M; i++)
	{
		scanf("%d %d %d", &t, &l, &r);
		if(t == 1)
		{
			printf("%lld\n", sum(r) - sum(l-1));
			continue;
		}
		while(true)
		{
			auto it = st.lower_bound(l);
			l = *it;
			if(it == st.end() || l > r)
				break;
			add(l, (int)sqrt(a[l])-a[l]);
			a[l] = (int)sqrt(a[l]);
			if(a[l] <= 1) st.erase(it); // Nobody likes you
			l++;
		}
	}
}
