#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
struct cyz{
    int h;
    int y,m,d;
    string n;
}a[5001];
int comp(cyz a,cyz b){
    if(a.y==b.y){
        if(a.m==b.m){
            if(a.d==b.d){
                return a.h>b.h;
            }else{
                return a.d<b.d;
            }
        }
        else{
            return a.m<b.m;
        }
    }else{
        return a.y<b.y;
    }
}
int main(){
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++){
        a[i].h = i;
        cin>>a[i].n>>a[i].y>>a[i].m>>a[i].d;
    }
    sort(a+1,a+n+1,comp);
    for(int i = 1;i<=n;i++){
        cout<<a[i].n<<" "<<endl;
    }
    return 0;
} 