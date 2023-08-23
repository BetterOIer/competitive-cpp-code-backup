#include<iostream>
#include<cmath>
using namespace std;
int w=0,l=0;
int comp[100000];
int main(){
	char wl;
	for(int i=1;cin>>wl&&wl!='E';i++){
		if(wl=='W') comp[i]=1;
		else comp[i]=2;
	}
	for(int i=1;i>0;i++){
		if(comp[i]==1) 
			w++;
		if(comp[i]==2) 
			l++;
		if(comp[i]==0){
			cout<<w<<':'<<l<<endl;
			break;
		}
		if(abs(w-l)>=2){
			if(w>=11||l>=11){
				cout<<w<<':'<<l<<endl;
				w=0,l=0;
			}
		}
	}
	w=0;
	l=0;
	printf("\n");
	for(int i=1;i>0;i++){
		if(comp[i]==1) 
			w++;
		if(comp[i]==2) 
			l++;
		if(comp[i]==0){
			cout<<w<<':'<<l<<endl;
			break;
		}
		if(abs(w-l)>=2){
			if(w>=21||l>=21){
				cout<<w<<':'<<l<<endl;
				w=0,l=0;
			}
		}
	}
	w=0;
	l=0;
	return 0;
} 
