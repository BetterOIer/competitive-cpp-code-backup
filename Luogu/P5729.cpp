#include <iostream>
using namespace std;
const int MAX = 30;
int sq[MAX][MAX][MAX] = {0};
int main()
{
	int a,b,c,n,ans = 0;
	cin>>a>>b>>c>>n;
	while(n--){
		int x1,y1,z1,x2,y2,z2;
		cin>>x1>>y1>>z1>>x2>>y2>>z2;
		for(int i = x1;i <= x2;i++){
			for(int j = y1;j <= y2;j++){
				for(int k = z1;k <= z2;k++){
                    if(!sq[i][j][k]){
                        sq[i][j][k] = 1;
                        ans++;
                    }
                }
            }
	    }
    }
    cout<<a*b*c-ans;
    return 0;
} 