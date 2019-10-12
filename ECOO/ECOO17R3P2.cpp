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

struct node
{
	map<int, node> ch;
	int mxch;
};

int N;
node root;
vector<string> v;

int main()
{
	string s;
	cintie(0);
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		v.clear();
		string s, n;
		cin >> s;
		// Tokenize
		for(int i = 0; i < s.length(); i++)
		{
			if(s[i] == '.')
			{
				v.push_back(stoi(n));
				n = "";
			}
			else
				n += s[i];
		}
		v.push_back(stoi(n));
		
		node ptr = root;
		for(string str : v)
		{
			int a = stoi(str);
			if(ptr.ch.find(a) != ptr.ch.end())
				ptr.ch[a] = node();
		}
	}
}
