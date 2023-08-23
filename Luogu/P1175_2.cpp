#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
char dasz[100010],s2[100010],s3[100010],a[100010];
long long  top2,topdasz,p;
long long  js[100010],topjs;
int lev(char n)
{
	if(n=='+'||n=='-') return 1;
	if(n=='*'||n=='/') return 2;
	if(n=='^') return 3;
	return 0;
}
void print()
{
	for(int i=1;i<=topjs;i++)cout<<js[i]<<" ";
	for(int i=p+1;i<=top2;i++)
	{
		cout<<s2[i];
		if(i!=top2)
		cout<<" ";
	}
	if(p!=top2)
	cout<<endl;
}
int main()
{
	long long  n; 
	scanf("%s",a);
	n=strlen(a);//不能用gets（）
	for(int i=0;i<n;i++)
	{
		if(a[i]>='0'&&a[i]<='9')s2[++top2]=a[i];
		else
		{
			if(a[i]=='(')
			{
				dasz[++topdasz]=a[i];
				continue;
			}
			if(dasz[topdasz]=='('||topdasz==0)
			{
				dasz[++topdasz]=a[i];
				continue;
			}
			if(lev(dasz[topdasz])>=lev(a[i])&&a[i]!=')')
			{
				s2[++top2]=dasz[topdasz--];
				while(lev(dasz[topdasz])>=lev(a[i]))s2[++top2]=dasz[topdasz--];
				dasz[++topdasz]=a[i];
				continue;
			}
			if(lev(dasz[topdasz])<lev(a[i])&&a[i]!=')')
			{
				dasz[++topdasz]=a[i];
				continue;
			}
			if(a[i]==')')
			{
				while(dasz[topdasz]!='(')s2[++top2]=dasz[topdasz--];
				--topdasz;
				continue;
			}
		}
	}
	while(topdasz>0)s2[++top2]=dasz[topdasz--];           //到此为止前缀表达式已经转成了后缀表达式，并存在了s2数组中
	for(int i=1;i<=top2;i++)cout<<s2[i]<<" ";
	cout<<endl;//先输出一遍
	for(int  i=1;i<=top2;i++)
	{	p=i;
		if(s2[i]>='0'&&s2[i]<='9')js[++topjs]=s2[i]-'0';
		else
		{
            long long  y=js[topjs];
			long long  x=js[--topjs];
            long long ans;
			if(s2[i]=='+')ans=x+y;
			if(s2[i]=='-')ans=x-y;
			if(s2[i]=='*')ans=x*y;
			if(s2[i]=='/')ans=x/y;
			if(s2[i]=='^')ans=pow(x,y);
            js[topjs]=ans;
			print();
		}
	}
	return 0;
}