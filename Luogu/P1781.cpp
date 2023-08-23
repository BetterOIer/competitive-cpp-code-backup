#include<iostream>
using namespace std;
struct president{
    int num;
    string tick;
}a[21];
int main(){
    int n;
    string s1,s2;
    cin>>n;
    for(int i = 1;i<=n;i++){
        a[i].num = i;
        cin>>a[i].tick;
    }
    a[0].tick = "";
    for(int i = 1;i<=n;i++){
        int t1 = a[i].tick.length(),t2 = a[0].tick.length();
        if(t1>t2){
            a[0].num = a[i].num;
            a[0].tick = a[i].tick;
        }else if(t1<t2){
            continue;
        }else{
            for(int w = 0;w<=t1-1;w++){
                if(a[i].tick[w]>a[0].tick[w]){
                    a[0].num = a[i].num;
                    a[0].tick = a[i].tick;
                }else if(a[i].tick[w]<a[0].tick[w]){
                    break;
                }
            }
        }
    }
    cout<<a[0].num<<endl<<a[0].tick;
    return 0;
} 