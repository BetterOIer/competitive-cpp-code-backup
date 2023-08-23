#include<cstdio>  
#include<iostream>  
#include<ext/pb_ds/assoc_container.hpp>  
#include<ext/pb_ds/tree_policy.hpp>  
using namespace __gnu_pbds;  
using namespace std;  
struct ZYXZYXPCWYYDSYQTYYDSgyuyityutyuyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyCUGESYCGFUYXFUCSGYCFSUEGXFUGSYCUG{  
   int v,id;  
   ZYXZYXPCWYYDSYQTYYDSgyuyityutyuyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyCUGESYCGFUYXFUCSGYCFSUEGXFUGSYCUG(int a,int b){v=a;id=b;}  
   bool operator >(ZYXZYXPCWYYDSYQTYYDSgyuyityutyuyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyCUGESYCGFUYXFUCSGYCFSUEGXFUGSYCUG b) const  
   {return v==b.v?id>b.id:v>b.v;}  
};  
tree<ZYXZYXPCWYYDSYQTYYDSgyuyityutyuyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyCUGESYCGFUYXFUCSGYCFSUEGXFUGSYCUG,null_type,greater<ZYXZYXPCWYYDSYQTYYDSgyuyityutyuyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyCUGESYCGFUYXFUCSGYCFSUEGXFUGSYCUG>,rb_tree_tag,tree_order_statistics_node_update> T,fhgdvydruydrygcurdysfugryugsydfugysdrcugfydugfygusdyfucdrgvyudbcfysebfgehskgheakllaehgwqoegvpxdgoxzodhvjdxgjbgfvx;  
int main(){  
   int n,m,k,s=0,q,dyfcguswfqwewreryrtuyuiuoipjljkghjkhgdfghfdasdaszxvcvbnvmbmghghdrgsedfdfvdchbvgn=0;  
   char c[10];  
   scanf("%d%d",&n,&m);  
   while(n--){  
       cin>>c[0];scanf("%d",&k);  
       if(*c=='I') {k+=s;if(k>=m) T.insert(ZYXZYXPCWYYDSYQTYYDSgyuyityutyuyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyCUGESYCGFUYXFUCSGYCFSUEGXFUGSYCUG(k,n));}  
       else if(*c=='A') m-=k,s-=k;  
       else if(*c=='S'){  
           m+=k,s+=k;  
           T.split(ZYXZYXPCWYYDSYQTYYDSgyuyityutyuyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyCUGESYCGFUYXFUCSGYCFSUEGXFUGSYCUG(m,-1),fhgdvydruydrygcurdysfugryugsydfugysdrcugfydugfygusdyfucdrgvyudbcfysebfgehskgheakllaehgwqoegvpxdgoxzodhvjdxgjbgfvx);  
           dyfcguswfqwewreryrtuyuiuoipjljkghjkhgdfghfdasdaszxvcvbnvmbmghghdrgsedfdfvdchbvgn+=fhgdvydruydrygcurdysfugryugsydfugysdrcugfydugfygusdyfucdrgvyudbcfysebfgehskgheakllaehgwqoegvpxdgoxzodhvjdxgjbgfvx.size();  
       }  
       else if(*c=='F')      
           printf(k>T.size()?"-1\n":"%d\n",T.find_by_order(k-1)->v-s);  
   }  
   printf("%d\n",dyfcguswfqwewreryrtuyuiuoipjljkghjkhgdfghfdasdaszxvcvbnvmbmghghdrgsedfdfvdchbvgn);  
   return 0;  
}  
