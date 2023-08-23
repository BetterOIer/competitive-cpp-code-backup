#include<iostream>
#include<cstring>
using namespace std;
const int N = 21, INF = 0x3f3f3f3f;
int dp[1 << N], vis[1 << N]; //dp [i] i为状态压缩的1-n每一位的选择情况的最小花费 ，
int n, m;
int a[25];

int cal(string s)
{
	int ans=0;
    for(int i=0;i<s.size();i++)
    {
        ans=ans*2+s[i]-'0';
    }
	return ans;
}

int f(int t1, int t2)
{
	int ans = 0;
	for (int i = 0; i < 21; i++)
	{
		if (((t1>>i&1)==0)&&(t2>>i&1))
		{
			ans++;
		}
	}
	return ans * ans;
}



int main()
{
	memset(dp, 0x3f, sizeof(dp));
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		string s;
		cin >> s;
		a[i] = cal(s);
	}
	int mx = (1 << n) - 1;
	dp[0] = 0;
	for (int i = 0; i <= (1 << n) - 1; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i>>j&1) continue;
			int tep = dp[i] + f(vis[i], a[j+1]);
			if (tep < dp[i | (1 << j)])
			{
				dp[i | (1 << j)] = tep;
				vis[i | (1 << j)] = vis[i] | a[j+1];
			}
		}
	}
	cout << dp[mx] << endl;
}