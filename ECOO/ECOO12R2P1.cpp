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

ll gcd(ll a, ll b)
{
	if(b == 0) return a;
	return gcd(b, a%b);
}

char getChar(int a)
{
	if(a == 0) return ' ';
	if(a == 27) return '.';
	if(a == 28) return ',';
	if(a == 29) return '!';
	if(a == 30) return '?';
	return a - 1 + 'A';
}

vector<ll> v;

int main()
{
for(int _ = 0; _ < 5;_++) {
	int N;
	v.clear();
	scanf("%d", &N);
	ll b = 0;
	for(int i = 0; i < N; i++)
	{
		ll a;
		scanf("%lld", &a);
		v.push_back(a);
		b = gcd(a, b);
	}
	for(ll a : v)
		printf("%c%c", getChar(((a/b)-(a/b)%100)/100), getChar((a/b)%100));
	printf("\n");
}
}
