#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#include <bits/stdc++.h>
#define P pair<int, int>
#define R register
typedef long long LL;
typedef double db;
using namespace std;

const int N = 1050   , INF = 0x3f3f3f3f;

int T, n, m, a[N], b[N];
char s[N];

bool Judge()
{
    for(int i = 0; i <= n - 2; i++)
        if((s[i] == '+' || s[i] == '*') && (s[i + 1] == '0') && ('0' <= s[i + 2] && s[i + 2] <= '9' && s[i]))
            return false;
    for(int i = 0; i <= n; i++)
        if((s[i] == '+' || s[i] == '*') && (s[i + 1] == '+' || s[i + 1] == '*'))
            return false;
    return true;
}
int main()
{
    scanf("%d", &T);
    for(int _ = 1; _ <= T; _++)
    {
        scanf("%s", s + 1);
        n = strlen(s + 1);
        s[0] = '+'; s[n + 1] = '+';
        for(int i = 0; i <= n - 1; i++)
        {
            if((s[i] == '*' || s[i] == '+') && s[i + 1] == '0' && s[i + 2] == '?')
                s[i + 2] = '+';
        }
        for(int i = 1; i <= n; i++) if(s[i] == '?') s[i] = '1';
        if(!Judge()) printf("IMPOSSIBLE\n");
        else 
        {
            for(int i = 1; i <= n; i++) cout << s[i];
            puts("");
        }
    }
}
