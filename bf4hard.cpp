#include <bits/stdc++.h>
using namespace std;
#define MOD 101
#define SEED 256
#define smod(a,b) (((a)%MOD-(b)%MOD+MOD)%MOD)
#define amod(a,b) (((a)%MOD+(b)%MOD)%MOD)
#define mmod(a,b) (((a)%MOD*(b)%MOD)%MOD)
#define cintie(x) { cin.sync_with_stdio(x); cin.tie(x); }

string S, T;
int psa[1000006], hashT, prec = 1;

int main()
{
    cintie(0);
    cin >> S;
    cin >> T;
    
    for(int i = 1; i <= S.length(); i++)
        psa[i] = amod(S[i-1], mmod(psa[i-1], SEED));
    for(int i = 1; i <= T.length(); i++)
        hashT = amod(T[i-1], mmod(hashT, SEED));
    for(int i = 1; i <= T.length(); i++)
        prec = mmod(prec, SEED);
    
    for(int i = 1, j; i <= S.length()-T.length()+1; i++)
    {
        if(smod(psa[i+T.length()-1], psa[i-1]*prec) == hashT)
        {
            // This is really important!
            // Check string equality as hash equality != string equality.
            for (j = 0; j < T.length(); j++)
                if (S[i+j-1] != T[j])
                    break;
            if (j == T.length())
            {
                cout << i-1 << "\n";
                return 0;
            }
        }
    }
    cout << -1 << "\n";
}
