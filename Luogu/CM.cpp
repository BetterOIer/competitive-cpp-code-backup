#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;
char re[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
string out=R"(//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<queue>
#include<stack>
#include <cctype>
#include <cmath>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <array>
#include <thread>
#include <unordered_map>
#include <unordered_set>
using namespace std;
const int mod = 1e9+7;
const int MAXN = 1e6+5;
const int INF = 2147483647;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
)";
string s,p;
int main(){
    cout<<"请输入文件保存地址： ";
    cin>>p;
    if(p=="l") p="A:\\Code\\C++\\luogu\\";
    else if(p=="t") p="A:\\Code\\C++\\test\\";
    else if(p=="n") p="A:\\Code\\C++\\nowcode\\";
    else if(p=="m") p="A:\\Code\\C++\\models\\";
    else if(p=="c"){
        p="A:\\Code\\C++\\Competition\\Competition";
        cout<<"请输入比赛号： ";
        cin>>s;
        string com="mkdir "+p+s;
        system(com.c_str());
        s+="\\";
        p+=s;
        int num;
        cout<<"请输入题目数量： ";
        cin>>num;
        cout<<"文件在 "<<p;
        for(int i = 1;i<=num;i++){
            string s2=p;
            s2+=re[i-1];
            s2+=".cpp";
            freopen(s2.c_str(),"w",stdout);
            cout<<out;
            fclose(stdout);
        }
        return 0;
    }
    cout<<"请输入文件名： ";
    cin>>s;
    s+=".cpp";
    p+=s;
    cout<<"文件在 "<<p;
    freopen(p.c_str(),"w",stdout);
    cout<<out;
    fclose(stdout);
    return 0;
}