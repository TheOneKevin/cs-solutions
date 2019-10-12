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

#define PISANO_PERIOD 2000000016LL

string N;

ll mod(string n)
{
	ll res = 0;
	for(int i = 0; i < n.length(); i++)
		res = (res*10+(n[i]-'0')) % PISANO_PERIOD;
	return res;
}

#define MD(x) ((x) % 1000000007)
#define MMD(x) (MD(x) % 1000000007)

void mult(ll F[2][2], ll M[2][2])
{
	ll x = MMD(MD(F[0][0]) * MD(M[0][0])) + MMD(MD(F[0][1]) * MD(M[1][0]));
	ll y = MMD(MD(F[0][0]) * MD(M[0][1])) + MMD(MD(F[0][1]) * MD(M[1][1]));
	ll z = MMD(MD(F[1][0]) * MD(M[0][0])) + MMD(MD(F[1][1]) * MD(M[1][0]));
	ll w = MMD(MD(F[1][0]) * MD(M[0][1])) + MMD(MD(F[1][1]) * MD(M[1][1]));
	
	F[0][0] = MD(x);
	F[0][1] = MD(y);
	F[1][0] = MD(z);
	F[1][1] = MD(w);
}

void powe(ll F[2][2], ll n)
{
	if(n == 0 || n == 1) return;
	ll M[2][2] = {{1, 1}, {1, 0}};
	powe(F, n / 2);
	mult(F, F);
	if(n % 2 != 0)
		mult(F, M);
}

ll fib(ll n)
{
	ll F[2][2] = {{1, 1}, {1, 0}};
	if(n == 0) return 0;
	powe(F, n - 1);
	return F[0][0];
}

int main()
{
	cintie(0);
	cin >> N;
	//reverse(N.begin(), N.end());
	ll t = mod(N);
	//cout << t << endl;
	cout << fib(t);
}
