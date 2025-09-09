// problem url: https://oj.uz/problem/view/BOI13_tracks
#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

typedef vector<int> vi;
typedef vector< vector<int> > vii;
typedef pair<int,int> pii;

const int INF = 1e9+7;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int h, w;
vector<string> snow;

bool inside(int x, int y) {
    return 0 <= x && x < h && 0 <= y && y < w && snow[x][y] != '.';
}

void solve() {
    cin >> h >> w; snow.resize(h);
    for (int i = 0; i < h; i++) cin >> snow[i];

    if (snow[0][0] == '.') {
        cout << 0 << '\n';
        return;
    }

    int ans = 1;
    vii d(h, vi(w, INF));
    d[0][0] = 1;
    
    deque<pii> dq;
    dq.push_back(pii(0,0));
    while (!dq.empty()) {
        pii u = dq.front(); dq.pop_front();
        int ux = u.fi, uy = u.se;
        ans = max(ans, d[ux][uy]);
        for (int i = 0; i < 4; i++) {
            int vx = ux + dx[i], vy = uy + dy[i];
            if (!inside(vx, vy)) continue;
            int w = (snow[ux][uy] != snow[vx][vy]);
            if (d[vx][vy] == INF) {
                d[vx][vy] = d[ux][uy] + w;
                if (w) dq.push_back(pii(vx,vy));
                else dq.push_front(pii(vx,vy));
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