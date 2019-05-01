#include <bits/stdc++.h>
#define MAX 1000090
#define F first
#define S second
using namespace std;
int par[MAX];
int n, m;

int Repr(int v) {
    if (v == par[v]) return v;
    return par[v] = Repr(par[v]);
}
int Union(int x, int y) {
    x = Repr(x), y = Repr(y);
    par[y] = x;
    return x != y;
}
int main() {
    ios_base::sync_with_stdio(false);
    string s;
    while (cin >> s) {
        if (s[0] == 'R') {
            int n;
            cin >> n;
            for (int i = 0; i < n; ++i) par[i] = i;
            cout << "RESET DONE\n";
        } else if (s[0] == 'J') {
            int x, y;
            cin >> x >> y;
            if (!Union(x, y)) cout << "ALREADY " << x << " " << y << endl;
        } else {
            int x, y;
            cin >> x >> y;
            cout << (Repr(x) == Repr(y) ? "YES\n" : "NO\n");
        }
    }
}
