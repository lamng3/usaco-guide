// problem url: https://usaco.org/index.php?page=viewproblem2&cpid=1469
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

void subtask1() {
    /*
        O(N^3)
    */
    int n; cin >> n;
    vi a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    vi pref(n, 0), suff(n, 0);
    pref[0] = (a[0]==b[0]);
    for (int i = 1; i < n; i++) pref[i] = pref[i-1] + (a[i]==b[i]);
    suff[n-1] = (a[n-1]==b[n-1]);
    for (int i = n-2; i >= 0; i--) suff[i] = suff[i+1] + (a[i]==b[i]);
    vi c(n+1, 0); // counts
    for (int L = 0; L < n; L++) {
        for (int R = L; R < n; R++) {
            vi x(n); for (int i = 0; i < n; i++) x[i] = a[i];
            int count = 0;
            if (L > 0) count += pref[L-1];
            if (R < n-1) count += suff[R+1];
            for (int i = L, j = R; i < j; i++, j--) swap(x[i], x[j]);
            for (int i = L; i <= R; i++) if (x[i] == b[i]) count++;
            c[count]++;
        }
    }
    for (int i = 0; i <= n; i++) cout << c[i] << '\n';
}

void subtask2() {
    /*
        O(N^2)
        elegant: choose a pivot index and expand
    */
    int n; cin >> n;
    vi a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    int s = 0; // current matched
    for (int i = 0; i < n; i++) s += (a[i]==b[i]);

    vi c(n+1, 0); // counts

    auto expand = [&](int l, int r) {
        /*
            expand from [l,r] to both sides
            increase match iteratively
        */
        int matched = s;
        for (; l >= 0 && r < n; l--, r++) {
            // swap a[l] and a[r] and compare with b[l] and b[r]
            matched += ((a[r] == b[l]) + (a[l] == b[r])); // after swap
            matched -= ((a[l] == b[l]) + (a[r] == b[r])); // before swap
            c[matched]++;
        }
    };

    for (int mid = 0; mid < n; mid++) {
        expand(mid, mid);
        expand(mid, mid+1);
    }
    for (int i = 0; i <= n; i++) cout << c[i] << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int tt = 1;
    // cin >> tt;
    while (tt--) {
        // subtask1();
        subtask2();
    }
    return 0;
}