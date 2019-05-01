/*
ID: toooooEasy or RafaelSaddatimov
PROG:
*/
#include <bits/stdc++.h>
#define MAX 150
#define MOD 10000007
#define INF 2000000000
#define EPS 0.00000001
#define ll long long
using namespace std;
typedef pair<int, pair<int, int> > edge;
vector< edge > g;
vector<int> usd;
vector<int> parent;
int n, m, l, r, w;

int Repr(int v)
{
    if(v == parent[v])
        return v;
    return parent[v] = Repr(parent[v]);
}
int Union(int x,int y)
{
    int x1 = Repr(x), y1 = Repr(y);
    parent[x1] = y1;
    return (x1 != y1);
}
int main()
{
    scanf("%d%d", &n, &m);
    parent.resize(n + 1);
    for(int i=0; i<m; ++i)
        scanf("%d%d%d", &l, &r, &w), g.push_back(make_pair(w, make_pair(l, r)));
    for(int i=1; i<=n; ++i)
        parent[i] = i;
    sort(g.begin(), g.end());
    int a, b, d, cost1 = 0;
    int cnt = 0;
    for(int i=0; i<g.size(); ++i)
    {
        d = g[i].first;
        a = g[i].second.first;
        b = g[i].second.second;
        if(Union(a, b))
            cost1 += d, usd.push_back(i);
    }
    int cost2 = INF;
    for(int i=0; i<usd.size(); ++i)
    {
        cnt = 0;
        int lccost = 0;
        for(int j=1; j<=n; ++j)
            parent[j] = j;
        for(int j=0; j<m; ++j)
        {
            if(j == usd[i])
                continue;
            d = g[j].first;
            a = g[j].second.first;
            b = g[j].second.second;
            if(Union(a, b))
                lccost += d, ++cnt;
        }
        if(cnt == n - 1 && lccost < cost2)
            cost2 = lccost;
    }
    printf("%d %d", cost1, cost2);
}
