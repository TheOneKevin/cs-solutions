#include <bits/stdc++.h>
using namespace std;
#define INF 0x3F3F3F3F
#define MOD 1000000007
#define pow2(n) (1<<(n))
#define ilg2(n) sizeof(n)*8-__builtin_clz(n)-1
#define mid(n,m)(((m)+(n))/2)
#define ff first
#define ss second
#define cintie(x) { cin.sync_with_stdio(x); cin.tie(x); }
typedef long long ll;
typedef struct{int x,y;}vec;
typedef struct{double x,y;}vecf;
typedef pair<int, int> ip;

#define SUBMIT

string toLower(string s)
{
	for(int i=0;i<s.size();i++){
		if(s[i]>='A'&&s[i]<='Z'){
			s[i]-='A';
			s[i]+='a';
		}
	}
	return s;
}

string getNormal(string s1)
{
	string ret = "";
	string s = toLower(s1);
	bool hasPlus = false, beforeAt = true;
	for(int i = 0; i < s.length(); i++)
	{
		if(hasPlus && s[i] == '@') hasPlus = false;
		if(s[i] == '@') beforeAt = false;
		if(s[i] == '+') hasPlus = true;
		//cout << s[i] << " " << (s[i] != '.' && beforeAt)<<endl;
		if(!beforeAt || (!hasPlus && (s[i] != '.' && beforeAt))) ret += s[i];
	}
	return ret;
}

set<string> st;

int main()
{
#ifndef SUBMIT
	freopen("DATA12.txt", "r", stdin);
#endif
	cintie(0);
for(int test=1;test<=10;test++){
	st.clear();
	int N;
	string s;
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		cin >> s;
		//cout<<getNormal(s)<<endl;
		st.insert(getNormal(s));
	}
	cout << st.size()<<"\n";
}
}
