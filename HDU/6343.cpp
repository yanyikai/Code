#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#include <bits/stdc++.h>
#define P pair<int, int>
#define R register
typedef long long LL;
typedef double db;
using namespace std;

const int N = 100500, INF = 0x3f3f3f3f;

int T, n, a[N], vis[N], dis[N];
priority_queue<P, vector<P>, greater<P> > G;

int calc(int i, int j){return floor(sqrt(fabs(1.0 * a[i] - a[j])));}
int main()
{
    scanf("%d", &T);
    for(int _ = 1; _ <= T; _++)
    {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) scanf("%d", a + i);
        printf("%d\n", calc(1, n));
    }
}
