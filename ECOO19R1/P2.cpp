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

map<char, string> mp;
ll fr[255], tp[255];

int update_freq()
{
	for(int i = (int)'A'; i <= (int)'Z'; i++)
		tp[i] = fr[i];
	for(int i = (int)'A'; i <= (int)'Z'; i++)
	{
		if(fr[i] && (mp.find((char)i) != mp.end()))
		{
			for(int j = 0; j < mp[(char)i].length(); j++)
				tp[(int)(mp[(char)i][j])] += fr[i];
			tp[i]-=fr[i];
		}
	}
	
	for(int i = (int)'A'; i <= (int)'Z'; i++)
		fr[i] = tp[i];
}

int main()
{
	cintie(0);
for(int _ = 0; _ < 10; _++)
{
	memset(fr, 0, sizeof(fr));
	int R, T;
	string ax;
	cin >> R >> T >> ax;
	char res[2];
	for(int i = 0; i < R; i++)
	{
		char ch; string str;
		cin >> ch >> str;
		mp[ch] = str;
	}
	
	for(int i = 0; i < ax.length(); i++)
		fr[ax[i]]++;
	
	res[0] = ax[0];
	res[1] = ax[ax.length()-1];
	
	for(int i = 0; i < T; i++)
	{
		update_freq();
		res[0] = mp[res[0]][0];
		res[1] = mp[res[1]][mp[res[1]].length()-1];
		/*ll len = 0;
		for(int i = (int)'A'; i <= (int)'Z'; i++)
			len += fr[i];
		cout << len << endl;*/
	}
	
	ll len = 0;
	for(int i = (int)'A'; i <= (int)'Z'; i++)
		len += fr[i];
	cout << res[0] << res[1] << " " << len << "\n";
}}
