#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 200010;
int T, n, t, i, f[N];
bool must[N];
struct P
{
    int x, y, id;
    bool operator<(const P &o) const
    {
        if (x != o.x)
            return x < o.x;
        if (y != o.y)
            return y > o.y;
        return id < o.id;
    }
} a[N], q[N];
int main()
{
    scanf("%d", &T);
    for (;T--;)
    {
        scanf("%d", &n);
        for (i = 1; i <= n; i++)
        {
            a[i].id = i;
            scanf("%d%d", &a[i].x, &a[i].y);
        }
        sort(a + 1, a + n + 1);
        for (t = 0, i = 1; i <= n; i++)
        {
            if (i > 1 && a[i].x == a[i - 1].x)
                continue;
            for (; t > 1 && 1LL * (q[t].y - q[t - 1].y) * (a[i].x - q[t].x) < 1LL * (a[i].y - q[t].y) * (q[t].x - q[t - 1].x); --t)
                ;
            q[++t] = a[i];
        }
        memset(must, 0, sizeof must);
        must[1] = must[t] = 1;
        for (i = 2; i < t; i++)
            if (1LL * (q[i].y - q[i - 1].y) * (q[i + 1].x - q[i].x) != 1LL * (q[i + 1].y - q[i].y) * (q[i].x - q[i - 1].x))
                must[i] = 1;
        for (i = t; i; i--)
            f[i] = must[i] ? q[i].id : min(f[i + 1], q[i].id);
        for (i = 1; i < t; i++)
            if (f[i] == q[i].id)
                printf("%d ", f[i]);
        printf("%d\n", f[t]);
    }
    return 0;
}
