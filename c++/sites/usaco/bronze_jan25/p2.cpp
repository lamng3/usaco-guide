// problem url: https://usaco.org/index.php?page=viewproblem2&cpid=1468
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

void solve() {
    int n; cin >> n;
    vi a(n); for (int i = 0; i < n; i++) cin >> a[i];
    // pref[i] = how many distinct numbers different from a[i] before i
    vi pref(n);
    unordered_set<int> st;
    for (int i = 0; i < n; i++) {
        pref[i] = st.size() - (st.find(a[i]) != st.end());
        st.insert(a[i]);
    }
    unordered_map<int,int> pp;
    ll ans = 0;
    // only take last 2
    for (int i = n-1; i >= 0; i--) {
        pp[a[i]]++; 
        if (pp[a[i]] == 2) {
            ans += (ll) pref[i];
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