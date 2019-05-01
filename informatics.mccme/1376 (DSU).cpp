#include <bits/stdc++.h>
#define MAX 1000090
#define F first
#define S second
using namespace std;
int par[MAX], sum[MAX];
pair<int, int> e[MAX];
int n, m;

int Repr(int v) {
    if (v == par[v]) return v;
    return par[v] = Repr(par[v]);
}
void Union(int x, int y, int w) {
    x = Repr(x), y = Repr(y);
    if (x == y) {
        sum[x] += w;
        return;
    }
    par[y] = x;
    sum[x] = sum[x] + sum[y] + w;
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) par[i] = i;
    for (int i = 1; i <= m; ++i) {
        int t, x, y, w;
        scanf("%d%d", &t, &x);
        if (t == 2)
            printf("%d\n", sum[Repr(x)]);
        else {
            scanf("%d%d", &y, &w);
            Union(x, y, w);
        }
    }
}
