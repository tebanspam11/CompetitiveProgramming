//A. One and Two
#include <iostream>
using namespace std;

void one_and_two() {
    int t; 
    cin >> t;

    for(int i = 0; i < t; i++) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n;
        cin >> n;
        vector<string> array(n);
        
        for(int i = 0; i < n; i++) {
            cin >> array[i];
        }

        int twocount = 0;
        for (auto &x : array) {
            if (x == "2") twocount++;
        }

        if (twocount == 0) {
        cout << 1 << "\n";
        continue;
        }

        if (twocount % 2 == 1) {
        cout << -1 << "\n";
        continue;
        }

        int index = 0;
        for (int i = 0; i < n; i++) {
            if (array[i] == "2") {
                index++;
                if (index == twocount / 2) {
                    cout << (i + 1) << "\n";
                    break;
                }
            }
        }
    }
}

int main() {
    one_and_two();
    return 0;
}
