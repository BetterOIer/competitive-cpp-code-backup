#include<iostream>
using namespace std;
struct node{
    int data;
    char sex;
}a[2000005];
struct Qnode{
    int cha;
    int first;
}combine[2000005];
int heap[4000005],k=0,k1=0,k2=1;
int ans[4000005];
string s;
void join(int x){
    heap[++k]=x;
    int po=k;
    while(combine[heap[po]].cha<combine[heap[po/2]].cha){
        swap(heap[po],heap[po/2]);
        po/=2;
    }
}
void del1(int x){
    for(int i = 1;i<=k;i++){
        if(combine[heap[i]].first==x){
            int po=i,next;
            heap[po]=heap[k--];
            while(po*2<=k){
                next=po*2;
                if(next<k&&combine[heap[next+1]].cha<combine[heap[next]].cha)next++;
                if(combine[heap[po]].cha<=combine[heap[next]].cha) break;
                swap(heap[po],heap[next]);
                po=next;
            }
            break;
        }
    }
}
int del(){
    if(!k) return 0;
    int res=heap[1],po,next;
    po=1;
    heap[1]=heap[k--];
    while(po*2<=k){
        next=po*2;
        if(next<k&&combine[heap[next+1]].cha<combine[heap[next]].cha)next++;
        if(combine[heap[po]].cha<=combine[heap[next]].cha) break;
        swap(heap[po],heap[next]);
        po=next;
    }
    ans[k2++]=res;
    if(k)del1(combine[heap[1]].first+1);
    return res;
}
int main(){
    int n;
    cin>>n>>s;
    for(int i = 0;i<n;i++) a[i+1].sex=s[i];
    for(int i = 1;i<=n;i++) cin>>a[i].data;
    for(int i = 1;i<n;i++){
        if(a[i].sex+a[i+1].sex=='B'+'G'){
            combine[++k1].cha=abs(a[i].data-a[i+1].data);
            combine[k1].first=i;
            join(k1);
        }
    }
    while(del());
    cout<<k2-1<<endl;
    for(int i = 1;i<=k2-1;i++){
        cout<<ans[i]<<" "<<ans[i]+1<<endl;
    }
}