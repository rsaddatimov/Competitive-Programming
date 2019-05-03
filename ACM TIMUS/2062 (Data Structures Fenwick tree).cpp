#include <bits/stdc++.h>
#define MAX 300005
#define LGMAX 18
#define MOD 998244353
#define F first
#define S second
#define ll long long
#define pb push_back
using namespace std;
ll arr[MAX], t[MAX];
vector<int> divs[MAX];
int n, m;

void inc(int i, ll dx) {
    for (; i <= n; i |= (i + 1))
        t[i] += dx;
}
ll sum(int i) {
    ll res = 0;
    for (; i > 0; i = (i & (i + 1)) - 1)
        res += t[i];
    return res;
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; j += i)
            divs[j].pb(i);
    }
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &arr[i]);
    scanf("%d", &m);
    while (m--) {
        int ty, l, r; ll d;
        scanf("%d%d", &ty, &l);
        if (ty == 2) {
            scanf("%d%lld", &r, &d);
            inc(l, d);
            inc(r + 1, -d);
        } else {
            ll res = arr[l];
            for (int x : divs[l])
                res += sum(x);
            printf("%lld\n", res);
        }
    }
}
