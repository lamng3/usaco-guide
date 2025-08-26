// problem url: https://leetcode.com/problems/repeated-string-match/description/
// difficulty: medium 
// difficulty: hard for O(M+N)
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

int contains(string p, string s) {
    string a = p + '#' + s;
    vi pi = prefix_function(a);
    for (int x : pi) if (x == p.size()) return 1;
    return 0;
}

void solve() {
    string a; getline(cin, a);
    string b; getline(cin, b);
    int k = b.size() / a.size() + (b.size() % a.size() != 0);
    string ra = a; for (int i = 1; i < k; i++) ra += a;
    int answer = contains(b, ra) ? k : contains(b, ra+a) ? k + 1 : -1;
    cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    // cin >> tt;
    while (tt--) solve();
    return 0;
}