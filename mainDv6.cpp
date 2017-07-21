#include <iostream>
#include <stdio.h>

using namespace std;

int     g_n, g_k;

int     diffbits(const void *a, const void *b) {
    unsigned char x, y, *xx = (unsigned char*)a, *yy = (unsigned char*)b;
    int j, i, wr = 0, gl = 0;
    int aa[] = {0, 0, 0, 0, 0, 0, 0, 0};
    int bb[] = {0, 0, 0, 0, 0, 0, 0, 0};
    int kek = (int)a, lul = (int)b;
    if (a == b && wr == g_k)
        return (1);
    while (gl < 4) {
        x = xx[gl];
        y = yy[gl];
        if (x != y) {
            i = 0;
            j = 128;
            while (i < 8) {
                x >> i;
                x << i << 7 - i;
                y >> i;
                y << i << 7 - i;
                if (x != y)
                    wr++;
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
    int num[g_n], i = 0, def = 0;
    while (i < g_n)
    {
        cin >> num[i];
        for (int a = 0; a < i; a++)
            if (diffbits(num + a, num + i))
                def++;
        i++;
    }
    cout << def << endl;
    return 0;
}