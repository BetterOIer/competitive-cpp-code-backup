#include<iostream>
//#include<cstdio>
//#include<algorithm>
//#include<cstring>
//#include<string>
//#include<cstdin>
//#include<cmath>
//#include<stdlib>
//#include<queue>
//#include<vector>
//#include<stack>
using namespace std;
int Y2,M2,D2;
void shijianjisuan(int t){
    if(D2+t>7){
        D2=
    }
}
int main(){
    //freopen("P.in","r",stdin);
    //freopen("P.out","w",stdout);
    int y,m,d,Y1,M1,D1;
    cin>>y>>m>>d;
    D1=1;
    if(m==12){
        M1=1;
        Y1=y+1;
    }else{
        M1=m+1;
        Y1=y;
    }
    while(Y1!=Y2&&M1!=M2&&D1!=D2){
        D1+=6;
    }
 	//fclose(stdin);
    //fclose(stdout);
    return 0;
}
