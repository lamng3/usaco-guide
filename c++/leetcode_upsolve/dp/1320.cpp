// problem url: https://leetcode.com/problems/minimum-distance-to-type-a-word-using-two-fingers/description/
// difficulty: hard
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

const int oo = 1e9+7;

pii locate(char c) {
    int x = c - 'A';
    return make_pair(x / 5, x % 5);
}

int distance(char a, char b) {
    pii pa = locate(a);
    pii pb = locate(b);
    return abs(pa.first - pb.first) + abs(pa.second - pb.second);
}

void solve() {
    /*
        states: dp[L][i][j], where:
            - L is the current position in the word
            - i is finger 1 at character 'A' + i
            - j is finger 2 at character 'A' + j
        dp[L][i][j] is the minimum distance to type word[0..L] 
            ending with finger 1 at character 'A' + i and
            ending with finger 2 at character 'A' + j.
        transitions:
            dp[L][c[L]][j] = min(dp[L-1][i][j] + distance(c[L], cj))
            dp[L][i][c[L]] = min(dp[L-1][i][j] + distance(c[L], cj))
        as next row only depends on previous rows, we can reduce the dimension
    */
    string word; getline(cin, word);
    int n = word.size();
    
    int dp[n][26][26];
    for (int L = 0; L < n; L++) {
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                dp[L][i][j] = oo;
            }
        }
    }
    
    // fill first row
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            dp[0][i][j] = min(dp[0][i][j], distance(word[0], (char)('A'+i)));
            dp[0][i][j] = min(dp[0][i][j], distance(word[0], (char)('A'+j)));
        }
    }

    for (int L = 1; L < n; L++) {
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                int c = word[L]-'A';
                dp[L][c][j] = min(dp[L][c][j], dp[L-1][i][j] + distance(word[L], (char)('A'+i)));
                dp[L][i][c] = min(dp[L][i][c], dp[L-1][i][j] + distance(word[L], (char)('A'+j)));
            }
        }
    }

    int best = oo;
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            best = min(best, dp[n-1][i][j]);
        }
    }
    cout << best << '\n';
}

void solve_optimize() {
    /*
        optimize with dimension reduction
        same time complexity O(N * 26 * 26)
    */ 
    string word; getline(cin, word);
    int n = word.size();

    int prev[26][26], curr[26][26];
    // don't use memset for non-0/1
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            prev[i][j] = curr[i][j] = oo;
        }
    }

    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            curr[i][j] = min(curr[i][j], distance(word[0], (char)('A'+i)));
            curr[i][j] = min(curr[i][j], distance(word[0], (char)('A'+j)));
        }
    }

    for (int L = 1; L < n; L++) {
        // prev = cur
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                prev[i][j] = curr[i][j];
            }
        }
        // reset curr for new row
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                curr[i][j] = oo;
            }
        }
        // update current
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                int c = word[L] - 'A';
                curr[c][j] = min(curr[c][j], prev[i][j] + distance(word[L], (char)('A'+i)));
                curr[i][c] = min(curr[i][c], prev[i][j] + distance(word[L], (char)('A'+j)));
            }
        }
    }

    int best = oo;
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            best = min(best, curr[i][j]);
        }
    }
    cout << best << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    // cin >> tt;
    while (tt--) solve_optimize();
    return 0;
}