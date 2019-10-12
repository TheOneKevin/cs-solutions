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

vector<string> dict[30];
int N, K, ptr[30];

int main()
{
	cintie(0);
	cin >> K >> N;
	for(int i = 0; i < K; i++)
	{
		string s; cin >> s;
		dict[s[0]-'a'].push_back(s);
	}
	
	for(int i = 0; i < 26; i++)
		sort(dict[i].begin(), dict[i].end());
	
	for(int i = 0; i < N; i++)
	{
		char c; cin >> c; int j = c-'a';
		cout << (dict[j])[ptr[j]] << endl;
		ptr[j]++; ptr[j] %= dict[j].size();
	}
}
