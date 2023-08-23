#include<iostream>
//#include<cstdio>
//#include<algorithm>
//#include<cstring>
#include<string>
//#include<cstdin>
//#include<cmath>
//#include<stdlib>
//#include<queue>
//#include<vector>
//#include<stack>
using namespace std;
//int a[];
int find_num(string &s,int po,int opt){//1后-1前
    int po1 = po,k=0;
    while(s[po+opt]>='0'&&s[po+opt]=<'9'){
        po=po+opt;
    }
    if(opt==1){
        for(int i = po1;i<=po;i++){
            k=k*10+s[i]-'0';
        }
    }else{
        for(int i = po;i<=po1;i++){
            k=k*10+s[i]-'0';
        }
    }
    return k;
}
string data_deal(string s){
    for(int i = 0;i<=s.length()-1;i++){
        if(s[i]=='*'){
            int k = find_num(s,i,-1)*find_num(s,i,+1);
        }else if(s[i]=='*'){
            int k = find_num(s,i,-1)/find_num(s,i,+1);
        }
    }
}
void string_deal(string s){
    for(int i = 0;i<=s.length()-1;i++){
        if(s[i]=='('){
            string s1 = s.substr(i+1,s.length()-i-1);
            string_deal(s1);
        }else if(s[i]==')'){
            string s2 = s.substr(0,s[i]==')'-1);
            data_deal(s2);
        }

    }
}
int main(){
    //freopen("P.in","r",stdin);
    //freopen("P.out","w",stdout);
    string s;
    cin>>s;

 	//fclose(stdin);
    //fclose(stdout);
    return 0;
}