#include<iostream>
//#include<cstdio>
//#include<algorithm>
#include<cstring>
//#include<string>
//#include<cstdin>
//#include<cmath>
//#include<stdlib>
using namespace std;
int a[10];
void sjcl(int x){
    a[x%10] = 1;
    a[x/10%10]=1;
    a[x/100]=1;
}
bool deal(int x,int y,int z){
    memset(a,0,sizeof(a));
    if(y>999||z>999)return 0;
    sjcl(x),sjcl(y),sjcl(z);
    for(int i = 1;i<=9;i++){
        if(!a[i]) return 0;
    }
    return 1;
}
int main(){
    //freopen("P.in","r",stdin);
    //freopen("P.out","w",stdout);
    int A,B,C,x,y,z,sum=0;
    cin>>A>>B>>C;
    for(x=123;x<=333;x++){
        if(x*B%A||x*C%A){
            continue;
        }
        y = x*B/A;
        z = x*C/A;
        if(deal(x,y,z)){
            cout<<x<<" "<<y<<" "<<z<<endl;
            sum++;
        }
    }
    if(!sum){
        cout<<"No!!!";
    }
 	//fclose(stdin);
    //fclose(stdout);
    return 0;
} 