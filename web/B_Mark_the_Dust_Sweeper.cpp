#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ULL;
typedef long long LL; 
typedef pair<int, int> PII;
typedef pair<string, int> PSI;

int t, n, val;
LL ans;

void solve() {
    bool m = false;
    cin >> n;
    ans = 0;
    LL ct = 0;
    for (int i = 0; i < n; i++) {
        
        cin >> val;
        if (i == n-1) continue;
        if (val > 0) {
            m = true;
        }
        ct += val;
        if (val == 0 && m) ans++;
    }
    ans += ct;
    cout << ans << endl;
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
