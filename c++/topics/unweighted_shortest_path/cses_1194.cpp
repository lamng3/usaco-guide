// problem url: https://cses.fi/problemset/task/1194
#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector< vector<int> > vii;

const int INF = 1e9+7;

int di[4] = {0,0,1,-1};
int dj[4] = {1,-1,0,0};
char dir[4] = {'R','L','D','U'};
// char rdir[4] = {'L','R','U','D'}; // reverse direction

int n, m;
vector<string> mp;

bool inside(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m && mp[x][y] != '#';
}

void solve() {
    cin >> n >> m;
    mp.resize(n); for (int i = 0; i < n; i++) cin >> mp[i];

    /*
        idea: d[i][j] = min time a monster can get there
    */
    vii monster(n, vi(m, INF));
    vii A(n, vi(m, INF));
    queue<pii> q;

    int Ai = -1, Aj = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mp[i][j] == 'M') {
                q.push(pii(i,j));
                monster[i][j] = 0;
            }
            if (mp[i][j] == 'A') { Ai = i; Aj = j; }
        }
    }

    while (!q.empty()) {
        pii u = q.front(); q.pop();
        int ui = u.fi, uj = u.se;
        for (int i = 0; i < 4; i++) {
            int vi = ui + di[i], vj = uj + dj[i];
            if (!inside(vi, vj)) continue;
            if (monster[ui][uj] + 1 < monster[vi][vj]) {
                monster[vi][vj] = monster[ui][uj] + 1;
                q.push(pii(vi,vj));
            }
        }
    }

    vector< vector<char> > direction(n, vector<char>(m, '-'));
    A[Ai][Aj] = 0;
    q.push(pii(Ai,Aj));
    while (!q.empty()) {
        pii u = q.front(); q.pop();
        int ui = u.fi, uj = u.se;
        for (int i = 0; i < 4; i++) {
            int vi = ui + di[i], vj = uj + dj[i];
            if (!inside(vi, vj)) continue;
            if (A[ui][uj] + 1 >= monster[vi][vj]) {
                // A goes to (vi,vj) and meet a monster there
                continue;
            }
            if (A[vi][vj] == INF) {
                A[vi][vj] = A[ui][uj] + 1;
                // update path
                direction[vi][vj] = dir[i];
                q.push(pii(vi,vj));
            }
        }
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         if (mp[i][j] != '#') {
    //             cerr << i << " " << j << " " << mp[i][j] << " " << monster[i][j] << " A goto " << A[i][j] << '\n';
    //         }
    //     }
    // }

    // check no path exists
    bool ok = false;
    for (int i = 0; i < n; i++) ok |= (A[i][0] != INF) || (A[i][m-1] != INF);
    for (int j = 0; j < m; j++) ok |= (A[0][j] != INF) || (A[n-1][j] != INF);
    if (!ok) { cout << "NO" << '\n'; return; }

    // find a solution
    int Bi = -1, Bj = -1;
    for (int i = 0; i < n; i++) {
        if (A[i][0] != INF) { Bi = i; Bj = 0; break; }
        if (A[i][m-1] != INF) { Bi = i; Bj = m-1; break; }
    }
    for (int j = 0; j < m; j++) {
        if (A[0][j] != INF) { Bi = 0; Bj = j; break; }
        if (A[n-1][j] != INF) { Bi = n-1; Bj = j; break; }
    }

    cout << "YES" << '\n';
    cout << A[Bi][Bj] << '\n';

    // construct a solution
    vector<char> path;
    int x = Bi, y = Bj;
    while (inside(x, y) && direction[x][y] != '-') {
        int i;
        for (i = 0; i < 4 && direction[x][y] != dir[i]; i++);
        path.push_back(dir[i]);
        x -= di[i], y -= dj[i];
    }
    reverse(path.begin(), path.end());
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