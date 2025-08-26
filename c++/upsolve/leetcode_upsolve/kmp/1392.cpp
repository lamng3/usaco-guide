// problem url: https://leetcode.com/problems/longest-happy-prefix/description/
// difficulty: hard
// KMP algorithm
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

vi prefix_function(string s) {
    vi pi(s.size());
    for (int i = 1; i < s.size(); i++) {
        int j = pi[i-1];
        while (j > 0 && s[j] != s[i]) j = pi[j-1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
    } 
    return pi;
}

void solve() {
    string s; getline(cin, s);
    vi pi = prefix_function(s);
    int L = pi[s.size()-1];
    cout << s.substr(0, L) << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    // cin >> tt;
    while (tt--) solve();
    return 0;
}