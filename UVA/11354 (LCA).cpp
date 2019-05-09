#include <bits/stdc++.h>
#define MAX 55000
#define LGMAX 17
#define F first
#define S second
#define ll long long
using namespace std;
vector< pair<int, int> > g[MAX];
vector< pair<int, pair<int, int> > > e;
int par[MAX][LGMAX], pmax[MAX][LGMAX], in[MAX], out[MAX];
int parent[MAX];
int n, m, T, q;

int Repr(int v) {
    if (v == parent[v]) return v;
    return parent[v] = Repr(parent[v]);
}
int Union(int x, int y) {
    x = Repr(x), y = Repr(y);
    parent[x] = y;
    return (x != y);
}
void dfs(int v, int p) {
    in[v] = T++;
    par[v][0] = p;
    for (int i = 1; i < LGMAX; ++i) {
        par[v][i] = par[par[v][i - 1]][i - 1];
        pmax[v][i] = max(pmax[v][i - 1], pmax[par[v][i - 1]][i - 1]);
    }
    int to;
    for (int i = 0; i < g[v].size(); ++i) {
        to = g[v][i].F;
        if (to == p) continue;
        pmax[to][0] = g[v][i].S;
        dfs(to, v);
    }
    out[v] = T++;
}
int IsParent(int a, int b) {
    return in[a] <= in[b] && out[a] >= out[b];
}
int lca(int a, int b) {
    if (IsParent(a, b)) swap(a, b);
    int res = -1;
    int x = a;
    for (int i = LGMAX - 1; i >= 0; --i) {
        if (!IsParent(par[x][i], b)) {
            res = max(res, pmax[x][i]);
            x = par[x][i];
        }
    }
    res = max(res, pmax[x][0]);
    if (IsParent(a, b) || IsParent(b, a)) return res;
    x = b;
    for (int i = LGMAX - 1; i >= 0; --i) {
        if (!IsParent(par[x][i], a)) {
            res = max(res, pmax[x][i]);
            x = par[x][i];
        }
    }
    res = max(res, pmax[x][0]);
    return res;
}
int main() {
    scanf("%d%d", &n, &m);
    while (1) {
        for (int i = 1; i <= n; ++i) parent[i] = i;
        for (int i = 0; i < m; ++i) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            e.push_back({c, {a, b}});
        }
        sort(e.begin(), e.end());
        for (int i = 0; i < m; ++i) {
            int x = e[i].S.F, y = e[i].S.S, w = e[i].F;
            if (Union(x, y)) {
                g[x].push_back({y, w});
                g[y].push_back({x, w});
            }
        }
        T = 0;
        dfs(1, 1);
        scanf("%d", &q);
        for (int i = 1; i <= q; ++i) {
            int x, y;
            scanf("%d%d", &x, &y);
            printf("%d", lca(x, y));
            if (i != q) puts("");
        }
        for (int i = 1; i <= n; ++i) {
            g[i].clear();
            for (int j = 0; j < LGMAX; ++j) par[i][j] = pmax[i][j] = -1;
        }
        e.clear();
        if (scanf("%d%d", &n, &m) == 2) {
            puts("\n");
        } else {
            puts("");
            break;
        }
    }
}
