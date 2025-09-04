// problem url: https://leetcode.com/problems/sliding-window-maximum/description/
// difficulty: hard
/*
classic problem: from sliding window minimum in CPH 8.3
*/
#include <bits/stdc++.h>
using namespace std;

/*
<in>
8 3
1 3 -1 -3 5 3 6 7
<out>
3 3 5 5 6 7
*/
void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n); for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> ans(n-k+1);
    deque<int> dq; // monotonic / decreasing stack
    for (int i = 0; i < n; i++) {
        while (!dq.empty() && dq.front() <= i-k) dq.pop_front();
        while (!dq.empty() && a[dq.back()] < a[i]) dq.pop_back();
        dq.push_back(i);
        if (i >= k-1) ans[i-k+1] = a[dq.front()];
    }
    for (int i = 0; i < n-k+1; i++) cout << ans[i] << (i==n-k?'\n':' ');
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int tt = 1;
    // cin >> tt;
    while (tt--) solve();
    return 0;
}