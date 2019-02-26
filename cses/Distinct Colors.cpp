/*
ID: toooooEasy or RafaelSaddatimov
PROG:
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
#define MAX 1009
#define SQMAX 4048
#define SZ (MAX / SQMAX + 1)
#define MOD 1000000007
#define INF 200000009
#define EPS 1e-5
#define ll long long
#define F first
#define S second
#define all(a) a.begin(), a.end()
#define pb push_back
#define io ios_base::sync_with_stdio(false); cin.tie(0)
using namespace std;
using namespace __gnu_pbds;
vector< vector<int> > g;
vector< set<int> > s;
vector<int> c, res;
int n;
 
void dfs(int v, int p = -1) {
    int to;
    s[v].insert(c[v]);
    for(int i=0; i<g[v].size(); ++i) {
        to = g[v][i];
        if(to == p)
            continue;
        dfs(to, v);
        if(s[v].size() < s[to].size())
            s[v].swap(s[to]);
        while(!s[to].empty()) {
            s[v].insert(*s[to].begin());
            s[to].erase(s[to].begin());
        }
    }
    res[v] = s[v].size();
}
int main() {
    scanf("%d", &n);
    g.resize(n + 1);
    s.resize(n + 1);
    c.resize(n + 1);
    res.assign(n + 1, 0);
    for(int i=1; i<=n; ++i)
        scanf("%d", &c[i]);
    for(int i=1; i<n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1);
    for(int i=1; i<=n; ++i)
        printf("%d ", res[i]);
}
