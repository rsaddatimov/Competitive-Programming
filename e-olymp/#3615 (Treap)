/*
ID: toooooEasy or RafaelSaddatimov
PROG:
*/
#include <bits/stdc++.h>
#define MAX 400009
#define MOD 4294967296
#define INF 2000000000
#define EPS 0.00000001
#define ll long long
using namespace std;

struct item
{
    ll cnt, value, priority, minimum;
    item *l, *r;
    item() {}
    item(ll value) : priority((rand()<<16u) + unsigned(rand())), value(value), minimum(value), l(NULL), r(NULL) {}
};
typedef item* pitem;

ll cnt(pitem t)
{
    return t ? t->cnt : 0;
}
ll getMin(pitem t)
{
    return t ? t->minimum : INF;
}
void update(pitem t)
{
    if(t)
    {
        t->cnt = 1 + cnt(t->l) + cnt(t->r);
        t->minimum = min(t->value, min(getMin(t->l), getMin(t->r)));
    }
}
void merge(pitem l, pitem r, pitem &t)
{
    if (!l || !r)
        t = l ? l : r;
    else if (l->priority > r->priority)
        merge(l->r, r, l->r),  t = l;
    else
        merge(l, r->l, r->l),  t = r;
    update(t);
}
void split(pitem t, pitem &l, pitem &r, ll pos)
{
    if(!t)
        return void( l = r = 0 );
    if(pos <= cnt(t->l))
        split(t->l, l, t->l, pos),  r = t;
    else
        split(t->r, t->r, r, pos - 1 - cnt(t->l)),  l = t;
    update(t);
}
void insert(pitem &t, pitem it, ll pos)
{
    pitem t1, t2;
    split (t, t1, t2, pos);
    merge(t1,it,t1);
    merge (t1, t2, t);
}
void erase(pitem &t, ll pos)
{
    if(pos == cnt(t->l))
        merge (t->l, t->r, t);
    else if(pos < cnt(t->l))
        erase (t->l, pos);
    else
        erase (t->r, pos - cnt(t->l) - 1);
    update(t);
}
pitem T;
ll query(ll l, ll r)
{
    pitem a, b, c;
    split(T, b, c, r);
    split(b, a, b, l-1);
    ll res = getMin(b);
    merge(a, b, b);
    merge(b, c, T);
    return res;
}
int main()
{
    ll n, l, r;
    char q;
    scanf("%lld", &n);
    while(n--)
    {
        scanf(" %c%lld%lld", &q, &l, &r);
        if(q == '+')
            insert(T, new item(r), l);
        else
            printf("%lld\n", query(l, r));
    }
}
