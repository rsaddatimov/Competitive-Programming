/*
ID: toooooEasy or RafaelSaddatimov
PROG:
*/
#include <bits/stdc++.h>
#define MAX 1509
#define ll long long
#define F first
#define S second
#define all(a) a.begin(), a.end()
#define pb push_back
using namespace std;
int f[MAX];

int Repr(int v) {
    if(v == f[v])
        return v;
    return f[v] = Repr(f[v]);
}
int Union(int u, int v) {
    int x = Repr(u);
    int y = Repr(v);
    f[x] = y;
    return (x != y);
}
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; ++i)
        f[i] = i;
    vector< pair<int, pair<int, int> > > e;
    while(m--) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        e.pb(make_pair(w, make_pair(u, v)));
    }
    sort(all(e));
    int res = 0;
    for(int i=0; i<e.size(); ++i) {
        int u = e[i].S.F;
        int v = e[i].S.S;
        if(Union(u, v))
            res = max(res, e[i].F);
    }
    printf("%d", res);
}
