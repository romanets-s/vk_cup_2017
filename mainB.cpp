#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

typedef struct s_stud
{
	int n; //n-student
	int count; //how many peoply send
	int flag; //know or not, 1 || 0
} t_stud;

int compare (const void *a, const void *b)
{
  const t_stud *orderA = (t_stud *)a;
  const t_stud *orderB = (t_stud *)b;
  int aa = orderA->count;
  int bb = orderB->count;
  // return ( orderB->all_bed - orderA->all_bed );
  return (bb - aa);
}

void	vk(int n, int *st)
{
	t_stud std[n];

	int nn = 1;
	for (int i = 0; i < n; ++i)
	{
		std[i].n = nn++;
		std[i].count = st[i];
		std[i].flag = 0;
	}
	std[0].flag = 1;
	if (std[0].count == 0)
	{
		cout << -1 << endl;
		return ;
	}
	qsort ((void*)std, n, sizeof(std[0]), compare);
	int ii;
	for (int i = 0; i < n; ++i)
	{
		if (std[i].flag == 1)
		{
			ii = i;
			break;
		}
	}

	int f = 1;
	int start = 0;
	int finish = n - 1;
	int iii = ii;

	int m = 0;
	int s1[142];
	int s2[142];

	while (f != n)
	{
		if (iii < n && std[iii].flag == 1 && std[iii].count > 0 && iii < n)
		{
			while (std[iii].count != 1  && f != n && finish >= 0)
			{
				if (std[finish].flag == 0)
				{
					s1[m] = std[iii].n;
					s2[m] = std[finish].n;
					m++;
					std[finish--].flag = 1;
					std[iii].count -= 1;
					f++;
				}
				else
					finish--;
			}
			while (std[iii].count != 0 && f != n && start < n)
			{
				if (std[start].flag == 0 && start < n)
				{
					s1[m] = std[iii].n;
					s2[m] = std[start].n;
					m++;
					std[start++].flag = 1;
					std[iii].count -= 1;
					f++;
				}
				else
					start++;
			}
			if (start != 0)
				iii = start - 1;
			else
				iii = start;
		}
		else
			iii++;
		//cout << start << ' ' << finish << ' ' << n << endl;
		if (iii > n && f != n)
			break;		
	}

	int nnn = -1;
	if (f == n)
	{
		cout << m << endl;
		while (++nnn < m)
			cout << s1[nnn] << ' ' << s2[nnn] << endl;
	}
	else
		cout << -1 << endl;
}

int main() {
    int n, gn;
    cin >> n;
    gn = n;
    int st[gn + 1];
    st[gn] = -1;
    n = 0;
    while (n < gn)
        cin >> st[n++];
    vk(gn, st);
    return 0;
}
