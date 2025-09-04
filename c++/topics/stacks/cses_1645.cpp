// problem url: https://cses.fi/problemset/task/1645
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

void solve() {
    int n; cin >> n;
    vi x(n); for (int i = 0; i < n; i++) cin >> x[i];
    vi ans(n, 0);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && x[st.top()] >= x[i]) st.pop();
        ans[i] = st.empty() ? 0 : st.top() + 1;
        st.push(i);
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << (i==n-1 ? '\n' : ' ');
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int tt = 1;
    // cin >> tt;
    while (tt--) solve();
    return 0;
}