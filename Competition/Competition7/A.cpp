#include <bits/stdc++.h>
#define int long long
using namespace std;
int arr[100005];
int val[100005];
int search(int key,int stop,int start){
    for(int i=start;i<stop;i++){
        if(arr[i]==key){
            return i;
        }
    }
    return -1;
}
signed main(){
	int n;
	cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    val[0]=1;
    int p=0,con=0;
    for(int i=1;i<n;i++){
        int x=search(arr[i],i,p);
        if(x==-1){
            val[i]=val[i-1]+1;
        }else{
            val[i]=val[i-1]-(x-p);
            p=x+1;
        }
    }
    for(int i=0;i<n;i++){
        con+=val[i];
    }
    cout << con << endl;
	return 0;
}