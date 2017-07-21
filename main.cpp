#include <iostream>

using namespace std;

int main() {
    int n, gn;
    cin >> n;
    gn = n;
    int st[gn + 1];
    st[gn] = -1;
    n = 0;
    while (n < gn)
        cin >> st[n++];
    int usest[gn + 1];
    n = 0;
    while (n < gn)
        usest[n++] = 0;
    usest[gn + 1] = -1;

    return 0;
}