#include<iostream>
//#include<cstdio>
//#include<algorithm>
//#include<cstring>
#include<string>
//#include<cstdin>
#include<cmath>
//#include<stdlib>
using namespace std;
//int a[];
int main(){
    //freopen("P.in","r",stdin);
    //freopen("P.out","w",stdout);
    int n,a1=0,a2=0;
    cin>>n;
    string s1,s2;
    cin>>s1>>s2;
    for(int i = 1;i<=n;i++){
        if(s1[i-1]=='1'){
            a1++;
        }
    }
    for(int i = 1;i<=n;i++){
        if(s2[i-1]=='1'){
            a2++;
        }
    }
    cout<<abs(a1-a2);
 	//fclose(stdin);
    //fclose(stdout);
    return 0;
} 