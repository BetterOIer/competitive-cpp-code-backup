#include<iostream>
using namespace std;
struct node{
    char val;
    int fit_c;
}tree[25];
struct nodechild{
    int next;
    int child;
}child[25];
int nt=0,cnt=0;
void create_child(char val){
    ++cnt,++nt;
    tree[nt].val=val;
    tree[nt].fit_c=0;
    child[cnt].child=nt;
}
int main(){
    string s;
    while(cin>>s){
        int fpo=0;//父亲节点ROOT
        int cpo=tree[0].fit_c;//ROOT下第一个孩子在child中的位置
        int po=child[tree[0].fit_c].child;//ROOT下第一个孩子在tree中的位置
        for(int i = 0;i<=s.length()-1;i++){
            bool flag=true;
            while(tree[po].val!=s[i]){
                if(child[cpo].next==0){
                    flag=false;
                    break;
                }
                po=child[child[cpo].next].child;//ROOT下下一个孩子在tree中的位置
                cpo=child[cpo].next;//ROOT下下一个孩子在child中的位置
            }
            if(!flag){
                create_child(s[i]);
                if(cpo==0){
                    tree[fpo].fit_c=cnt;
                }
                /* cpo=child[cpo].next;//ROOT下下一个孩子在child中的位置
                po=child[child[cpo].next].child;//ROOT下下一个孩子在tree中的位置 */
            }else{
                cpo=tree[po].fit_c;
                po=child[cpo].child;
                fpo++;
            }
        }
    }
    cout<<cnt++;
}