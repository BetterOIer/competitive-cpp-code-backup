#include <iostream>
#include <cstring>
using namespace std;
int n;
int x;
int y;
int a[250005];
int Better_OIer[250005];
int PCW[65536];
int cnt[65536];
int NUMID[65536];
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int main()
{
    int S=read(), T=read();
    while (T--)
    {
        bool can_consider = 0;
        memset(Better_OIer, 0, sizeof(Better_OIer));
        memset(PCW, 0, sizeof(PCW));
        memset(cnt, 0, sizeof(cnt));
        n=read(),x=read(),y=read();
        for (int i = 1; i <= n; i++){
            a[i]=read();
            PCW[a[i]]++;
            NUMID[a[i]] = i;
        }
        for (int i = 65535; ~i!=0; i--){
            if (PCW[i] & 1){
                cnt[i] = 1;
            }
            else if (y && PCW[i]){
                cnt[i] = Better_OIer[NUMID[i]] = 1;
                y--;
            }
        }
        for (int i = n; y >= 1; i--){
            if (!Better_OIer[i]){
                Better_OIer[i] = 1;
                y-=1;
            }
        }
        for (int i = 65535; ~i!=0; i--){
            if (cnt[i] || can_consider){
                cout << cnt[i];
                can_consider = 1;
            }
        }
        if (!can_consider){
            cout << '0';
        }
        cout <<endl;
        for (int i = 2; i <= n; i++) cout << (Better_OIer[i] ? '|' : '^');
        cout <<endl;
    }
    return 0;
}