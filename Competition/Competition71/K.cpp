#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1009;
const int M = 5e5 + 1009;
int n, k, o;
char s[N];
struct node{
    int p, f, len, e;
};
string solve(){
    k = o;
    for(int i = 1; i < n; i ++) {
        if(s[i] == '?' || s[i + 1] == '?') continue;
        if(s[i] != s[i + 1]) k --;
    }
    int minn = 0, maxn = 0;
    for(int i = 1; i < n; i ++) {
        if(s[i] != '?' && s[i + 1] == '?') {
            int len = 0;
            while(i + len + 1 <= n && s[i + len + 1] == '?') len ++;
            if(s[i] - '0' != s[i + len + 1] - '0') {
                minn ++;
                maxn += (len / 2) * 2 + 1;
            } else maxn += (len + 1) / 2 * 2;
            i += len;
        }
    }
    if(k < minn || ((k & 1) != (minn & 1)) || k > maxn) return "2";
    string S = "";
    for(int i = 1; i <= n; i ++) {
        // cout << i << endl;
        if(s[i] != '?') S += s[i];
        else {
            int len = 1;
            while(s[i + len] == '?') len ++;
            //cout << len << endl;
            int f = s[i - 1] - '0', e = s[i + len] - '0';
            if(f != e) {
                minn --;
                maxn -= (len / 2) * 2 + 1;
            } else maxn -= (len + 1) / 2 * 2;
            int Minn = max(0, k - maxn), Maxn = k - minn;
            if(f != e) {
                Minn --; Maxn --;
                Minn = (Minn + 1) / 2; Maxn /= 2;
                if(f == 0) {
                    int t = len - (Minn * 2);
                    k --;
                    while(t --) S += "0";
                    while(Minn --) {
                        S += "10";
                        k -= 2;
                    }
                } else {
                    int t = len - (Minn * 2);
                    while(t --) S += "0";
                    k --;
                    while(Minn --) {
                        S += "01";
                        k -= 2;
                    }
                }
            } else if(f == e) {
                Minn = (Minn + 1) / 2; Maxn /= 2;
                if(f == 0) {
                    int t = len - max(0, (Minn * 2) - 1);
                    while(t --) S += "0";
                    if(Minn) {
                        S += "1";
                        Minn --;
                        k -= 2;
                    }
                    while(Minn --) {
                        S += "01";
                        k -= 2;
                    }
                } else {
                    if(Maxn == 0) {
                        int t = len;
                        while(t --) S += "1";
                    } else {
                        if(Minn) Minn --;
                        int t = len - (Minn * 2);
                        while(t --) S += "0"; k -= 2;
                        while(Minn --) S += "10", k -= 2;
                    }
                }
            }
            i += len - 1;
        }
    }
    return S;
}
void work() {
    cin >> n >> k;
    cin >> s + 1;
    int flag1 = (s[1] == '?'), flag2 = (s[n] == '?');
    o = k;
    string ans = "2";
    for(int j = 0; j <= 1; j ++)
        if(flag1 || s[1] == '0' + j) {
            s[1] = '0' + j;
            for(int k = 0; k <= 1; k ++)
                if(flag2 || s[n] == '0' + k) {
                    s[n] = '0' + k;
                  //   cout << s + 1 << endl;
                    ans = min(ans, solve());
                }
        }
    if(ans == "2") cout << "Impossible" << endl;
    else cout << ans << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int Case = 1;
    cin >> Case;
    while(Case --) work();
    return 0;
}