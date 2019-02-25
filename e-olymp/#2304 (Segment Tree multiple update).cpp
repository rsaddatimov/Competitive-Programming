/*
ID: toooooEasy or RafaelSaddatimov
PROG:
*/
#include <bits/stdc++.h>
#define MAX 100009
#define MOD 1000000LL
#define INF 17179869183
#define EPS 1e-12
#define ll long long
using namespace std;

class node
{
public:
    ll summa, add;
} t[4*MAX];
void push(ll v, ll vl, ll vm, ll vr)
{
    if(t[v].add != 0)
    {
        t[2*v+1].add += t[v].add;
        t[2*v+1].summa += t[v].add * (vm - vl + 1);
        t[2*v+2].add += t[v].add;
        t[2*v+2].summa += t[v].add * (vr - vm);
        t[v].add = 0;
    }
}
void build(ll v, ll vl, ll vr)
{
    if(vl == vr)
    {
        t[v] = arr[vl];
        return;
    }
    ll vm = (vl + vr) / 2;
    build(2*v+1, vl, vm);
    build(2*v+2, vm+1, vr);
    t[v] = t[2*v+1] + t[2*v+2];
}
void modify(ll v, ll vl, ll vr, ll l, ll r, ll val)
{
    if(l > r)
        return;
    if(vl == l && vr == r)
    {
        t[v].add += val;
        t[v].summa += val * (r - l + 1);
        return;
    }
    ll vm = (vl + vr) / 2;
    push(v, vl, vm, vr);
    modify(2*v+1, vl, vm, l, min(vm, r), val);
    modify(2*v+2, vm+1, vr, max(l, vm+1), r, val);
    t[v].summa = t[2*v+1].summa + t[2*v+2].summa;
}
ll query(ll v, ll vl, ll vr, ll l, ll r)
{
    if(l > r)
        return 0;
    if(vl == l && vr == r)
        return t[v].summa;
    ll vm = (vl + vr) / 2;
    push(v, vl, vm, vr);
    ll ql = query(2*v+1, vl, vm, l, min(r, vm));
    ll qr = query(2*v+2, vm+1, vr, max(l, vm+1), r);
    return ql + qr;
}
int main()
{
    ll T;
    scanf("%lld", &T);
    while(T--)
    {
        memset(t, 0, sizeof t);
        ll n, c, q, l, r, val;
        scanf("%lld%lld", &n, &c);
        while(c--)
        {
            scanf("%lld", &q);
            if(q == 0)
            {
                scanf("%lld%lld%lld", &l, &r, &val);
                modify(0, 0, n-1, l-1, r-1, val);
            }else
            {
                scanf("%lld%lld", &l, &r);
                printf("%lld\n", query(0, 0, n-1, l-1, r-1));
            }
        }
    }
}
