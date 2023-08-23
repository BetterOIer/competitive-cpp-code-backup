#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int a[101],n,d=0,t[10001]={0};
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int x=1;x<=n;x++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
			if(a[x]==a[i]||a[x]==a[j]||a[j]==a[i])
                continue;
			else{
				if(a[x]==a[i]+a[j])
                    t[a[x]]=1;
			    }   
		    }
	    }
	}
	for(int i=1;i<=n;i++){
		if(t[a[i]]==1)d++;
	}
	printf("%d",d);
	return 0;
}

