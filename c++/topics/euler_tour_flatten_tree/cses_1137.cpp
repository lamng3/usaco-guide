// problem url: https://cses.fi/problemset/task/1137
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector< vector<int> > vii;
typedef vector<ll> vl;

struct Fenwick {
    int n; vl ft;
    void init(int _n) {
        n = _n;
        ft.assign(n+1, 0);
    }
    void update(int k, ll u) {
        for (; k <= n; k+=k&-k) ft[k] += u;
    }
    ll query(int k) {
        ll s = 0;
        for (; k > 0; k-=k&-k) s += ft[k];
        return s;
    }
};

int n, q;
vi order, sz;
vl v;
vii adj;

int dfs(int u, int p) {
    order.push_back(u);
    for (int w : adj[u]) if (w != p) {
        sz[u] += dfs(w, u);
    }
    return sz[u];
}

void solve() {
    cin >> n >> q;
    v.assign(n+1, 0); for (int i = 1; i <= n; i++) cin >> v[i];

    adj.assign(n+1, vi());
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    sz.assign(n+1, 1);
    order.clear(); order.push_back(-1); // virtual
    dfs(1, 0);
    
    unordered_map<int,int> pos;
    pos.reserve(n*2);
    for (int i = 1; i <= n; i++) pos[order[i]] = i;

    Fenwick ft; ft.init(n);
    for (int i = 1; i <= n; i++) {
        int u = order[i];
        ft.update(i, v[u]);
    }

    for (int i = 0; i < q; i++) {
        int t; cin >> t;
        if (t == 1) {
            int s; ll nv;
            cin >> s >> nv;
            int L = pos.at(s);
            ll delta = nv - v[s];
            v[s] = nv;
            ft.update(L, delta);
        }
        else if (t == 2) {
            int s; cin >> s;
            int L = pos.at(s);
            int R = L + sz[s] - 1;
            ll sum = ft.query(R) - ft.query(L - 1);
            cout << sum << '\n';
        }
    }
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