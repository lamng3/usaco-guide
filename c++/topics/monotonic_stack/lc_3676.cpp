// problem url: https://leetcode.com/problems/count-bowl-subarrays/description/
// difficulty: medium
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

/*
inp:
5
2 5 3 1 4
out:
2
*/
void solve() {
    // monotonic stack problem
    int n; cin >> n;
    vi a(n); for (int i = 0; i < n; i++) cin >> a[i];
    vi st;

    // previous greater element
    st.clear();
    vi prev(n, -1);
    for (int i = 0; i < n; i++) {
        while (!st.empty() && a[st.back()] > a[i]) {
            st.pop_back();
        }
        if (!st.empty()) prev[i] = st.back();
        st.push_back(i);
    }

    // next greater element
    st.clear();
    vi next(n, -1);
    for (int i = n-1; i >= 0; i--) {
        while (!st.empty() && a[st.back()] > a[i]) {
            st.pop_back();
        }
        if (!st.empty()) next[i] = st.back();
        st.push_back(i);
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int l = prev[i], r = next[i];
        if (l != -1 && i - l + 1 >= 3) ans++;
        if (r != -1 && r - i + 1 >= 3) ans++;
    }
    cout << (int) ans << '\n';
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