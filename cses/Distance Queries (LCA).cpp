#include <bits/stdc++.h>
#define MAX 200004
#define NMAX 500005
#define MOD 1000000007LL
#define INF 1000000000
#define ll long long
#define F first
#define S second
using namespace std;
vector< vector< pair<int, int> > > g;
vector<int> tin, tout, dfrom1;
int timer = 0;
vector< vector<int> > up;
int n, q, l;

int parent(int a, int b)
{
	return tin[a] <= tin[b] && tout[a] >= tout[b];
}
int lca(int a, int b)
{
    if(parent(a, b))
        return a;
	if(parent(b, a))
        return b;
	for(int i=l; i>=0; --i)
		if(!parent(up[a][i], b))
			a = up[a][i];
	return up[a][0];
}
void dfs(int v, int dist, int p = 0)
{
    dfrom1[v] = dist;
    tin[v] = ++timer;
    up[v][0] = p;
    for(int i=1; i<=l; ++i)
		up[v][i] = up[up[v][i - 1]][i - 1];
    for(int i=0; i<g[v].size(); ++i)
    {
        int to = g[v][i].F;
        int cost = g[v][i].S;
        if(to != p)
            dfs(to, dist + cost, v);
    }
    tout[v] = ++timer;
}
int main()
{
    int a, b, w;
    scanf("%d%d", &n, &q);
    g.resize(n + 1);
    dfrom1.resize(n + 1, 0);
    tin.resize(n + 1, 0);
    tout.resize(n + 1, 0);
    up.resize(n + 1);
    tin[0] = -INF;
    tout[0] = INF;
    l = 1;
    while((1 << l) <= n)
        ++l;
    for(int i = 0; i <= n; ++i)
        up[i].resize(l + 1);
    for(int i = 0; i < n - 1; ++i) {
        scanf("%d%d", &a, &b);
        g[a].push_back(make_pair(b, 1));
        g[b].push_back(make_pair(a, 1));
    }
    dfs(1, 0);
    for(int i = 0; i < q; ++i) {
        scanf("%d%d", &a, &b);
        if(a > b)
            swap(a, b);
        int lv = lca(a, b);
        int res = dfrom1[a] + dfrom1[b] - 2 * dfrom1[lv];
        printf("%d\n", res);
    }
}
