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
	char dbg;
	int idx, v = 0, c = 0;
	unordered_map<char, node*> ch;
	bool isEnd;
	
	~node()
	{
		for(auto k : ch)
			delete k.ss;
	}
};

int N, T, ctr, ans;
node* root;

void find(string s)
{
	node* cur = root;
	for(int i = 0; i < s.length(); i++)
	{
		cur = cur->ch[s[i]];
		
		// Will always be present
		if(cur->c == 1)
		{
			//printf("%d %d %d %c\n", cur->idx, cur->c, cur->isEnd, cur->dbg);
			ans += cur->idx;
			return;
		}
		if(cur->isEnd && i == s.length()-1)
		{
			//printf("%d %d %d %c\n", cur->idx, cur->c, cur->isEnd, cur->dbg);
			ans += cur->idx;
		}
	}
}

int main()
{
	cintie(0);
	cin >> T;
	//T = 1;
	for(int i = 0; i < T; i++)
	{
		ctr = 0, ans = 0;
		cin >> N;
		root = new node();
		for(int i = 0; i < N; i++)
		{
			string s;
			cin >> s;
			node* cur = root;
			for(int i = 0; i < s.length(); i++)
			{
				//cur->c++;
				if(cur->ch.find(s[i]) != cur->ch.end())
				{
					cur = cur->ch[s[i]];
					cur->isEnd |= i == s.length()-1;
					cur->c++;
					continue;
				}
				// Add and initialize
				cur->ch[s[i]] = new node();
				cur = cur->ch[s[i]];
				cur->dbg = s[i];
				cur->c = 1; cur->v = ++ctr; cur->idx = i+1;
				cur->isEnd = i == s.length()-1;
			}
			find(s);
		}
		cout << "Case #" << i+1 << ": " << ans << "\n";
		delete root;
	}
}
