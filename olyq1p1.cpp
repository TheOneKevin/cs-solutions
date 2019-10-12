#include <bits/stdc++.h>
using namespace std;
// Change me!
#define INF 0x3F3F3F3F
#define MOD 1000000007
// All other macros.
#define pow2(n) (1<<(n))
#define ilg2(n) sizeof(n)*8-__builtin_clz(n)-1
#define lsb(n)  ((n)&-(n))
#define mid(n,m)(((m)+(n))/2)
#define ff first
#define ss second
#define cintie(x) { cin.sync_with_stdio(x); cin.tie(x); }
// Typedefs
typedef long long ll;
typedef struct{int x,y;}vec;
typedef struct{double x,y;}vecf;
typedef pair<int, int> ip;

int N, BIT[1000006];
ll ans;
string s1, s2;
stack<int> q[27];

ll sum(int n)
{
	ll sum = 0;
	for(int i = n; i > 0; i -= lsb(i))
		sum += BIT[i];
	return sum;
}

void add(int n, int v)
{
	for(int i = n; i <= 1000000; i += lsb(i))
		BIT[i] += v;
}

int main()
{
	cintie(0);
	cin >> N >> s1 >> s2;
	for(int i = 1; i <= N; i++)
		q[s1[i-1]-'A'].push(i);
	for(int i = N; i > 0; i--)
	{
		int a = q[s2[i-1]-'A'].top();
		q[s2[i-1]-'A'].pop();
		//cout << a << " ";
		ans += sum(a-1);
		add(a, 1);
	}
	cout << ans << "\n";
}
