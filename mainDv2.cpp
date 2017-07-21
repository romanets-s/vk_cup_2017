#include <iostream>
#include <stdio.h>

using namespace std;

int     g_n, g_k;


/* A utility function to reverse a string  */
void reverse(char str[], int length)
{
    int start = 0;
    int end = length -1;
    while (start < end)
    {
        swap(*(str+start), *(str+end));
        start++;
        end--;
    }
}
 
// Implementation of itoa()
char* itoa(int num, char* str, int base)
{
    int i = 0;
    bool isNegative = false;
 
    /* Handle 0 explicitely, otherwise empty string is printed for 0 */
    if (num == 0)
    {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }
 
    // In standard itoa(), negative numbers are handled only with 
    // base 10. Otherwise numbers are considered unsigned.
    if (num < 0 && base == 10)
    {
        isNegative = true;
        num = -num;
    }
 
    // Process individual digits
    while (num != 0)
    {
        int rem = num % base;
        str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0';
        num = num/base;
    }
 
    // If number is negative, append '-'
    if (isNegative)
        str[i++] = '-';
 
    str[i] = '\0'; // Append string terminator
 
    // Reverse the string
    reverse(str, i);
 
    return str;
}



int     diffbits(int a, int b) {
    int i, wr = 0;
    char *aaa;
    char *bbb;

    aaa = (char *)malloc(sizeof(char) * 142);
    bbb = (char *)malloc(sizeof(char) * 142);

    aaa = itoa(a, aaa, 2);
    bbb = itoa(b, bbb, 2);
/*
printf("a = %d\n", a);
printf("b = %d\n", b);
printf("aaa = %s\n", aaa);
printf("bbb = %s\n", bbb);
*/
    i = 0;
    while (aaa[i] != '\0' && bbb[i] != '\0') {
        if (aaa[i] != bbb[i]) {
            wr++;
            if (wr > g_k)
                return (0);
        }
        i++;
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
    //printf("g_n %d\n", g_n);
    if (g_k == 0)
    {
        cout << g_n << endl;
        return 0;
    }
    for (int a = 0; a < g_n; a++)
    {
        for (int b = a + 1; b < g_n; b++)
        {
            if (diffbits(num[a], num[b]))
                i++;
        }
    }
    cout << i << endl;
    return 0;
}