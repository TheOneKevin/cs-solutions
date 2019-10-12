#include <bits/stdc++.h>
using namespace std;
// Change me!
#define INF 0x3F3F3F3F
#define MOD 1000000007
// All other macros.
#define lsb(n)  ((n)&-(n))
#define pow2(n) (1<<(n))
#define ilg2(n) sizeof(n)*8-__builtin_clz(n)-1
#define mid(n,m)(((m)+(n))/2)
#define sl(x) (2*(x))
#define sr(x) (sl(x)+1)
#define ff first
#define ss second
#define smod(a,b) (((a)%MOD-(b)%MOD+MOD)%MOD)
#define amod(a,b) (((a)%MOD+(b)%MOD)%MOD)
#define btst(a,b) ((a) & (1 << (b)))
#define cintie(x) { cin.sync_with_stdio(x); cin.tie(x); }
// Typedefs
typedef long long ll;
typedef struct{int x,y;}vec;
typedef struct{double x,y;}vecf;
typedef pair<int, int> ip;

int get_sum(int dig)
{
	string s = to_string(dig);
	int sum = 0;
	for(int i = 0; i < s.length(); i++)
		sum += (int)(s[i]-'0');
	return sum;
}

ll sum_other_two(string s)
{
	ll sum = 0;
	for(int i = s.length()-2; i >= 0; i -= 2)
		sum += (ll)(s[i]-'0');
	return sum;
}

ll sum_every_two(string s)
{
	ll sum = 0;
	for(int i = s.length()-1; i >= 0; i -= 2)
	{
		int dig = (int)(s[i]-'0');
		dig *= 2;
		if(dig >= 10) dig = get_sum(dig);
		sum += (ll) dig;
	}
	return sum;
}

int main()
{
for(int _ = 0; _ < 5; _++)
{
	for(int z = 0; z < 5; z++)
	{
		string s;
		cin >> s;
		//cout << sum_every_two(s) << endl;
		//cout << sum_other_two(s) << endl;
		if((sum_every_two(s)+sum_other_two(s))%10)
			cout << 10-(sum_every_two(s)+sum_other_two(s))%10;
		else
			cout << 0;
	}
	cout << "\n";
}}
