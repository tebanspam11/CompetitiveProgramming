#include <iostream>
using namespace std;

void solve() {
    int t; cin >> t;

    for(int i = 0; i < t; i++) {
        long long n; cin >> n;
        if ((n & (n - 1)) == 0) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   solve();
   return 0;
}