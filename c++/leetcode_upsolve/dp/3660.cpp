// problem url: https://leetcode.com/problems/jump-game-ix/
// weekly contest 464
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

const int oo = (int)1e9+7;

struct Fenwick {
    int n; vi ft;
    Fenwick(int n): n(n), ft(n+1, -oo) {};
    void update(int k, int u) {
        for (; k <= n; k += k & -k) ft[k] = max(ft[k], u);
    }
    int query(int k) {
        int s = -oo;
        for (; k > 0; k -= k & -k) s = max(s, ft[k]);
        return s;
    }
};

int strict_less(int x, vi a) {
    /* return largest number in a strictly less than x */
    // return int(lower_bound(a.begin(), a.end(), x) - a.begin());
    int l = -1, r = a.size();
    while (r - l > 1) {
        int m = l + (r - l) / 2;
        if (x < a[m]) r = m;
        else l = m;
    }
    return l;
};

void solve() {
    int n; cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    // no jumping or left-only
    vi base(n);
    for (int i = 0; i < n; i++) base[i] = i > 0 ? max(a[i], base[i-1]) : a[i];
    
    // coordinate compress
    vi uq = a;
    sort(uq.begin(), uq.end());
    uq.erase(unique(uq.begin(), uq.end()), uq.end());
    
    // get ranks
    unordered_map<int,int> rank;
    for (int i = 0; i < uq.size(); i++) rank[uq[i]] = i+1;
    vi r(n);
    for (int i = 0; i < n; i++) r[i] = rank[a[i]];

    Fenwick ft(uq.size());
    vi dp(n, -oo);
    for (int i = n-1; i >= 0; i--) {
        /*
        Intuition behind this is:
            If we approached a number < a[i] before, ft will have updated its value to be not -oo.
            Thus, ft.query(idx) have considered all smaller numbers than a[i] it has seen.
            We can jump to that numbers and get the max value at that place because a[idx] < a[i].
            And ft.query(idx) handles finding the max of numbers < a[i]. 

        Observation:
            We see under the lens of coordinate compression.
            I find this to be elegant for DP + Fenwick Tree.
        */
        int id = strict_less(a[i], uq);
        int best = base[i];
        if (id > 0) best = max(best, ft.query(id));
        dp[i] = best;
        ft.update(r[i], dp[i]);
    }

    for (int i = 0; i < n; i++) cout << dp[i] << ' ';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    // cin >> tt;
    while (tt--) solve();
    return 0;
}