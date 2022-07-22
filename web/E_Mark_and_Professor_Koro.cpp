#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ULL;
typedef long long LL; 
typedef pair<int, int> PII;
typedef pair<string, int> PSI;

int n, q, a, idx;
const int N = 2e5+20;
int arr[N], arr2[N];
int f[N];
multiset<int> ms2;
multiset<int> ms;


int find(int x) {
    if (f[x] == x) return x;
    f[x] = find(f[x]);
    return f[x];
}

void solve() {
    cin >> n >> q;
    for (int i = 0; i < N; i++) {
        f[i] = i;
    }
    for (int i = 1; i <= n; i++) {
        cin >> a;
        arr2[i] = a;
        arr[a]++;
        ms.insert(a);
        if (arr[a] == 2) ms2.insert(a);
    }
    int top = *ms.rbegin();
    for (int i = top; i >= 1; i--) {
        if (arr[i] > 0 && arr[i-1] > 0) f[i] = i-1;
    }
    for (int i = 0; i < q; i++) {
        cin >> idx >> a;
        arr[a] ++;
        ms.insert(a);
        if (arr[a] == 2) ms2.insert(a);
        if (arr[a] > 0 && arr[a-1] > 0) {
            f[a] = a-1;
        }
        if (arr[a+1] > 0 && arr[a] > 0) {
            f[a+1] = a;
        }
        int val = arr2[idx];
        arr[val]--;
        ms.erase(ms.find(val));
        if (arr[val] == 1) ms2.erase(val);
        if (arr[val] == 0) {
            f[val+1] = val+1;
            f[val] = val;
        }
        arr2[idx] = a;
        if (ms2.size() > 0 && find(*ms.rbegin()) <= *ms2.rbegin()) {
            cout << (*ms.rbegin()) + 1 << endl;
        } else {
            cout << *ms.rbegin() << endl;
        }
    }


}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    
        solve();
    
    

    return 0;
}
