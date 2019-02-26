#include <bits/stdc++.h>
#define MAX 200004
#define NMAX 500005
#define MOD 1000000007LL
#define INF 1000000000
#define ll long long
using namespace std;
int type[MAX];
int a[MAX];
int b[MAX];
int arr[MAX];
vector<int> t, al;
map<int, int> compress;
int n, q;

void inc(int x, int dx) {
    for (; x < t.size(); x |= x + 1)
        t[x] += dx;
}
int sum(int x) {
    int res = 0;
    for (; x > 0; x = (x & (x + 1)) - 1)
        res += t[x];
    return res;
}
int main() {
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &arr[i]);
        al.push_back(arr[i]);
    }
    for (int i = 1; i <= q; ++i) {
        char x;
        int l, r;
        scanf(" %c%d%d", &x, &l, &r);
        a[i] = l;
        b[i] = r;
        type[i] = (x == '!' ? 0 : 1);
        al.push_back(r);
        if (type[i])
            al.push_back(l);
    }
    sort(al.begin(), al.end());
    al.erase(unique(al.begin(), al.end()), al.end());
    t = vector<int>(al.size() + 1, 0);
    for (int i = 0; i < al.size(); ++i) {
        compress[al[i]] = i + 1;
    }
    for (int i = 1; i <= n; ++i) inc(compress[arr[i]], 1);
    for (int i = 1; i <= q; ++i) {
        if (!type[i]) {
            inc(compress[arr[a[i]]], -1);
            arr[a[i]] = b[i];
            inc(compress[b[i]], 1);
        } else {
            printf("%d\n", sum(compress[b[i]]) - sum(compress[a[i]] - 1));
        }
    }
}
