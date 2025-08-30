// problem url: https://www.chuyentin.pro/2025/01/e-thi-hoc-sinh-gioi-thanh-pho-ha-noi.html
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int keep(vi& f, int k) {
    sort(f.begin(), f.end(), greater<int>());
    int s = 0; 
    for (int i = 0; i < k && i < (int)f.size(); i++) s += f[i];
    return s;
}

void solve() {
    int n, k, x; cin >> n >> k >> x;
    vi a(n); for (int i = 0; i < n; i++) cin >> a[i];
    vi f(10,0);
    int ans = 0;
    for (int i = 0, j = 0; i < n; i++) {
        while (j < n) {
            vi g = f; // work on copy of f
            g[a[j]]++;
            if (j-i+1-x <= keep(g, k)) {
                f[a[j]]++;
                j++;
            }
            else break;
        }
        ans = max(ans, j-i);
        f[a[i]]--;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    // cin >> tt;
    while (tt--) solve();
    return 0;
}