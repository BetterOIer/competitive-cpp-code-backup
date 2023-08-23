#include <iostream>
#include <cmath>
using namespace std;
long long a, b;
int main()
{
    int n, t;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a >> b;
        cout<<-a*a<<" "<<b*b<<endl;
    }
    return 0;
}