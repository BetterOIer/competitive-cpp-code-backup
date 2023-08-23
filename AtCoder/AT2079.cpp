#include<iostream>
//#include<cstdio>
//#include<algorithm>
//#include<cstring>
//#include<string>
//#include<cstdin>
//#include<cmath>
//#include<stdlib>
using namespace std;
int main(){
    //freopen("P.in","r",stdin);
    //freopen("P.out","w",stdout);
    string s1,s2;
    cin>>s1;
    int sum = 0;
    s2 = "CODEFESTIVAL2016";
    for(int i = 0;i<=15;i++){
        if(s1[i]!=s2[i]){
            sum++;
        }
    }
    cout<<sum;
 	//fclose(stdin);
    //fclose(stdout);
    return 0;
} 