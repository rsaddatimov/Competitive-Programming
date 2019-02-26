#include <bits/stdc++.h>
#define MAX 2604
#define NMAX 500005
#define MOD 1000000007LL
#define INF 1000000000
#define ll long long
using namespace std;
string s[MAX];
int used[MAX][MAX];
int n, m;

bool can(int i, int j) {
    return 0 <= i && i < n && 0 <= j && j < m && s[i][j] != '#' && !used[i][j];
}
void dfs(int i, int j) {
    used[i][j] = 1;
    if (can(i + 1, j)) dfs(i + 1, j);
    if (can(i - 1, j)) dfs(i - 1, j);
    if (can(i, j + 1)) dfs(i, j + 1);
    if (can(i, j - 1)) dfs(i, j - 1);

}
int main() {
    cin >> n >> m;
    int res = 0;
    for (int i = 0; i < n; ++i) cin >> s[i];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (s[i][j] != '#' && !used[i][j]) {
                dfs(i, j);
                res++;
            }
        }
    }
    printf("%d", res);
}
