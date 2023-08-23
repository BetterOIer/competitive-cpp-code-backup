#include <iostream>
#include <cmath>
using namespace std;
double jd=0.000001,x, y;
bool dirx=true, diry=true;
int n;
struct node{
    int x;
    int y;
    int val;
}positions[1005];
void zjfj(double);
int main() {
    scanf("%d", &n);
    for (int i=1;i<=n;i++)
        scanf("%d%d%d", &positions[i].x, &positions[i].y, &positions[i].val);
    double distance = 5000, tx, ty;
    while (true) {
        tx=x,ty=y;
        zjfj(distance);
        if (abs(tx-x)<jd&&abs(ty-y)<jd)
            break;
        if ((dirx!=(x>tx))||(diry!= (y>ty))) {
            dirx = !x > tx;
            diry= !y > ty;
            distance *=0.9;
        }
    }
    printf("%.3f %.3f", x, y);
    return 0;
}
void zjfj(double distance){
    double X,Y,offset;
    X=Y=0;
    for (int i = 1; i <= n; i++) {
        offset=sqrt((x-positions[i].x)*(x-positions[i].x)+(y-positions[i].y)*(y-positions[i].y));
        if(offset){
            X+=(positions[i].x-x)*positions[i].val/offset;
            Y+=(positions[i].y-y)*positions[i].val/offset;
        }
    }
    offset = sqrt(X * X + Y * Y);
    x+=distance*X/offset;
    y+=distance*Y/offset;
}