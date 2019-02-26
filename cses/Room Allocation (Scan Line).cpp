#include <bits/stdc++.h>
#define MAX 200004
#define NMAX 500005
#define MOD 1000000007LL
#define INF 1000000000
#define ll long long
using namespace std;

struct query {
    int man, day, type;
    query(int man = 0, int day = 0, int type = 0) : man(man), day(day), type(type) {}
};
int id[MAX];
int cmp(query a, query b) {
    if (a.day == b.day) return a.type < b.type;
    return a.day < b.day;
}
int main() {
    int n;
    cin >> n;
    set<int> now;
    vector<query> q;
    for (int i = 1; i <= n; ++i) {
        int l, r;
        cin >> l >> r;
        q.push_back(query(i, l, 0));
        q.push_back(query(i, r, 1));
    }
    sort(q.begin(), q.end(), cmp);
    int nxt = 1;
    for (int i = 0; i < q.size(); ++i) {
        if (q[i].type == 0) {
            if (now.size() == 0) {
                id[q[i].man] = nxt++;
            } else {
                id[q[i].man] = *now.begin();
                now.erase(now.begin());
            }
        } else {
            now.insert(id[q[i].man]);
        }
    }
    cout << now.size() << endl;
    for (int i = 1; i <= n; ++i) cout << id[i] << " ";
}
