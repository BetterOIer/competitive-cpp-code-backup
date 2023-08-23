#include<iostream>
using namespace std;
int main(){
    int n, ans = 0;
    cin>>n;
    for(int i=1;i<=n;i++){
        int a=0, b=0, c=0;
        float aa, bb, cc;
        cin>>a>>b>>c;
        aa = 1.0*a/(a+b+c)*360;
        bb = 1.0*b/(a+b+c)*360;
        cc = 1.0*c/(a+b+c)*360;
        if(a!=b&&b!=c&&c!=a){
            ans+= ((aa<360&&aa>180)||(aa>0&&aa<180))? 2:(aa==180? 1:0);
            ans+= ((bb<360&&bb>180)||(bb>0&&bb<180))? 2:(bb==180? 1:0);
            ans+= ((cc<360&&cc>180)||(cc>0&&cc<180))? 2:(cc==180? 1:0);
            ans/=2;
        }
        else if(a!=0&&b!=0&&c!=0){
            ans = 2;
        }else if((a==0&&b==0&&c!=0)||(b==0&&c==0&&a!=0)||(a==0&&c==0&&a!=0)){
            ans = 0;
        }else{
            ans = 1;
        }
        cout<<ans<<endl;
        ans = 0;
    }
    return 0;
} 