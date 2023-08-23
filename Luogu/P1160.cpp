#include<iostream>
struct node{
	int val;
	node *next; 
}; 
int a[100000],g;
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
void insertnode(node *insertnode,int data){
	node *newnode=creatnode(data);
	newnode->next=insertnode->next;
	insertnode->next=newnode;
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
		printf("%d ", nodenext->val);
		nodenext = nodenext->next;
	}
    printf("\n");
}
using namespace std;
int main(){
    node *list=creathead();
    int n,k,opt;
    cin>>n;
    insertnode(list,1);
    for(int i = 2;i<=n;i++){
        cin>>k>>opt;
        node *list1=list;
        while(list1->next->val!=k){
            list1=list1->next;
        }
        if(opt)insertnode(list1->next,i);
        else insertnode(list1,i);
    }
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>k;
        int flag = 0;
        for(int w = 0;w<=g-1;w++){
            if(a[w]==k){
                flag=1;
                break;
            }
        }
        if(!flag){
            a[g++]=k;
            node *list1=list,*list2=list;
            while(list1->next->val!=k)list1=list1->next;
            removenode(list1,list1->next);
        }
    }
    printnode(list);
    return 0;
}