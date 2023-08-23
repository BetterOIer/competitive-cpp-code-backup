#include<iostream>
using namespace std;
int ans = -1,num,n;
int cnt = 0;
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> num;
        if (ans == num) cnt += 1;
        else {
        if (cnt == 0) {
            ans = num;
            cnt = 1;
        }
        else cnt -= 1;
        }
    }
    cout<<ans<<endl;
}
