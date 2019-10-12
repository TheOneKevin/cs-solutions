#include <bits/stdc++.h>
using namespace std;
#define INF 0x3F3F3F3F
#define LSB(n) ((n) & -(n))
#define pow2(n) (1 << (n))
#define mid(n, m) (((m)+(n))/2)
#define _log2(n) sizeof(int) * 8 - __builtin_clz(n) - 1
#define sl(x) (2*(x))
#define sr(x) (sl(x)+1)
typedef pair<int, int> ip;
typedef long long ll;

struct node {
	int l, r, s;
};

int C, idx;
int BIT[40004], arr[10003];
unordered_map<string, int> mp;

int get_mass(string& s)
{
	int m = 0;
	for(char& c : s) m += c - 'a' + 1;
	return m;
}

void add(int x, int y)
{
	for(int i = x; i < 10004; i += LSB(i))
		BIT[i] += y;
}

int sum(int x)
{
	int res = 0;
	for(int i = x; i > 0; i -= LSB(i))
		res += BIT[i];
	return res;
}

int main()
{
	scanf("%d", &C);
	for(int i = 0, l, r; i < C; i++)
	{
		char c;
		string x, y;
		scanf(" %c", &c);
		switch(c)
		{
			case 'A':
				cin >> x;
				if (mp[x] != 0)
				{
					printf("Can't add %s\n", x.c_str());
					break;
				}
				mp[x] = ++idx;
				arr[idx] = get_mass(x);
				//printf("Added %d with %d\n", mp[x], arr[mp[x]]);
				add(idx, arr[idx]);
				break;
			case 'S': // Swap x and y
				cin >> x >> y;
				l = mp[x], r = mp[y];
				add(l, arr[r] - arr[l]);
				add(r, arr[l] - arr[r]);
				swap(arr[l], arr[r]);
				mp[y] = l, mp[x] = r;
				break;
			case 'M':
				cin >> x >> y;
				l = mp[x], r = mp[y];
				if(l > r) swap(l, r);
				printf("%d\n", sum(r) - sum(l - 1));
				break;
			case 'R': // Replace x with y
				cin >> x >> y;
				l = mp[x], r = get_mass(y);
				add(l, r - arr[l]);
				arr[l] = r;
				mp[y] = l;
				mp[x] = 0;
				break;
			case 'N':
				printf("%d\n", idx);
				break;
		}
	}
}
