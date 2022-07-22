#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ULL;
typedef long long LL; 
typedef pair<int, int> PII;
typedef pair<string, int> PSI;

int t, n, c, q;
LL val;
const int C = 43;
string s;
LL f[C];
LL to[C];
LL ss[C];

char find(LL val) {
    // cout << val << endl;
    if (val <= ss[0]) return s[val-1];
    int i = 0;
    while (val > ss[i]) i++;
    // cout << i << ": i" << endl;
    return find(val - ss[i-1] - 1 + f[i]);
}

void solve() {
    cin >> n >> c >> q;
    cin >> s;
    ss[0] = n;
    LL cur = n;
    for (int i = 1; i <= c; i++) {
        cin >> f[i] >> to[i];
        cur += (to[i] - f[i] + 1);
        ss[i] = cur;
    }
    // for (int i = 0; i <= c; i++) {
    //     cout << ss[i] << " ";
    // }
    for (int i = 0; i < q; i++) {
        cin >> val;
        cout << find(val) << endl;
    }
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;

    while (t--) {
        solve();
    }
    

    return 0;
}
