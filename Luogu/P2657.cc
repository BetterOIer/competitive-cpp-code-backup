#include<bits/stdc++.h>
using namespace std;
int L,R;
namespace right{
    long long dp[15][15],ans;
    int a[15],len;
    long long dfs(int pos,int pre,int st,int limit)
    {
        if(pos>len) return 1;
        if(!limit&&dp[pos][pre]!=-1) return dp[pos][pre];
        long long ret=0;
        int res=limit?a[len-pos+1]:9;
        for(int i=0;i<=res;i++)
        {
            if(abs(i-pre)<2) continue;
            if(st&&i==0) ret+=dfs(pos+1,-2,1,limit&&i==res);
            else ret+=dfs(pos+1,i,0,limit&&i==res);
        }
        if(!limit&&!st) dp[pos][pre]=ret;
        return ret;
    }
    void part(long long x)
    {
        len=0;
        while(x) a[++len]=x%10,x/=10;
        memset(dp,-1,sizeof dp);
        ans=dfs(1,-2,1,1);
    }
    long long main(){
        part(L-1);long long minn=ans;
        part(R);  long long maxx=ans;
        return maxx-minn;
    }
}
namespace my{
    long long len=0;
    long long f[10][10][3][3];
    long long a[10];
    inline long long dfs(long long pos,long long pre,long long lead,long long limit){
        if(pos>len)return 1;
        if(f[pos][pre][lead][limit])return f[pos][pre][lead][limit];
        long long cnt=0,high=limit? a[len-pos+1]:9;
        for(long long i = 0;i<=high;i++){
            if(abs(i-pre)<2)continue;
            if(lead&&(!i))cnt+=dfs(pos+1,-2,1,limit&&(i==high));
            else cnt+=dfs(pos+1,i,0,limit&&(i==high));
        }
        if(!limit&&!lead)f[pos][pre][lead][limit]=cnt;
        return cnt;
    }
    inline long long divid(long long x){
        len=0;
        memset(f,0,sizeof(f));
        while(x){
            len++;
            a[len]=x%10;
            x/=10;
        }
        return dfs(1,-2,1,1);
    }
    long long main(){
        return divid(R)-divid(L-1);
    }
}
int main(){
    L=rand()%10000000+2;
    R=rand()%L;
    int ans=10;
    while(ans){
        if(my::main()!=right::main()){
            ans--;
            cout<<L<<" "<<R<<endl<<"My:"<<my::main()<<" Right:"<<right::main()<<endl<<endl;
        }
    }
}