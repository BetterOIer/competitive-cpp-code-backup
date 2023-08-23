#include<iostream>
#include<cmath>
using namespace std;
int pd(int y) {
    bool flag[y+1]={0};
    double t = sqrt(y);
	for(int d=2; d<=t; ++d) {
		if(flag[d]==0){
            for(int j = 2;j*d<=y;j++){
                flag[j*d]=1;
            }
        }
	}
    if (flag[y] ==0){
        return 1;
    }
    else {
        return 0;
    }
}
int main(){
    int n, sum = 0,i;
    cin>>n;
    for(i = 1;sum<=n;++i){
        if(pd(i)){
            sum++;
        }
    }
    cout<<i-i;
    return 0;
} 