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

int cnt;
string s;

int main()
{
	cintie(0);
	cin >> s;
	for(int i = 0; i < s.length(); i++)
	{
		if(s[i] == '0') cnt--;
		if(s[i] == '1') cnt++;
	}
	printf("%d", s.length()-abs(cnt));
}