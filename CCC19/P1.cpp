#include <bits/stdc++.h>
using namespace std;
#define INF 0x3F3F3F3F
#define MOD 1000000007
#define cintie(x) { cin.sync_with_stdio(x); cin.tie(x); }

int v, h;

int main()
{
	cintie(0);
	string s;
	cin >> s;
	for(int i = 0; i < s.length(); i++)
	{
		if(s.c_str()[i] == 'V')
			v = (v+1)%2;
		else if(s.c_str()[i] == 'H')
			h = (h+1)%2;
	}
	
	if(!v && !h)
		cout << "1 2\n3 4";
	else if(v && !h)
		cout << "2 1\n4 3";
	else if(h && !v)
		cout << "3 4\n1 2";
	else if(h && v)
		cout << "4 3\n2 1";
}
