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
        cout << year << " �� " << money << " Ԫ������� " << happiness << " % ����������" << buff << " Ԫ\n";
        cout << "�����CSP�þٰ��ˣ���������" << 700 + happiness * 3 << "��,�ɱ�50(������������)�����������շ�\n";
        int x = read();
        money += (700 + happiness * 3) * (x - 50 + buff);
        if (x > happiness)
            happiness -= (x - 100) / 5;
        if (x < happiness / 4)
            happiness += (25 - x) / 5;
        x = rand() % 10;
        if (x == 0) {
            cout << "CCF��������C��,�����-10,�ʽ�+20000\n";
            happiness -= 10;
            money += 20000;
        }
        if (x == 1) {
            cout << "��ר�ҳ��⣬�����+5,�ʽ�-10000\n";
            happiness += 5;
            money -= 10000;
        }
        if (x == 2) {
            cout << "����������������+10���ʽ�-20000������+2\n";
            happiness += 10;
            money -= 20000;
            buff += 2;
        }
        if (x == 3) {
            cout << "��ѡ�ֿ����⣬����������ʽ�-1000������-1\n";
            money -= 1000;
            buff--;
        }
        if (x < 4) {
            cout << "��ȷ���¼�\n";
            string s;
            cin >> s;
        }
        if (happiness < 0) {
            cout << "\nCCF��Ͷ�ߵ���";
            return;
        }

        if (money < 0) {
            cout << "\nCCF��Ϊ�ʽ��㵹��";
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