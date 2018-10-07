#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#include <bits/stdc++.h>
using namespace std;

const int N = 20, INF = 0x3f3f3f3f;

int T, ans, s[N][N], tmp[N][N], cntc[N][N], cntr[N][N];
char t[N];

inline void Change(int x, int y)
{
    for(int i = 1; i <= 4; i++)
        for(int j = 1; j <= 4; j++)
            tmp[j][5 - i] = s[i + x - 1][j + y - 1];
    for(int i = 1; i <= 4; i++)  
        for(int j = 1; j <= 4; j++)
            s[i + x - 1][j + y - 1] = tmp[i][j];
}
inline bool check(int x, int y)
{
    for(int i = 0; i < 4; i ++)
        for(int j = 0; j < 4; j++) 
        {
            if(cntc[x + i][s[x + i][y + j]] != 0) return false;
            if(cntr[y + j][s[x + i][y + j]] != 0) return false;
        }
    return true;
}
inline void update(int x, int y, int sy)
{
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            cntc[x + i][s[x + i][y + j]] += sy,
                cntr[y + j][s[x + i][y + j]] += sy;
}
void DFS(int x, int y, int cnt)
{
    // cout << x << " " << y << " " << cnt << endl;
    if(cnt > ans) return;
    if(y > 16) x += 4, y = 1;
    if(x > 16) return (void) (ans = min(ans, cnt));
    if(check(x, y))
    {
        update(x, y, 1); DFS(x, y + 4, cnt); update(x, y, -1);
    }
    Change(x, y);
    if(check(x, y))
    {
        update(x, y, 1); DFS(x, y + 4, cnt + 1); update(x, y, -1);
    }
    Change(x, y);
    if(check(x, y))
    {
        update(x, y, 1); DFS(x, y + 4, cnt + 2); update(x, y, -1);
    }
    Change(x, y);
    if(check(x, y))
    {
        update(x, y, 1); DFS(x, y + 4, cnt + 3); update(x, y, -1);
    }
    Change(x, y);
}
int main()
{
    scanf("%d", &T);
    for(int _ = 1; _ <= T; _++)
    {
        ans = INF;
        memset(cntc, 0, sizeof cntc);
        memset(cntr, 0, sizeof cntr);
        for(int i = 1; i <= 16; i++) 
        {
            scanf("%s", t + 1);
            for(int j = 1; j <= 16; j++)
                if(isdigit(t[j])) s[i][j] = t[j] - '0';
                else s[i][j] = t[j] - 'A' + 10;
        }
        DFS(1, 1, 0);
        printf("%d\n", ans);
    }
    return 0;
}
