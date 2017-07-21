#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int     g_n, g_k;

 /* reverse:  переворачиваем строку s на месте */
 void reverse(char s[])
 {
     int i, j;
     char c;
 
     for (i = 0, j = strlen(s)-1; i<j; i++, j--) {
         c = s[i];
         s[i] = s[j];
         s[j] = c;
     }
 }

 /* itoa:  конвертируем n в символы в s */
 void itoa(int n, char *s)
 {
     int i, sign;
 
     if ((sign = n) < 0)  /* записываем знак */
         n = -n;          /* делаем n положительным числом */
     i = 0;
     do {       /* генерируем цифры в обратном порядке */
         s[i++] = n % 10 + '0';   /* берем следующую цифру */
     } while ((n /= 10) > 0);     /* удаляем */
     if (sign < 0)
         s[i++] = '-';
     s[i] = '\0';
     reverse(s);
 }



int     diffbits(const void *a, const void *b) {
    unsigned char x, y, *xx = (unsigned char*)a, *yy = (unsigned char*)b;
    int j, i, wr = 0, gl = 0;
    char aa[9];
    char bb[9];
    while (gl < 4) {
        x = xx[gl];
        y = yy[gl];
        if (x != y) {
            /*
            i = 0;
            while (i < 8) {
                aa[i] = 0;
                bb[i] = 0;
                i++;
            }
            */
            /*
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
                if (aa[i] != bb[i]) {
                    wr++;
                    if (wr > g_k)
                        return (0);
                }
                i++;
                j /= 2;
            }
            */
            itoa (x, aa);
            itoa (y, bb);
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