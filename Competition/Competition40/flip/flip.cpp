#include<iostream>
#include<cstring>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int a[10005],tmp[10005],cnt=0,CNT=0,cpa[10005], L, R;
struct node{
    int L;
    int R;
    int cnt;
};
void merge_sort(int l, int r) {
	if (l >= r) return ;
	int mid = (l + r) >> 1;
	merge_sort(l, mid);
	merge_sort(mid + 1, r);
	int pl = l, pr = mid + 1, tmpp = 0;
	while(pl <= mid && pr <= r){
		if (cpa[pl] <= cpa[pr]) tmp[tmpp++] = cpa[pl++];
		else tmp[tmpp++] = cpa[pr++], cnt += mid - pl + 1;
	}
	while(pl <= mid) tmp[tmpp++] = cpa[pl++];
	while(pr <= r) tmp[tmpp++] = cpa[pr++];
	for (int i = 0; i < tmpp; i++) cpa[i + l] = tmp[i];
}
int main(){
    freopen("flip.in","r",stdin);
    freopen("flip.out","w",stdout);
    int n=read();
    for(int i = 1;i<=n;i++) a[i]=read();
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=i;j++){
            memcpy(cpa,a,sizeof a);
            int mi=(j+i)>>1;
            for(int w = j;w<=mi;w++){
                int cn=cpa[w];
                cpa[w]=cpa[i+j-w];
                cpa[i+j-w]=cn;
            }
            cnt=0;
            memset(tmp,0,n+1);
            merge_sort(1,n);
            if(cnt>CNT){
                CNT=cnt;
                L=j;
                R=i;
            }
        }
    }
    cout<<CNT<<endl<<L<<" "<<R;
    fclose(stdin);
    fclose(stdout);
    return 0;
}