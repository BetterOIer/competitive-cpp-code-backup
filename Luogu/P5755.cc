#include<iostream>
using namespace std;
struct node{
    char val;
    int f_c,n_c;
}a[100000];
int t=1,p=0;
int main(){
    string s;
    while(cin>>s){
        p=0;
        for(int i = 0;i<=s.length()-1;i++){
            int now=a[p].f_c;
            if(now==0){
                a[t].val=s[i];
                a[p].f_c=t;
                p=t,t++;
            }else{
                /* if(a[now].val==s[i]){
                    p=now;
                    continue;
                } */
                bool flag=false;
                while(now!=0){
                    if(a[now].val==s[i]){
                        flag=true;
                        p=now;
                        break;
                    }
                    now=a[now].n_c;
                    if(a[now].val==s[i]){
                        flag=true;
                        p=now;
                        break;
                    }
                }
                if(!flag){
                    a[t].val=s[i];
                    a[now].n_c=t;
                    p=t,t++;
                }
            }
        }
    }
    cout<<t;
}