// problem url: https://leetcode.com/problems/maximum-total-subarray-value-ii/description/
// difficulty: hard
// topics: sparse table, range min/max query
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef tuple<int,int,int> iii;
typedef long long ll;

const int MAXN = 500005;

vi precompute_lg2(int n) {
    vi lg2(n+1, 0);
    for (int i = 2; i <= n; i++) lg2[i] = lg2[i/2] + 1;
    return lg2;
}

int calculate_max(int L, int R, const vii& stmax, const vi& lg2) {
    int d = R - L + 1;
    int k = lg2[d];
    return max(stmax[L][k], stmax[R - (1 << k) + 1][k]);
}

int calculate_min(int L, int R, const vii& stmin, const vi& lg2) {
    int d = R - L + 1;
    int k = lg2[d];
    return min(stmin[L][k], stmin[R - (1 << k) + 1][k]);
}

/*
inp:
4 3
4 2 5 1
out:
12
*/
void solve() {
    int n, k; cin >> n >> k;
    vi a; a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vi lg2 = precompute_lg2(MAXN);

    // sparse table (range min/max query)
    vii stmax(n, vi(21, 0));
    vii stmin(n, vi(21, 0));

    for (int i = 0; i < n; i++) {
        stmax[i][0] = stmin[i][0] = a[i];
    }

    for (int j = 1; j <= 20; j++) {
        for (int i = 0; i < n; i++) {
            if (i + (1 << j) > n) continue;
            stmax[i][j] = max(stmax[i][j-1], stmax[i + (1 << (j-1))][j-1]);
            stmin[i][j] = min(stmin[i][j-1], stmin[i + (1 << (j-1))][j-1]);
        }
    }

    priority_queue<iii> pq;
    for (int L = 0; L < n; L++) {
        int R = n-1;
        int mx = calculate_max(L, R, stmax, lg2);
        int mn = calculate_min(L, R, stmin, lg2);
        pq.emplace(mx - mn, L, R);
    }

    ll ans = 0;
    while (k-- && !pq.empty()) {
        auto [v, L, R] = pq.top(); pq.pop();
        ans += v;
        R--;
        if (R >= L) {
            int mx = calculate_max(L, R, stmax, lg2);
            int mn = calculate_min(L, R, stmin, lg2);
            pq.emplace(mx - mn, L, R);
        }
    }
    cout << ans << '\n';
}

int main() {
    // freopen("name.in", "r", stdin);
    // freopen("name.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    // cin >> tt;
    while (tt--) solve();
    return 0;
}