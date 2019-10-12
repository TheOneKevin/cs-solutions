#include <bits/stdc++.h>
using namespace std;
#define STATE_DEFAULT		1
#define STATE_QUO1_BEGIN	2 
#define STATE_QUO2_BEGIN	4
#define STATE_COMM_FIRST	3
#define STATE_COM1_BEGIN	6
#define STATE_COM2_BEGIN	8
#define STATE_COM2_PFINI	5

int main()
{
for(int _ = 0; _ < 5; _++) {
	int st1 = STATE_DEFAULT, st2 = STATE_DEFAULT;
	string s, res = "";
	bool appendSpace = false, open = false;
	
	getline(cin, s);
	
	for(int i = 0; i < s.length(); i++)
	{
		switch(s[i])
		{
			case '"':
				if(st1 == STATE_DEFAULT)			{ st1 = STATE_QUO1_BEGIN; goto end1; }
				else if(st1 == STATE_QUO1_BEGIN)	{ st1 = STATE_DEFAULT; goto end2; }
				break;
			case '\'':
				if(st1 == STATE_DEFAULT)			{ st1 = STATE_QUO2_BEGIN; goto end1; }
				else if(st1 == STATE_QUO2_BEGIN)	{ st1 = STATE_DEFAULT; goto end2; }
				break;
			case '/':
				if(st1 == STATE_DEFAULT)			{ st1 = STATE_COMM_FIRST; } // Intermediate
				else if(st1 == STATE_COMM_FIRST)	{ st1 = STATE_COM1_BEGIN, st2 = STATE_COM1_BEGIN; goto end1; }
				else if(st1 == STATE_COM2_PFINI)	{ st1 = STATE_DEFAULT, st2 = STATE_DEFAULT, open = false; goto end2; }
				break;
			case '*':
				if(st1 == STATE_COMM_FIRST)			{ st1 = STATE_COM2_BEGIN, st2 = STATE_COM2_BEGIN, open = true; goto end1; }
				else if(st1 == STATE_COM2_BEGIN)	{ st1 = STATE_COM2_PFINI; } // Intermediate
				break;
			default:
				if(st1 == STATE_COMM_FIRST)			st1 = st2;
				else if(st1 == STATE_COM2_PFINI)	st1 = st2;
				break;
		}
		if(st1 % 2 == 0) res += s[i];
end1:
		if(appendSpace)
		{
			appendSpace = false;
			cout << res << ' ';
			res = "";
		}
		continue;

end2:
		appendSpace = true;
		continue;
	}
	if(!open)
		cout << res;
	cout << "\n";
}}
