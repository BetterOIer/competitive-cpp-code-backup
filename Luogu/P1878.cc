#include<cstdio>
#include<iostream>
using namespace std;
const int maxn = 200010;
struct node{
    int value,l,r;
    friend bool operator > (node aa,node bb){return aa.value > bb.value || (aa.value == bb.value && aa.l > bb.l);} 
    
}heap[maxn],tmp;
void swap(node &a,node &b){tmp = a,a = b,b = tmp;}
int abs(int value){return value < 0?-value:value;}

int n,a[maxn],heap_size,tot,tl[maxn],tr[maxn]; 
bool b[maxn],f[maxn];
void put(int value,int l,int r){
    int now = ++heap_size,next;
    heap[heap_size].value = value,heap[heap_size].l = l,heap[heap_size].r = r;
    while(now > 1){
        next = now >> 1;
        if(heap[now] > heap[next]) return;
        swap(heap[now],heap[next]);
        now = next;
    } 
}
void get(){
    int now = 1,next;
    heap[1].value = heap[heap_size].value,heap[1].l = heap[heap_size].l,heap[1].r = heap[heap_size--].r;
    while(now << 1 <= heap_size){
        next = now << 1;
        if(next < heap_size && heap[next] > heap[next + 1]) next++;
        if(heap[next] > heap[now]) return;
        swap(heap[now],heap[next]);
        now = next;
    }
}

int main(){
    scanf("%d\n",&n);
    for(int i = 0;i < n;i++){
        char ch = getchar();
        f[i] = ch == 'B';
    }
    for(int i = 0;i < n;i++){
        scanf("%d",&a[i]);
        int j = i - 1;
        if(i && f[i] ^ f[j]) put(abs(a[i] - a[j]),j,i);
        
    }
    while(heap_size){
        int l = heap[1].l,r = heap[1].r,ll,rr;
        b[l] = b[r] = true;
        tl[++tot] = l + 1,tr[tot] = r + 1;
        do{
            get();
            if(!heap_size) break;
            ll = heap[1].l,rr = heap[1].r;
        }while(b[ll] || b[rr]);
        
        while(l >= 0 && b[l]) l--;
        while(r < n && b[r]) r++;
        
        if(l >= 0 && r < n && f[l] ^ f[r]) put(abs(a[l] - a[r]),l,r);
    }
    cout<<tot;
    for(int i = 1;i <= tot;i++) cout<<endl<<tl[i]<<" "<<tr[i];
    
    return 0;
}