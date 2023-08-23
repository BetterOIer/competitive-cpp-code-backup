#include<iostream>
using namespace std;
int n,m,p;
struct node{
    string n;
    int pre;
    int aft;
}a[21];
void output(int i,int q,int flag){
    if(flag){
        for(int j = 1;j<=q;j++){
            i=a[i].pre;
        }
        cout<<a[i].n<<endl;
    }else{
        for(int j = 1;j<=q;j++) i=a[i].aft;
        cout<<a[i].n<<endl;
    }
}
int main(){
    cin>>n>>m>>p;
    cin>>a[1].n;
    a[1].aft=2;
    a[1].pre=n;
    for(int i = 2;i<=n-1;i++){
        cin>>a[i].n;
        a[i].aft=i+1;
        a[i].pre=i-1;
    }
    cin>>a[n].n;
    a[n].aft=1;
    a[n].pre=n-1;
    for(int j = 1;j<=m;j++){
        string s1,s2;
        int p11,p12,p21,p22,po1,po2;
        int flag;
        cin>>s1>>s2;
        for(int i = 1;i<=n;i++){
            if(a[i].n==s1){
                p11 = a[i].pre;
                p12 = a[i].aft;
                po1 = i;
            }else if(a[i].n==s2){
                p21 = a[i].pre;
                p22 = a[i].aft;
                po2 = i;
            }
        }
        cin>>flag;
        if(!flag){
            a[po1].aft=p22;
            a[po1].pre=po2;
            a[po2].aft=po1;
            a[p12].pre=p11;
            a[p11].aft=p12;
            a[p22].pre=po1;
        }else{
            a[po1].aft=po2;
            a[po1].pre=p21;
            a[p12].pre=p11;
            a[p11].aft=p12;
            a[p21].aft=po1;
            a[po2].pre=po1;
        }
    }
    for(int i = 1;i<=p;i++){
        string s;
        int flag;
        int q;
        cin>>s>>flag>>q;
        for(int i = 1;i<=n;i++){
            if(a[i].n==s){
                output(i,q,flag);
                break;
            }
        }
    }
    return 0;
}