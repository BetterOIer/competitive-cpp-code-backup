#include<iostream>
using namespace std;
const int inf=0x3f3f3f3f;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
char opt[104];
int num[104];
int dpu[105][105], dpd[105][105];
int max(int x,int y){return (x>y)?(x):(y);}
int min(int x,int y){return (x<y)?(x):(y);}
int main(){
    int n=read(),nu;
    char op;
    for(int i = 1;i<=n;i++){
        cin>>op;
        nu=read();
        opt[i]=opt[i+n]=op;
        num[i]=num[i+n]=nu;
    }
    for(int i=1;i<=(n<<1);i++){
        for(int j=1;j<=(n<<1);j++){
            dpu[i][j]=-inf,dpd[i][j]=inf;
        }
    }
    for(int i=1;i<=(n<<1);i++)dpu[i][i]=dpd[i][i]=num[i];
    for(int len = 2;len<=n;len++){
        for(int l = 1;l<=n+n+1-len;l++){
            int r=l+len-1;
            for(int k = l;k<r;k++){
                if(opt[k+1]=='x'){
                    dpu[l][r]=max(dpu[l][r],max(dpu[l][k]*dpu[k+1][r],max(dpd[l][k]*dpd[k+1][r],max(dpu[l][k]*dpd[k+1][r],dpd[l][k]*dpu[k+1][r]))));
                    dpd[l][r]=min(dpd[l][r],min(dpu[l][k]*dpu[k+1][r],min(dpd[l][k]*dpd[k+1][r],min(dpu[l][k]*dpd[k+1][r],dpd[l][k]*dpu[k+1][r]))));
                }
                else if(opt[k+1]=='t'){
                    dpu[l][r]=max(dpu[l][r],dpu[l][k]+dpu[k+1][r]);
                    dpd[l][r]=min(dpd[l][r],dpd[l][k]+dpd[k+1][r]);
                }
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)ans=max(ans,dpu[i][i+n-1]);printf("%d\n",ans);
    for(int i=1;i<=n;i++)if(dpu[i][i+n-1]==ans)printf("%d ",i);
    return 0;
}