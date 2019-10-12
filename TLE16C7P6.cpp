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

int N, M;
vector<string> v;

int hash(string s)
{
	res = s[0];
	for(int i = 1; i < s.length(); i++)
		res = res*131 + s[i];
	return res;
}

int main()
{
	cin >> N >> M;
	for(int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		v.push_back(s);
	}
}
