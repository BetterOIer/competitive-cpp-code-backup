#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int main(){
    freopen("10.in","w",stdout);
    srand((unsigned int)time(NULL));
    int n=3830;
    int b=n*2/3;
    cout<<n<<" "<<b<<endl;
    for(int i = 1;i<=n;i++){
        cout<<rand()%200001<<endl;
    }
    return 0;
}