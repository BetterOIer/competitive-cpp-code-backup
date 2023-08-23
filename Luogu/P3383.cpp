#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
bool v[100000010];
int Prime[6000010], cnt = 0;
void prim(int n)
{
	memset(v, 1, sizeof(v));
	v[1] = 0;
	for(int i = 2; i <= n; i++){
		if(v[i]) Prime[++cnt] = i; 
		for(int j = 1; j <= cnt && i*Prime[j] <= n; j++) {
			v[i*Prime[j]] = 0;
			if(i % Prime[j] == 0) break; 
		}
	}
}
int main(){
	int n, q;
	scanf("%d %d", &n, &q);
	prim(n);
	while (q--){
		int k;
		scanf("%d", &k);
		printf("%d\n", Prime[k]);
	}
	return 0;
}

