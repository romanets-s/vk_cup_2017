#include <iostream>
#include <stdio.h>

using namespace std;

int     g_n, g_k;

int     diffbits(const void *a, const void *b) {
    unsigned char x, y, *xx = (unsigned char*)a, *yy = (unsigned char*)b;
    int aa[8], bb[8], j, i, wr = 0, gl = 0;
    while (gl < 4) {
        x = xx[gl];
        y = yy[gl];
        if (x != y) {
            i = 0;
            while (i < 8) {
                aa[i] = 0;
                bb[i] = 0;
                i++;
            }
            i = 0;
            j = 128;
            while (i < 8) {
                if (x / j) {
                    aa[i] = 1;
                    x -= j;
                }
                if (y / j) {
                    bb[i] = 1;
                    y -= j;
                }
                i++;
                j /= 2;
            }
            i = 0;
            while (i < 8) {
                if (aa[i] != bb[i]) {
                    wr++;
                    if (wr > g_k)
                        return (0);
                }
                i++;
            }
        }
        gl++;
    }
    if (wr == g_k)
        return (1);
    return (0);
}

int     main() {
    cin >> g_n >> g_k;
    int num[g_n], i = 0;;
    while (i < g_n)
        cin >> num[i++];
    i = 0;
    for (int a = 0; a < g_n; a++)
    {
        for (int b = a + 1; b < g_n; b++)
        {
            if (diffbits(num + a, num + b))
                i++;
        }
    }
    cout << i << endl;
    return 0;
}