#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

char *strnew(char *s, int i)
{
    int n = -1;
    s = (char *)malloc(sizeof(char) * i + 1);
    while (++n <= i)
        s[n] = '\0';
    return (s);
}

int strlen(char *s)
{
    int i = 0;

    while (s[i])
        i++;
    return (i);
}

int *position(char **map, int row, int col)
{
    int *poz;

    poz = (int *)malloc(sizeof(int) * 2);
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            if (map[i][j] == 'X')
            {
                poz[0] = i;
                poz[1] = j;
                return (poz);
            }
        }
    }
    return (poz);
}

char check_step(char **map, int row, int col, int x, int y, int st, int step, char old)
{
    if (step / 2 < st)
    {
        if (x - 1 >= 0)
        {
            if (map[x - 1][y] == '.' && old != 'U')
            {
                map[x][y] = '.';
                map[x - 1][y] = 'X';
                return ('U');
            }
        }
        if (y - 1 >= 0)
        {
            if (map[x][y - 1] == '.' && old != 'L')
            {
                map[x][y] = '.';
                map[x][y - 1] = 'X';
                return ('L');
            }
        }
        if (y + 1 < col)
        {
            if (map[x][y + 1] == '.' && old != 'R')
            {
                map[x][y] = '.';
                map[x][y + 1] = 'X';
                return ('R');
            }
        }
        if (x + 1 < row)
        {
            if (map[x + 1][y] == '.' && old != 'D')
            {
                map[x][y] = '.';
                map[x + 1][y] = 'X';
                return ('D');
            }
        }
    }
    else
    {
        if (x + 1 < row)
        {
            if (map[x + 1][y] == '.' && old != 'D')
            {
                map[x][y] = '.';
                map[x + 1][y] = 'X';
                return ('D');
            }
        }
        if (y - 1 >= 0)
        {
            if (map[x][y - 1] == '.' && old != 'L')
            {
                map[x][y] = '.';
                map[x][y - 1] = 'X';
                return ('L');
            }
        }
        if (y + 1 < col)
        {
            if (map[x][y + 1] == '.' && old != 'R')
            {
                map[x][y] = '.';
                map[x][y + 1] = 'X';
                return ('R');
            }
        }
        if (x - 1 >= 0)
        {
            if (map[x - 1][y] == '.' && old != 'U')
            {
                map[x][y] = '.';
                map[x - 1][y] = 'X';
                return ('U');
            }
        }
    }
    return ('Q');

}

void    del(char **map, char tmp, int x, int y)
{
    if (tmp == 'D')
    {
        map[x][y] = '.';
        map[x - 1][y] = 'X';
    }
    if (tmp == 'L')
    {
        map[x][y] = '.';
        map[x][y + 1] = 'X';
    }
    if (tmp == 'R')
    {
        map[x][y] = '.';
        map[x][y - 1] = 'X';
    }
    if (tmp == 'U')
    {
        map[x][y] = '.';
        map[x + 1][y] = 'X';
    }
}

int check_finish(char **map, int x, int y, int xx, int yy)
{
    if (x == xx && y == yy)
        return (1);
    return (0);
}

int check_a(char *answer, int step)
{
    if (strlen(answer) == step)
        return (1);
    return (0);
}

void    ddl(char *answer, int step)
{
    int n = step / 2;
    while (n < step)
        answer[n] = '0';
}

int skaynet(char **map, int step, int row, int col, char *answer, int st, int x, int y, char old, int xx, int yy)
{
    char tmp;

    if (check_a(answer, step) && x == xx && y == yy)
        return (1);
/*
    if (check_a(answer, step))
    {
        if (x == xx && y == yy)
            return (1);
        else
            ddl(answer, step);
    }
    */

    while (strlen(answer) != step)
    {
        if (tmp = check_step(map, row, col, x, y, st, step, old))
        {
            answer[st++] = tmp;
            if (tmp == 'D')
                x++;
            else if (tmp == 'L')
                y--;
            else if (tmp == 'R')
                y++;
            else if (tmp == 'U')
                x--;
/*            if (strlen(answer) == step && (x != xx || y != yy))
                goto del_point;*/
            if (skaynet(map, step, row, col, answer, st, x, y, old, xx, yy))
                return (1);
            del_point: ;
            old = tmp;
            answer[--st] = 0;
            del(map, tmp, x, y);
        }
    }
    //ddl(answer, step);
    return (0);
}

int robot(char **map, int step, int row, int col)
{
    char *answer;
    int *poz;

    answer = strnew(answer, step);
    poz = position(map, row, col);

char tmp;
int st = 0;
    //skaynet(map, step, row, col, answer, 0, poz[0], poz[1], '.', poz[0], poz[1]);
        tmp = check_step(map, row, col, poz[0], poz[1], st, step, '.');
        if (tmp == 'Q')
        {
            cout << "IMPOSSIBLE" << endl;
            return (42);
        }
        answer[st++] = tmp;

            if (tmp == 'D')
            {
                while (strlen(answer) != step)
                {
                    if (answer[st - 1] == 'D')
                        answer[st] = 'U';
                    else
                        answer[st] = 'D';
                    st++;
                }
            }
            else if (tmp == 'L')
            {
                while (strlen(answer) != step)
                {
                    if (answer[st - 1] == 'L')
                        answer[st] = 'R';
                    else
                        answer[st] = 'L';
                    st++;
                }
            }
            else if (tmp == 'R')
            {
                while (strlen(answer) != step)
                {
                    if (answer[st - 1] == 'R')
                        answer[st] = 'L';
                    else
                        answer[st] = 'R';
                    st++;
                }
            }
            else if (tmp == 'U')
            {
                while (strlen(answer) != step)
                {
                    if (answer[st - 1] == 'U')
                        answer[st] = 'D';
                    else
                        answer[st] = 'U';
                    st++;
                }
            }

    cout << answer << endl;

    return (42);
}

int main() {
    int n, m, step;
    cin >> n >> m >> step;
    char **map;
    map = (char **)malloc(sizeof(char *) * n);
    for (int i = 0; i < n; ++i)
        map[i] = (char *)malloc(sizeof(char) * m + 1);
    for (int i = 0; i < n; ++i)
    {
        for (int l = 0; l < m; ++l)
        {
            cin >> map[i][l];
            map[i][l + 1] = '\0';
        }
    }
    robot(map, step, n, m);
    return 0;
}
