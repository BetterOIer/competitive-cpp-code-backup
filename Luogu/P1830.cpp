#include <iostream>
using namespace std;
int n, m, t1, t2, M[1000][1000], last[1000][1000], k, i, j, xx, x2, yy, y2;
int main()
{
    scanf("%d%d%d%d", &n, &m, &t1, &t2);
    for (k = 1; k <= t1; k++)
    {
        scanf("%d%d%d%d", &xx, &yy, &x2, &y2);
        for (i = xx; i <= x2; i++)
            for (j = yy; j <= y2; j++)
            {
                M[i][j]++;
                last[i][j] = k;
            }
    }
    for (k = 1; k <= t2; k++)
    {
        scanf("%d%d", &xx, &yy);
        if (M[xx][yy] != 0)
            printf("Y %d %d\n", M[xx][yy], last[xx][yy]);
        else
            printf("N");
    }
}
