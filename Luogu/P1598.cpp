#include<iostream>
using namespace std;
int a[27];
int sc[401][52];//1_400;1_51
int main(){
    for(int i = 1;i<=4;i++){
        string s;
        getline(cin,s);
        for(int w = 1;w<=26;w++){
            char b = w+64;
            while((int)s.find(b)!=-1){
                s[s.find(b)]='0';
                a[w]++;
            }
        }
    }
    int js=1, hsmax = 400;
    for(int i = 1;i<=51;i+=2){
        int hangshu = 400;
        while(a[js]!=0){
            sc[hangshu][i]=1;
            hangshu--;
            a[js]--;
        }
        hsmax = hangshu>hsmax? hsmax:hangshu;
        js++;
    }
    for(int i = hsmax+1;i<=400;i++){
        for(int w = 1;w<=51;w++){
            if(sc[i][w]==1){
                cout<<"*";
            }else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
    cout<<"A "<<"B "<<"C "<<"D "<<"E "<<"F "<<"G "<<"H "<<"I "<<"J "<<"K "<<"L "<<"M "<<"N "<<"O "<<"P "<<"Q "<<"R "<<"S "<<"T "<<"U "<<"V "<<"W "<<"X "<<"Y "<<"Z";
    return 0;
}