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

ll A, B, K;
vector<ll> v;

int main()
{
	scanf("%lld %lld %lld", &A, &B, &K);
	if(A == 1 || B == 1)
	{
		if(K == 1)
			printf("1\n");
		else
			printf("-1\n");
		return 0;
	}
	for(int i = 2; i <= min(A, B); i++)
	{
		if(A % i == 0 && B % i == 0)
		{
			v.push_back(i);
		}
	}
	if(v.size() <= K)
	    printf("-1\n");
	else
	    printf("%lld\n", v[v.size()-K]);
}
