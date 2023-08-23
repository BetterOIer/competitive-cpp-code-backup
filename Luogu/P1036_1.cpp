#include <iostream>
#include <cmath>
using namespace std;
int x[20], n, k;
bool pdzs(int n)
{
    int s = sqrt(n);
    for (int i = 2; i <= s; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
int pcwyyyyyyyyyyyyyyyyyyyyyyds(int pcwNbest, int pzwyyds, int pcwnum1, int pcwyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyds)
{
    if (pcwNbest == 0)
        return pdzs(pzwyyds);
    int sum = 0;
    for (int i = pcwnum1; i <= pcwyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyds; i++)
    {
        sum += pcwyyyyyyyyyyyyyyyyyyyyyyds(pcwNbest - 1, pzwyyds + x[i], i + 1, pcwyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyds);
    }
    return sum;
}
int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> x[i];
    cout << pcwyyyyyyyyyyyyyyyyyyyyyyds(k, 0, 0, n - 1);
}