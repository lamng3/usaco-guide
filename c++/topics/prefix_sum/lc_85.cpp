// problem url: https://leetcode.com/problems/maximal-rectangle/
// difficulty: hard
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector< vector<int> > vii;

/*
4 5
10100
10111
11111
10010
*/
void solve() {
    int m, n; cin >> m >> n;
    vector< vector<char> > mat(m, vector<char>(n));
    for (int i = 0; i < m; i++) {
        string row; cin >> row;
        for (int j = 0; j < n; j++) {
            mat[i][j] = row[j];
        }
    }

    // r[i][j] = largest rectangle at row i up to index j
    vii r(m, vi(n, 0));
    for (int i = 0; i < m; i++) {
        int s = 0;
        for (int j = 0; j < n; j++) {
            s = mat[i][j] == '0' ? 0 : s + 1;
            r[i][j] = s;
        }
    }

    int ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == '0') continue;
            int x = r[i][j];
            // try sweeping rows upward
            for (int k = i; k >= 0; k--) {
                x = min(x, r[k][j]);
                int area = x * (i-k+1);
                ans = max(ans, area);
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int tt = 1; 
    // cin >> tt;
    while (tt--) solve();
    return 0;
}