#include <iostream>
#define mod 1000000007
using namespace std;
long long dp[102][5500];
string s;
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < 26; i++)
    {
        dp[1][i] = 1;
    }
    for (int i = 2; i <= 100; i++)
    {
        dp[i][0] = 1;
        for (int j = 1; j <= 2700; j++)
        {
            for (int k = 0; k < 26; k++)
            {
                if (j - k >= 0)
                {
                    dp[i][j] = (dp[i][j] % mod + dp[i - 1][j - k] % mod) % mod;
                }
            }
        }
    }
    while (n--)
    {
        cin >> s;
        int sum = 0;
        for (int i = 0; i < s.size(); i++)
        {
            sum += s[i] - 'a';
        }
        cout << dp[s.size()][sum] % mod - 1 << endl;
    }
}