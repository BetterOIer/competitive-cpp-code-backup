#include<iostream>
#include<cmath>
using namespace std;
int pd(long y) {
    int q = sqrt(y);
	for(long d=2; d<=q; ++d) {
		if(y%d==0) return 0;
	}
	return 1;
}
int hws(long x){
    long w=x,g=0;
    while(w>0){
        g = 10*g + w%10;
        w = (w-w%10)/10;
    }
    if (g!=x){
        return 0;
    }
    return 1;
}
int main(){
    long a, b ,c = 0;
    cin>>a>>b;
    for(long i=a;i<=b;++i){
        if(i%2==1&&i<=10000000){
            if(hws(i)){
                if(pd(i)){
                    cout<<i<<endl;
                }
            }
        }
    }
    return 0;
} 