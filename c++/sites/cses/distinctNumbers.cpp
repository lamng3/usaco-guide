// problem url: https://cses.fi/problemset/task/1621/
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    unordered_set<int> s;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        s.insert(x);
    }
    cout << s.size() << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt; // number of test cases
    while (tt--) solve();
    return 0;
}