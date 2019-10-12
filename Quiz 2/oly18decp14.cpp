#include <bits/stdc++.h>
using namespace std;
#define INF 0x3F3F3F3F
#define LSB(n) ((n) & -(n))
#define pow2(n) (1 << (n))
#define mid(n, m) (((m)+(n))/2)
#define ilog2(n) sizeof(int) * 8 - __builtin_clz(n) - 1
#define sl(x) (2*(x))
#define sr(x) (sl(x)+1)
#define loop(x, a, b) for(int x = a; x < b; x++)
#define sc(x) do{while((x=getchar())<'0');for(x-='0';'0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
typedef long long ll;
typedef struct{int x,y;}vec;
typedef pair<int, int> ip;

int N, M;
vector<string> v;
unordered_map<string, int> m;

bool isPre(string a, string b)
{
	if(a.length() > b.length()) return false;
	return 0 == b.compare(0, a.length(), a);
}

int main()
{
	scanf("%d %d", &N, &M);
	for(int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		v.push_back(s);
		m[s] = i;
	}
	sort(v.begin(), v.end());
	/*for(string s : v)
		cout << s << " ";
	printf("\n");*/
	for(int i = 0, n; i < M; i++)
	{
		string s;
		cin >> n >> s;
		auto it = lower_bound(v.begin(), v.end(), s);
		int f = it - v.begin();
		f += n - 1;
		//printf("%d\n", f);
		if(f < v.size() && (isPre(s, v[f]) || isPre(v[f], s)))
			printf("%d\n", m[v[f]] + 1);
			//printf("%s %d\n", v[f].c_str(), m[v[f]]);
		else
			printf("-1\n");
	}
}
