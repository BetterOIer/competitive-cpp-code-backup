#include<iostream>
//#include<cstdio>
//#include<algorithm>
//#include<cstring>
#include<string>
//#include<cstdin>
//#include<cmath>
//#include<stdlib>
#include<queue>
//#include<vector>
//#include<stack>
using namespace std;
//int a[];
queue <int> Q;
queue <int> Q1;
int ans=0;
void data(int x){
    while(!Q.empty()){
        int a = Q.front()-1;
        Q.pop();
        ans+=x;
        Q1.push(a);
    }
    while(!Q1.empty()){
        int a = Q1.front();
        Q1.pop();
        if(a>0) Q.push(a);
    }
}
int main(){
    //freopen("P.in","r",stdin);
    //freopen("P.out","w",stdout);
    int js=1,cs=1, k=0,flag1=0,flag2=0;
    string s;
    getline(cin,s);
    for(int i = 0;i<=s.length()-1;i++){
        if(js<=10){
            if(s[i]=='/'){
                if(cs==1){
                    data(10);
                    ans+=10;
                    Q.push(2);
                    cs++;
                    flag2=1;
                }
                else if(cs==2&&flag2==0){
                    data(10-k);
                    ans+=10;
                    Q.push(1);
                    k=0;
                }
            if(js==10)flag1=1;
            }else if(s[i]==' '){
                js++;
                cs=1;
                flag2=0;
            }else{
                if(cs==2&&flag2==0){
                    int n = s[i]-'0';
                    if(n+k==10){
                        data(n);
                        ans+=10;
                        Q.push(1);
                        k=0;
                    }else{
                        ans+=n+k;
                        data(n);
                        k=0;
                    }
                }else if(cs==1){
                    k = s[i]-'0';
                    data(k);
                    cs++;
                }
            }
        }
        else if(flag1==1){
            if(s[i]=='/'){
                if(cs==1){
                    data(10);
                    cs++;
                    
                }
                else if(cs==2){
                    data(10-k);
                    k=0;
                }
            }else{
                if(cs==2){
                    int n = s[i]-'0';
                    if(n+k==10)
                        data(n);
                        k=0;
                }else if(cs==1){
                    k = s[i]-'0';
                    data(k);
                    cs++;
                }
            }
        }
    }
    cout<<ans;
 	//fclose(stdin);
    //fclose(stdout);
    return 0;
}
