/*
n bees numbered 1..n are spreading word of a flower. 
Bee 1 is the one that first located the flower and initially the only bee with the information. 
n − 1 pairs of bees are friends, and bees only talk to friends. 
It is possible for all bees to hear the news. 
Each minute, a bee with the news can transmit it to one friend. 
Compute the minimum time for all bees to receive the news.
*/
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector< vector<int> > vii;

const int oo = 1e9+7;

vi dp;
vii g;

void dfs(int u, int p) {
    vi ch; // children
    for (int v : g[u]) {
        if (v == p) continue;
        dfs(v, u); 
        ch.push_back(dp[v]);
    }
    // prioritize subtree with larger times
    sort(ch.begin(), ch.end(), greater<int>());
    // this for loop is interesting, we prioritize by index
    // +0 for largest, +1 for second largest
    // (i+1) = delay until ch[i] gets informed
    for (int i = 0; i < ch.size(); i++) dp[u] = max(dp[u], ch[i] + i + 1);
}

void solve() {
    int n; cin >> n;
    g.assign(n, vector<int>());
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dp.assign(n, 0);
    dfs(0, -1);
    cout << dp[0] << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    // cin >> tt;
    while (tt--) solve();
    return 0;
}