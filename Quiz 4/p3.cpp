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

#define MAXN 1000000

ll A, B, K, cnt, ans = 1;
ll fct[MAXN+6];
vector<ll> v;

ll gcd(ll a, ll b)
{
	ll t = 0;
	while(b != 0)
	{
		t = b;
		b = a % b;
		a = t;
	}
	return a;
}

int main()
{
	fct[1] = 1;
	for(ll i = 2; i <= MAXN; i++) fct[i] = i;
	for(ll i = 4; i < MAXN; i+=2) fct[i] = 2;
	for(ll i = 3; i*i <= MAXN; i++)
		if(fct[i] == i)
			for(ll j = i*i; j <= MAXN; j+=i)
				if(fct[j]==j)
					fct[j]=i;
	scanf("%lld %lld %lld", &A, &B, &K);
	if(A == 1 || B == 1)
	{
		if(K == 1)
			printf("1\n");
		else
			printf("-1\n");
		return 0;
	}
	
	ll g = gcd(A, B);
	v.push_back(g);
	v.push_back(1);
	for(ll i = 1; i*i <= g; i++)
	{
		if(g % i == 0)
		{
			v.push_back(i);
			if(i != g/i)
				v.push_back(g/i);
		}
	}
	/*for(int i = 0; i < v.size(); i++)
		printf("%lld\n", v[i]);*/
	if(v.size() <= K-1)
	{
		printf("-1\n");
		return 0;
	}
	sort(v.begin(), v.end());
	printf("%lld\n", v[v.size()-K]);
	
}
