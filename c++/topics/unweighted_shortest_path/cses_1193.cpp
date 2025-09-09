// problem url: https://cses.fi/problemset/task/1193
#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector< vector<int> > vii;

const int INF = 1e9+7;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
char dir[4] = {'D','U','R','L'};
char rdir[4] = {'U','D','L','R'}; // reverse direction

int n, m;
vector<string> mp;

bool inside(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m && mp[x][y] != '#';
}

void solve() {
    cin >> n >> m;
    mp.resize(n); 
    for (int i = 0; i < n; i++) cin >> mp[i];

    int Ax = -1, Ay = -1, Bx = -1, By = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mp[i][j] == 'A') { Ax = i; Ay = j; }
            if (mp[i][j] == 'B') { Bx = i; By = j; }
        }
    }

    vii d(n, vi(m, INF));

    queue<pii> q;
    d[Ax][Ay] = 0;
    q.push(pii(Ax,Ay));

    // restore path
    vector< vector<char> > direction(n, vector<char>(m, '-'));
    direction[Ax][Ay] = '-';

    while (!q.empty()) {
        pii u = q.front(); q.pop();
        int ux = u.fi, uy = u.se;
        if (ux == Bx && uy == By) break;
        for (int i = 0; i < 4; i++) {
            int vx = ux + dx[i], vy = uy + dy[i];
            if (!inside(vx, vy)) continue;
            if (d[vx][vy] == INF) {
                d[vx][vy] = d[ux][uy] + 1;
                direction[vx][vy] = dir[i];
                q.push(pii(vx,vy));
            }
        }
    }

    if (d[Bx][By] == INF) {
        cout << "NO" << '\n';
        return;
    } 

    // construct solution
    vector<char> path;
    int x = Bx, y = By;
    while (inside(x, y) && direction[x][y] != '-') {
        // update x and y
        int i;
        for (i = 0; i < 4 && dir[i] != direction[x][y]; i++);
        path.push_back(dir[i]);
        x -= dx[i]; y -= dy[i];
    }
    reverse(path.begin(), path.end());

    cout << "YES" << '\n';
    cout << d[Bx][By] << '\n';
    string ans = "";
    for (int i = 0; i < (int)path.size(); i++) ans += path[i];
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