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
typedef unsigned long long ll;
typedef struct{int x,y;}vec;
typedef struct{double x,y;}vecf;
typedef pair<int, int> ip;

string N;

#define MD(x) ((x) % 1000000007)
#define MMD(x) (MD(x) % 1000000007)

string div2(string n)
{
	int c = 0, q = 0;
	string quot = "";
	for(int i = n.length()-1; i >= 0; i--)
	{
		q = ((n[i]-'0')+c*10)/2;
		c = ((n[i]-'0')+c*10)%2;
		quot += q+'0';
	}
	quot.erase(0, min(quot.find_first_not_of('0'), quot.size()-1));
	reverse(quot.begin(), quot.end());
	return quot;
}

string dec(string n)
{
	int d = 0, c = 1;
	string diff = "";
	for(int i = 0; i < n.length(); i++)
	{
		d = n[i]-'0';
		if(n[i] == '0' && c == 1)
			d = 9;
		else if(c == 1)
			d--, c = 0;
		diff += d+'0';
	}
	reverse(diff.begin(), diff.end());
	diff.erase(0, min(diff.find_first_not_of('0'), diff.size()-1));
	reverse(diff.begin(), diff.end());
	return diff;
}

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

void powe(ll F[2][2], string n)
{
	if(n == "0" || n == "1") return;
	ll M[2][2] = {{1, 1}, {1, 0}};
	powe(F, div2(n));
	mult(F, F);
	if((n[0]-'0')%2 != 0) mult(F, M);
}

ll fib(string n)
{
	ll F[2][2] = {{1, 1}, {1, 0}};
	if(n == "0") return 0;
	powe(F, dec(n));
	return F[0][0];
}

int main()
{
	cintie(0);
	cin >> N;
	reverse(N.begin(), N.end());
	//cout << dec(N);
	cout << fib(N);
}
