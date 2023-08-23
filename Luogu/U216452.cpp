#include<iostream>
#include<string>
using namespace std;
string s = "hello";
struct zm{
    string s;
}a[5][4];
int main(){
    freopen("U216452.in","r",stdin);
    freopen("U216452.out","w",stdout);
    for(int j = 0;j<=4;j++){
        int g=0;
        for(int i = 0;i<=1;i++){
            for(int k = 0;k<=32;k+=32){
                if(i==0){
                    char c=s[j]-k;
                    a[j][g++].s+=c;
                }else{
                    int d =s[j]-k;
                    if(d<100){
                        char c = d/10+'0';
                        char e=d%10+'0';
                        a[j][g].s+=c;
                        a[j][g++].s+=e;
                    }else{
                        char c = d/100+'0';
                        a[j][g].s+=c;
                        c = d%100/10+'0';
                        a[j][g].s+=c;
                        c = d%10+'0';
                        a[j][g++].s+=c;
                    }
                }
            }
        }
    }
    for(int i1 = 0;i1<=3;i1++)for(int i2 = 0;i2<=3;i2++)for(int i3 = 0;i3<=3;i3++)for(int i4 = 0;i4<=3;i4++)for(int i5 = 0;i5<=3;i5++)/* for(int i6 = 0;i6<=3;i6++)for(int i7 = 0;i7<=3;i7++)for(int i8 = 0;i8<=3;i8++)for(int i9 = 0;i9<=3;i9++)for(int i0 = 0;i0<=3;i0++) */cout<<a[0][i1].s<<a[1][i2].s<<a[2][i3].s<<a[3][i4].s<<a[4][i5].s/* <<a[5][i6].s<<a[6][i7].s<<a[7][i8].s<<a[8][i9].s<<a[9][i0].s */<<endl;
 	fclose(stdin);
    fclose(stdout);
    return 0;
}
