// problem url: https://cses.fi/problemset/task/1648
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl; 

struct SqrtDecomp {
    int block_size;
    vi nums;
    vl blocks;
    void init(int sqrtn, vi& a) {
        block_size = sqrtn;
        blocks.assign(sqrtn, 0);
        nums = a;
        for (int i = 0; i < nums.size(); i++) {
            blocks[i / block_size] += nums[i];
        }
    }
    void update(int x, int v) {
        blocks[x / block_size] -= nums[x];
        nums[x] = v;
        blocks[x / block_size] += nums[x];
    }
    ll query(int r) {
        ll res = 0; int R = r / block_size;
        for (int i = 0; i < R; i++) res += blocks[i];
        for (int i = R * block_size; i <= r; i++) res += nums[i];
        return res;
    }
    ll query(int l, int r) {
        return query(r) - query(l-1);
    }
};

void solve() {
    int n, q; cin >> n >> q;
    vi x(n+1); for (int i = 1; i <= n; i++) cin >> x[i];
    SqrtDecomp sd; sd.init(sqrt(n)+1, x);
    for (int i = 0; i < q; i++) {
        int type; cin >> type;
        if (type == 1) {
            int k, u; cin >> k >> u;
            sd.update(k, u);
        }
        else if (type == 2) {
            int a, b; cin >> a >> b;
            cout << sd.query(a, b) << '\n';
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