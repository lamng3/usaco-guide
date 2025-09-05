// problem url: https://atcoder.jp/contests/dp/tasks/dp_o?lang=en
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

const int mod = 1e9+7;

int main() {
    int n; cin >> n;
    vi adj(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int a; cin >> a;
            if (a) adj[i] |= (1 << j);
        }
    }
    int FULL = 1 << n;
    vi man(n, 0);
    
}