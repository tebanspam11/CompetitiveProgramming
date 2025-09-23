//A. Exponential Equation
#include <iostream>
using namespace std;

void exponential_equation() {
    int t; cin >> t;

    for(int i = 0; i < t; i++) {
        int n; cin >> n;
        if (n % 2 == 0) {
            cout << 1 << " " << n / 2 << endl;
        } else {
            cout << -1 << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    exponential_equation();
    return 0;
}
exponential()

//Observations: Even and odd
