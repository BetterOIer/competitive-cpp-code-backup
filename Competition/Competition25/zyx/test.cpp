#include <vector>
#include <map>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <iostream>
using namespace std;
#define inf 0x3f3f3f3f
#define minf 0x3f
#define inp(x) cin>>x
#define otp(x) cout<<x
#define otp_nl(x) cout<<x<<"\n"
#define otp_sp(x) cout<<x<<" "
#define int long long
#define veci vector<int>
#define str string
#define pb(x) push_back(x)
#define fr(k,len) for(k=0;k<len;k++)
#define nfr(k,len) for(int k=0;k<len;k++)
#define ret return
#define db long double
#define all(x) x.begin(),x.end()

namespace my_stl {

}

inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - 48;
        ch = getchar();
    }
    return x * f;
}

int qpow(int a, int t, int p) {
    a %= p;
    int b[64];
    b[0] = a;
    nfr(i, 63)b[i + 1] = (b[i] * b[i]) % p;
    int ans = 1;
    nfr(i, 64) {
        if (t & (1 << i)) {
            ans *= b[i];
            ans %= p;
        }
    }
    ret ans;
}

int gcd(int a, int b) {
    ret (b ? (gcd(b, a % b)) : a);
}

int invp(int a, int p) {
    ret qpow(a, p - 2, p);
}
int x, y;

void exgcd(int a, int b, bool f) {
    if (f)
        x = 0, y = 0;
    if (!b) {
        x = 1;
        y = 0;
        return;
    }
    exgcd(b, a % b, false);
    int tx = x;
    x = y;
    y = tx - a / b * y;
}

int inv(int a, int p) {
    exgcd(a, p, true);
    return (x + p) % p;
}

void solve() {
    srand(time(0));
    int money = 10000, happiness = 100;
    int year = 2022;
    int buff = 0;
    while (true) {
        system("cls");
        cout << year << " 年 " << money << " 元，满意度 " << happiness << " % 利润增长：" << buff << " 元\n";
        cout << "今年的CSP该举办了，参赛人数" << 700 + happiness * 3 << "人,成本50(不含利润增长)请输入您的收费\n";
        int x = read();
        money += (700 + happiness * 3) * (x - 50 + buff);
        if (x > happiness)
            happiness -= (x - 100) / 5;
        if (x < happiness / 4)
            happiness += (25 - x) / 5;
        x = rand() % 10;
        if (x == 0) {
            cout << "CCF被爆料买C队,满意度-10,资金+20000\n";
            happiness -= 10;
            money += 20000;
        }
        if (x == 1) {
            cout << "请专家出题，满意度+5,资金-10000\n";
            happiness += 5;
            money -= 10000;
        }
        if (x == 2) {
            cout << "更换评测机，满意度+10，资金-20000，利润+2\n";
            happiness += 10;
            money -= 20000;
            buff += 2;
        }
        if (x == 3) {
            cout << "有选手卡评测，损坏评测机，资金-1000，利润-1\n";
            money -= 1000;
            buff--;
        }
        if (x < 4) {
            cout << "请确认事件\n";
            string s;
            cin >> s;
        }
        if (happiness < 0) {
            cout << "\nCCF被投诉倒闭";
            return;
        }

        if (money < 0) {
            cout << "\nCCF因为资金不足倒闭";
            return;
        }

        year++;
    }
    ret;
}

signed main() {
    int t = 1;
    nfr(i, t) {
        solve();
    }
    ret 0;
}