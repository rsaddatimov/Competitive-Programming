#include <bits/stdc++.h>
#define MAX 100009
#define F first
#define S second
using namespace std;
int par[MAX], de[MAX], used[MAX], ans[MAX];
pair<int, int> e[MAX];
int n, m, q, cmpcnt;

int Repr(int v) {
    if (v == par[v]) return v;
    return par[v] = Repr(par[v]);
}
void Union(int x, int y) {
    x = Repr(x), y = Repr(y);
    if (x == y) return;
    par[y] = x;
    cmpcnt--;
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) par[i] = i;
    for (int i = 1; i <= m; ++i)
        scanf("%d%d", &e[i].F, &e[i].S);
    scanf("%d", &q);
    for (int i = 1; i <= q; ++i) {
        scanf("%d", &de[i]);
        used[de[i]] = 1;
    }
    cmpcnt = n;
    for (int i = 1; i <= m; ++i) {
        if (!used[i]) Union(e[i].F, e[i].S);
    }
    for (int i = q; i >= 1; --i) {
        ans[i] = cmpcnt;
        Union(e[de[i]].F, e[de[i]].S);
    }
    for (int i = 1; i <= q; ++i) printf("%d ", ans[i]);
}
