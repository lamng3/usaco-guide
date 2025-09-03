// problem url: https://usaco.org/index.php?page=viewproblem2&cpid=1467
/*
1. place all black pixels
2. check invalid white pixels
3. greedy place gray pixels (move a right, move b down)
*/
#include <bits/stdc++.h>
using namespace std;

int n, a, b;

int compute(const vector< vector<char> >& pt) {
    vector< vector<int> > has(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (pt[i][j] == 'B') {
                // illegal: star appear from no where
                if (i < b || j < a) return -1;
                has[i][j] = has[i-b][j-a] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (pt[i][j] == 'W') {
                if (has[i][j]) return -1;
            }
            else if (pt[i][j] == 'G') {
                if (has[i][j]) continue;
                if (i >= b && j >= a && has[i-b][j-a]) continue;
                has[i][j] = 1;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans += has[i][j];
        }
    }
    return ans;
}

void solve() {
    cin >> n >> a >> b;
    vector< vector<char> > pt(n, vector<char>(n, 'x'));
    for (int i = 0; i < n; i++) {
        string r; cin >> r;
        for (int j = 0; j < n; j++) pt[i][j] = r[j];
    }
    int ans = compute(pt);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--) solve();
    return 0;
}