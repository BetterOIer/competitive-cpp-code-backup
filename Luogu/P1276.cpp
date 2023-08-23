#include<iostream>
using namespace std;
long long l,n;
bool opt;
long long a,b;
long long flag[10000+5];
long long ans_1,ans_2;

int main(){
    ios::sync_with_stdio(false);
    cin>>l>>n;
    for(int i=0;i<=l;++i)
    {
        flag[i]=1;
    }
    for(int i=0;i<n;++i)
    {
        cin>>opt>>a>>b;
        if(opt==0)
        {
            for(int j=a;j<=b;++j)
            {
                if(flag[j]==2)
                {
                    ans_2+=1;
                }
                flag[j]=0;
            }
        }
        else
        {
            for(int j=a;j<=b;++j)
            {
                if(flag[j]==0)
                {
                    flag[j]=2;
                }
            }
        }
    }
    for(int i=0;i<=l;++i)
    {
        if(flag[i]==2)
        {
            ans_1+=1;
        }
    }
    cout<<ans_1<<endl<<ans_2;
    return 0;
}
