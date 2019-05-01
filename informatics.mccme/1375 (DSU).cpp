#include <bits/stdc++.h>
#define MAX 100009
#define F first
#define S second
using namespace std;
int par[MAX];
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
    cmpcnt = n;
    for (int i = 1; i <= n; ++i) par[i] = i;
    for (int i = 1; i <= m; ++i) {
        if (cmpcnt == 1) return 0 * printf("%d", i - 1);
        int x, y;
        scanf("%d%d", &x, &y);
        Union(x, y);
    }
}
