#include <bits/stdc++.h>
#define N 1005
using namespace std;
queue<int> Q;
int n, num[N], ans[N], res[N];
int main()
{
    scanf("%d", &n);
    for (int i = 1, x, y; i < n; ++i)
        scanf("%d%d", &x, &y), ++num[x], ++num[y];
    int tot = 0;
    if (num[n] != n - 1)
        return puts("NO"), 0;
    for (int i = 1; i < n; ++i)
        if (!num[i])
            Q.push(i);
        else
        {
            int now = i;
            for (; !Q.empty();)
            {
                if (num[i] == 1)
                    break;
                int x = Q.front();
                Q.pop();
                ++tot;
                ans[tot] = now;
                now = x;
                res[tot] = x;
                --num[i];
            }
            if (num[i] != 1)
                return puts("NO"), 0;
            ++tot;
            ans[tot] = now;
            res[tot] = n;
        }
    puts("YES");
    for (int i = 1; i <= tot; ++i)
        printf("%d %d\n", ans[i], res[i]);
    return 0;
}
