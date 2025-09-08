// problem url: https://oj.uz/problem/view/BOI13_tracks
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector< vector<int> > vii;

const int INF = 1e9+7;

int h, w;
vector<string> snow;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

bool inside(int x, int y) {
    return 0 <= x && x < h && 0 <= y && y < w && snow[x][y] != '.';
}

/*
inp:
5 8 
FFR..... 
.FRRR... 
.FFFFF.. 
..RRRFFR 
.....FFF
out:
2
*/
void solve() {
    cin >> h >> w;
    snow.resize(h);
    for (int i = 0; i < h; i++) cin >> snow[i];

    // no rabbits or foxes
    if (snow[0][0] == '.') { cout << 0 << '\n'; return; }

    // initialize first cell
    vii d(h, vi(w, INF));
    deque<pii> dq;
    dq.push_back(pii(0,0));
    d[0][0] = 1;

    int ans = 1;
    while (!dq.empty()) {
        // auto [ux, uy] = dq.front() // for C++17
        pii u = dq.front();
        int ux = u.first, uy = u.second;
        dq.pop_front();
        ans = max(ans, d[ux][uy]);
        for (int i = 0; i < 4; i++) {
            int x = ux + dx[i], y = uy + dy[i];
            // what if: d[ux][uy] + w < d[x][y]
            // instead of d[x][y] == INF
            // answer: this is 0/1 BFS
            // d[x][y] == INF means each node will be visited once
            // 0/1 BFS we do not need relaxation like Dijkstra
            if (!inside(x,y)) continue;
            int w = snow[ux][uy] != snow[x][y];
            if (d[x][y] == INF) {
            // if (d[ux][uy] + w < d[x][y]) {
                d[x][y] = d[ux][uy] + w;
                if (w) dq.push_back(pii(x,y));
                else dq.push_front(pii(x,y));
            }
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    while (tt--) solve();
    return 0;
}