#include<iostream>
using namespace std;
int cnt[1000005];
int main(){
    int wssb;
    cin>>wssb;
    for(int i = 1;i<=wssb;i++){
        int x;
        cin>>x;
        int t=__builtin_sqrt(x);
        for (int j = 1; j <= t; ++j) {
			if (x % j == 0) {
				++cnt[j];
				if (j * j != x) {
					++cnt[x / j];
				}
			}
		}
    }
    int ans = 1;
	for (int i = 2; i < 1000005; ++i) {
		ans = max(ans, cnt[i]);
	}
    cout<<ans;
}