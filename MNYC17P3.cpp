#include <bits/stdc++.h>
using namespace std;
#define SEED 29
#define smod(a,b) (((a)%MOD-(b)%MOD+MOD)%MOD)
#define amod(a,b) (((a)%MOD+(b)%MOD)%MOD)
#define mmod(a,b) (((a)%MOD*(b)%MOD)%MOD)
#define cintie(x) { cin.sync_with_stdio(x); cin.tie(x); }

string S, T;
int N, M, ln;
int pS, pT, prec[1000006] = {1};

int main()
{
    cintie(0);   
    cin >> S >> T;
    N = S.size();
    M = T.size();
    for(int i = 1; i <= min(N, M); i++)
        prec[i] = SEED * prec[i-1];
    for(int i = 0; i < min(N, M); i++)
    {
        pS = pS + (S[N-i-1]-'A') * prec[i];
        pT = T[i]-'A' + pT * SEED;
        if(pS == pT)
            ln = i+1;
    }
    cout << S << T.substr(ln) << "\n";
}
