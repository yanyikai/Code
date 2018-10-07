#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#include <bits/stdc++.h>
#define P pair<int, int>
#define R register
using namespace std;
typedef long long LL;
typedef double db;

const int N = 250;
const LL MOD = 1000000007, INF = 0x3f3f3f3f;

int T, a, b, c, n, m;
char s[N][N];
signed main()
{
    scanf("%d", &T);
    for(int _ = 1; _ <= T; _++)
    {
        scanf("%d%d%d", &a, &b, &c);
        n = ((c + b) << 1) + 1;
        m = ((a + b) << 1) + 1;
        for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) s[i][j] = '!';
        for(int i = 1 + 2 * b; i <= n ; i ++)
        {
            int flag = 1;
            for(int j = 1; j <= 2 * a + 1; j ++)
            {
                if(i & 1)
                {
                    if(flag) s[i][j] = '+', flag ^= 1;
                    else s[i][j] = '-', flag ^= 1;
                }
                else
                {
                    if(flag) s[i][j] = '|', flag ^= 1;
                    else s[i][j] = '.', flag ^= 1;
                }
            }
        }
        int empty = 2 * b;
        for(int pp = n; pp >= n - 2 * b + 1; pp--)
        {
            int up = pp;
            int row = n - pp + 1, col = m - (n - pp);
            for(int i = 1; i <= empty; i++) s[row][i] = '.';
            for(int i = 1; i <= empty; i++) s[n - i + 1][col] = '.';
            
            if(! (empty & 1))
            {
                int flag = 1;
                for(int i = empty + 1; i <= col; i++)
                {
                    if(flag) s[row][i] = '+', flag ^= 1;
                    else s[row][i] = '-', flag ^= 1;
                }
                flag = 1;
                for(int i = row + 1; i <= n && s[i][col] == '!'; i ++)
                {
                    if(flag) s[i][col] = '|', flag ^= 1;
                    else s[i][col] = '+', flag ^= 1;
                }
            }
            else
            {
                int flag = 1;
                for(int i = empty + 1; i <= col; i++)
                {
                    if(flag) s[row][i] = '/', flag ^= 1;
                    else s[row][i] = '.', flag ^= 1;
                }
                flag = 1;
                for(int i = row + 1; i <= n && s[i][col] == '!'; i ++)
                {
                    if(flag) s[i][col] = '.', flag ^= 1;
                    else s[i][col] = '/', flag ^= 1;
                }
            }
            empty --;
        }
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
                cout <<s[i][j];
            puts("");
        }
    }
    return 0;
}
