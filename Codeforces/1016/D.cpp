#include<bits/stdc++.h>
using namespace std;
const int N = 110;
int a[N], b[N], n, m, sm1, sm2;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) scanf("%d", a + i), sm1 ^= a[i];
	for (int i = 1; i <= m; ++i) scanf("%d", b + i), sm2 ^= b[i];
	if (sm1 != sm2) {
		puts("NO");
		return 0;
	}
	puts("YES");
	printf("%d ", sm1 ^ a[1] ^ b[1]);
	for (int i = 2; i <= m; ++i) printf("%d ", b[i]);
	puts("");
	for (int i = 2; i <= n; ++i) {
		printf("%d ", a[i]);
		for (int i = 2; i <= m; ++i) printf("%d ", 0);
		puts("");
	}
	return 0;
} 
