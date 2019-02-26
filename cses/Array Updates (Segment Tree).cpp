/*
ID: toooooEasy or RafaelSaddatimov
PROG:
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
#define MAX 200009
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
ll arr[MAX];
 
class node {
public:
    ll prefix, suffix, summa, maximum;
} t[4 * MAX];
node merge(node l, node r) {
    node res;
    res.prefix = max(l.prefix, l.summa + r.prefix);
    res.suffix = max(r.suffix, r.summa + l.suffix);
    res.summa = l.summa + r.summa;
    res.maximum = max(max(l.maximum, r.maximum), l.suffix + r.prefix);
    return res;
}
void build(ll v, ll vl, ll vr) {
    if(vl == vr) {
        t[v].maximum = t[v].prefix = t[v].suffix = t[v].summa = arr[vl];
        return;
    }
    ll vm = vl + (vr - vl)/2;
    build(2 * v + 1, vl, vm);
    build(2 * v + 2, vm + 1, vr);
    t[v] = merge(t[2 * v + 1], t[2 * v + 2]);
}
node query(ll v, ll vl, ll vr, ll l, ll r) {
    if(r < vl || vr < l) {
        node lc;
        lc.maximum = lc.prefix = lc.suffix = lc.summa = -INF;
        return lc;
    }
    if(l <= vl && vr <= r)
        return t[v];
    ll vm = vl + (vr - vl)/2;
    node ql = query(2 * v + 1, vl, vm, l, r);
    node qr = query(2 * v + 2, vm + 1, vr, l, r);
    return merge(ql, qr);
}
void modify(ll v, ll vl, ll vr, ll pos, ll nval) {
    if(vl == vr) {
        t[v].maximum = t[v].prefix = t[v].suffix = t[v].summa = nval;
        return;
    }
    ll vm = vl + (vr - vl) / 2;
    if(pos <= vm)
        modify(2 * v + 1, vl, vm, pos, nval);
    else
        modify(2 * v + 2, vm + 1, vr, pos, nval);
    t[v] = merge(t[2 * v + 1], t[2 * v + 2]);
}
int main() {
    ll n, m, l, r;
    scanf("%lld%lld", &n, &m);
    for(ll i=1; i<=n; ++i)
        scanf("%lld", &arr[i]);
    build(0, 1, n);
    while(m--) {
        scanf("%lld%lld", &l, &r);
        modify(0, 1, n, l, r);
        printf("%lld\n", t[0].maximum);
    }
}
