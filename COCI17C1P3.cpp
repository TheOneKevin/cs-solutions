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

int N, ans;
vector<string> v;
unordered_map<string, int> mp;

void getAllAndPush(string s)
{
	set<string> st;
	for(int i = 0; i < s.length(); i++)
		for(int j = i; j < s.length(); j++)
			st.insert(s.substr(i, j-i+1));
	for(string e : st)
	{
		if(mp.find(e) != mp.end())
			mp[e]++;
		else
			mp[e] = 1;
	}
}

int main()
{
	cintie(0);
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		v.push_back(s);
	}
	
	for(string s : v) getAllAndPush(s);
	for(string s : v) ans += mp[s];
	ans -= N;
	cout << ans << "\n";
}
