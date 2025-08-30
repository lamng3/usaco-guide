#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

struct DSU {
    vi parent, sz, pos;
    vl sum;
    int vid; // virtual id

    void init(int n, int m){
        int N = n + m + 5; // reserve for virtual nodes
        parent.resize(N);
        sum.assign(N, 0);
        pos.resize(n);
        for (int i = 0; i < n; ++i){
            parent[i] = i;
            sum[i] = i + 1;
            pos[i] = i;
        }
        sz.assign(N, 1);
        vid = n;
    }

    int find(int x){ 
        return parent[x] == x ? x : parent[x] = find(parent[x]); 
    }

    bool unite(int p, int q){
        int u = find(pos[p]), v = find(pos[q]);
        if (u == v) return false;
        if (sz[u] < sz[v]) swap(u, v);
        parent[v] = u;
        sz[u] += sz[v];
        sum[u] += sum[v];
        return true;
    }

    bool move(int p, int q){
        int u = find(pos[p]), v = find(pos[q]);
        if (u == v) return false;

        // remove p from old set
        sz[u] -= 1;
        sum[u] -= (p + 1);

        // new virtual node
        int np = ++vid;
        parent[np] = np;
        sz[np] = 1;
        sum[np] = (p + 1);
        pos[p] = np; // update pointer of p to virtual node

        // unite with set q
        v = find(v);
        if (sz[v] < sz[np]) swap(v, np);
        parent[np] = v;
        sz[v] += 1;
        sum[v] += (p + 1);
        return true;
    }

    void info(int p){
        int r = find(pos[p]);
        cout << sz[r] << ' ' << sum[r] << '\n';
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    while (cin >> n >> m){
        DSU dsu; dsu.init(n, m);
        for (int i = 0; i < m; ++i){
            int t; cin >> t;
            if (t == 1){
                int p, q; cin >> p >> q;
                p--; q--;
                dsu.unite(p, q);
            } else if (t == 2){
                int p, q; cin >> p >> q;
                p--; q--;
                dsu.move(p, q);
            } else {
                int p; cin >> p; p--;
                dsu.info(p);
            }
        }
    }
    return 0;
}