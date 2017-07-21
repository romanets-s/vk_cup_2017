#include <iostream>

using namespace std;

int main() {
    int n, nn, i, t;
    cin >> n;
    nn = n;
    cin >> t;
    if (n == 1)
    {
        cout << t << endl;
        return 0;
    }
    i = t;
    n -= 1;
    while (n--) {
        cin >> t;
        if (t < i)
            i = t;
    }
    if (nn == 3)
        cout << i + 1 << endl;

    else
        cout << i + 2 << endl;
    return 0;
}