#include<iostream>
#include<cstring>
using namespace std;
int T,q,n,t[3000005][65],cnt[3000005],siza;
char s[3000005];
int getnum(char x){
    if(x>='A'&&x<='Z')
        return x-'A';
    else if(x>='a'&&x<='z')
        return x-'a'+26;
    else
        return x-'0'+52;
} 
void insert(char str[]){
    int p=0,length=strlen(str);
    for(int i=0;i<length;i++){
        int c=getnum(str[i]);
        if(!t[p][c])
            t[p][c]=++siza;
        p=t[p][c];
        cnt[p]++;
    }
}
int find(char str[]){
    int p=0,length=strlen(str);
    for(int i=0;i<length;i++){
        int c=getnum(str[i]);
        if(!t[p][c])
            return 0;
        p=t[p][c];
    }
    return cnt[p];
}
int main(){
    scanf("%d",&T);
    while(T--){
        for(int i=0;i<=siza;i++){
            for(int j=0;j<=122;j++){
                t[i][j]=0;
            }
        }
        for(int i=0;i<=siza;i++){
            cnt[i]=0;
        }
        siza=0;
        scanf("%d%d",&n,&q);
        for(int i=1;i<=n;i++){
            scanf("%s",s);
            insert(s);
        }
        for(int i=1;i<=q;i++){
            scanf("%s",s);
            printf("%d\n",find(s));
        }
    }
    return 0;
}
