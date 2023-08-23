#include<iostream>
using namespace std;
struct node{
	int val;
	node *next; 
}; 
node *creathead(){
	node *headnode=new node;
	headnode->next=NULL;
	return headnode;
}
node *creatnode(int data){
	node *newnode=new node;
	newnode->next=NULL;
	newnode->val=data;
	return newnode;
}
void insertnode(node *headnode,int data){
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
		printf("%d", nodenext->val);
		nodenext = nodenext->next;
	}
}
int main(){
    int n,m;
    cin>>n>>m;
    node *list=creathead(); 
    node *list1=list;
	for(int i = n;i>=1;i--){
		insertnode(list, i);
        if(n==i)list1=list1->next;
	}
    fr_ta_connectnode(list,list1);
    int k = 0;
    node *cz1 = list,*cz2 = list;
    while(k<n){
        for(int i = 1;i<=m-1;i++){
            cz1=cz1->next;
        }
        for(int i = 1;i<=m;i++){
            cz2=cz2->next;
        }
        cout<<removenode(cz1,cz2)<<" ";
        k++;
    }
    return 0;
}
