#include<iostream>
//#include<cstdio>
//#include<algorithm>
//#include<cstring>
//#include<string>
//#include<cstdin>
//#include<cmath>
//#include<stdlib>
//#include<queue>
//#include<vector>
//#include<stack>
using namespace std;
struct node{
	char val;
	node *next; 
}; 
node *creathead(){
	node *headnode=new node;
	headnode->next=NULL;
	return headnode;
}
node *h_creatnode(char data){
	node *newnode=new node;
	newnode->next=NULL;
	newnode->val=data;
	return newnode;
}
node *t_creatnode(char data){
	node *newnode=new node;
	newnode->next=NULL;
	newnode->val=data;
	return newnode;
}
void h_insertnode(node *headnode,char data){
	node *newnode=creatnode(data);
	newnode->next=headnode->next;
	headnode->next=newnode;
}
void t_insertnode(node *headnode,char data){
	node *newnode=creatnode(data);
	newnode->next=headnode->next;
	headnode->next=newnode;
}
void fr_ta_connectnode(node *headnode,node *tailnode){
    tailnode->next=headnode->next;
}
int removenode(node *fr_rmnode,node *rmnode){
	fr_rmnode->next=rmnode->next;
    return rmnode->val;
}
void printnode(node *headnode){
	node *nodenext = headnode->next;
	while(nodenext!=NULL){
		printf("%c", nodenext->val);
		nodenext = nodenext->next;
	}
}
int main(){
    //freopen("P.in","r",stdin);
    //freopen("P.out","w",stdout);
    string s;
    node *list=creathead(); 
    while(cin>>s){
        for(int i = 0;i<=s.length()-1;i++){
            char c = s[i];
            if(c!='['&&c!=']'){
                h_insertnode(list, c);
            }else{

            }
        }
    }
 	//fclose(stdin);
    //fclose(stdout);
    return 0;
}
