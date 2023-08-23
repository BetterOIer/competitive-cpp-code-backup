/*=================================================
* Le vent se lève, il faut tenter de vivre! 
* Author: Better_OIer Zyx
今人不见古时月，今月曾经照古人。 --把酒问月·故人贾淳令予问之
* Blog: betteroier.site:1000 
* FileStation: betteroier.site:1001
* OnlineJudge: betteroier.site:8888
=================================================*/
#include <iostream>
using namespace std;
int n;
double p1[100005], p2[100005], f[100005];
int main() {
	scanf("%d", &n);
	for(int i = 1 ; i <= n ; ++ i) {
		double p; scanf("%lf", &p);
		p1[i] = p * (p1[i - 1] + 1);
		f[i] = f[i - 1] + p * (1 + 2 * p1[i - 1]);
	}
	printf("%.10lf\n", f[n]);
}
