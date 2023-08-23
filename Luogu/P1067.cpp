#include<iostream>
using namespace std;
int main(){
    int n,flag1 = 0;
    cin>>n;
    for(int i = 1;i<=n+1;i++){
        int x;
        cin>>x;
        if(x==0){
            continue;
        }else if(x>1){
        	if(flag1==0){
        		printf("%dx^%d",x,n+1-i);
			}else if(i==n+1){
				printf("+%d",x);
			}else{
				printf("+%dx^%d",x,n+1-i);
			}
        }else if(x<-1){
        	if(i==n+1){
				printf("%d",x);
			}
			else{
				printf("%dx^%d",x,n+1-i);
			}
		}
		else if(x==1){
			if(i==n+1){
				printf("+1");
			}else{
				printf("+x^%d",n+1-i);
			}
		}
		else if(x==-1){
			if(i==n+1){
				printf("-1");
			}else{
				printf("-x^%d",n+1-i);
			}
		}
		flag1 = 1;
    }
    return 0;
} 
