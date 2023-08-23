#include<iostream>
using namespace std;
int player[100005],n,w;
int score[605];
int main(){
    scanf("%d%d",&n,&w);
    for(int i = 1;i<=n;i++){
        scanf("%d",player+i);
        score[player[i]]++;
        int p=i*w/100,ans = 1,cnt = 0;;
        for (int j = 600; ~j; --j){
            if (score[j]) {
                if ((cnt += score[j]) >= p){ 
                    ans = j;
                    break; 
                }
            }
        }
        printf("%d ",ans);
    }
}