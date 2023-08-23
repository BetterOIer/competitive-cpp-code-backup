#include<iostream> 
using namespace std;
int na[201],nb[201];
int main(){
	int n,a,b, sa=0,sb=0,c, d;
	cin>>n>>a>>b;
	for(int i = 1;i<=a;i++){
		cin>>na[i];
	}
	for(int i = 1;i<=b;i++){
		cin>>nb[i];
	};
	for(int i = 1;i<=n;i++){
		c = i%a==0? a:i%a;
		d = i%b==0? b:i%b;
		if(na[c] == nb[d]){
			continue;
		}else if(na[c]==0){
			if(nb[d]==2||nb[d]==3){
				sa++;
			}else{
				sb++;
			}
		}else if(na[c]==1){
			if(nb[d]==0||nb[d]==3){
				sa++;
			}else{
				sb++;
			}
		}else if(na[c]==2){
			if(nb[d]==1||nb[d]==4){
				sa++;
			}else{
				sb++;
			}
		}else if(na[c]==3){
			if(nb[d]==2||nb[d]==4){
				sa++;
			}else{
				sb++;
			}
		}else if(na[c]==4){
			if(nb[d]==0||nb[d]==1){
				sa++;
			}else{
				sb++;
			}
		}
	}
	cout<<sa<<" "<<sb;
	return 0;
}