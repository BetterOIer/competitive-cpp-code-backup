/*=================================================
* Le vent se lève, il faut tenter de vivre! 
* Author: Better_OIer Zyx
* 
* Blog: betteroier.site:1000 
* FileStation: betteroier.site:1001
* OnlineJudge: betteroier.site:8888
=================================================*/
#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int main(){
    srand((unsigned int)time(NULL));
    string s[100]={"001.in","002.in","003.in","004.in","005.in","006.in","007.in","008.in","009.in","010.in","011.in","012.in","013.in","014.in","015.in","016.in","017.in","018.in","019.in","020.in","021.in","022.in","023.in","024.in","025.in","026.in","027.in","028.in","029.in","030.in","031.in","032.in","033.in","034.in","035.in","036.in","037.in","038.in","039.in","040.in","041.in","042.in","043.in","044.in","045.in","046.in","047.in","048.in","049.in","050.in","051.in","052.in","053.in","054.in","055.in","056.in","057.in","058.in","059.in","060.in","061.in","062.in","063.in","064.in","065.in","066.in","067.in","068.in","069.in","070.in","071.in","072.in","073.in","074.in","075.in","076.in","077.in","078.in","079.in","080.in","081.in","082.in","083.in","084.in","085.in","086.in","087.in","088.in","089.in","090.in","091.in","092.in","093.in","094.in","095.in","096.in","097.in","098.in","099.in","100.in"};
    for(int i = 0;i<=99;i++){
        freopen(s[i].c_str(),"w",stdout);
        int n=rand()*10;
        cout<<n<<endl;
        for(int i = 1;i<=n;i++){
            cout<<1LL*rand()*1000<<" ";
        }
    }
}