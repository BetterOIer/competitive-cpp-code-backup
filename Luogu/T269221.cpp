#include <iostream>
using namespace std;
int n,a[1000010], tree[3000000][2], depth=0;
void insert(int x) {
    int p = 0;
    for (int i = 30; ~i; i--) {
        int &s = tree[p][x >> i & 1];
        if (!s) s = ++depth;
        p = s;
    }
}
int srh(int x) {
    int p = 0,ans = 0;
    for (int i = 30; ~i; i--){
        int s = x >> i & 1;
        if (tree[p][!s]) {
            ans += (1 << i);
            p = tree[p][!s];
        }
        else  p = tree[p][s];
    }
    return ans;
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        insert(a[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) ans = max(ans, srh(a[i]));
    cout << ans << endl;;
    return 0;
}