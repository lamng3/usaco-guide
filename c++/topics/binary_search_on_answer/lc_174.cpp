// problem url: https://leetcode.com/problems/dungeon-game/description/
// difficulty: hard
// tags: "binary search on answer", "paths on grid dp"
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector< vector<int> > vii;

const int oo = 1e9+7;
const int MAXH = 2e5+5;

int m, n;
vii dungeon;

bool check(int h) {
    if (h <= 0) return false;
    vii dp(m, vi(n, -oo));
    /*
        dp[i][j] = max health left reaching (i, j)
    */
    dp[0][0] = h + dungeon[0][0];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i > 0 && dp[i-1][j] > 0) {
                // can reach via left
                dp[i][j] = max(dp[i][j], dp[i-1][j] + dungeon[i][j]);
            }
            if (j > 0 && dp[i][j-1] > 0) {
                // can reach via up
                dp[i][j] = max(dp[i][j], dp[i][j-1] + dungeon[i][j]);
            }
        }
    }
    // reach bottom-right with positive health
    return dp[m-1][n-1] > 0;
}

int find() {
    // binary search
    int maxpos = MAXH;
    int h = maxpos;
    for (int pos = maxpos; pos > 0; pos /= 2) {
        while (check(h - pos)) {
            h -= pos;
        }
    }
    return h;
}

/*
inp:
3 3
-2 -3 3 
-5 -10 1
10 30 -5
out:
7
*/
void solve() {
    cin >> m >> n;
    dungeon.assign(m, vi(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dungeon[i][j];
        }
    }
    int ans = find();
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int tt = 1;
    // cin >> tt;
    while (tt--) solve();
    return 0;
}