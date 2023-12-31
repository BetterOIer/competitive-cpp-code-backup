# baller的村BA总决赛

## 题目背景

**//数据提供：LINTONG，goldfish**

**//Checker:LINTONG**

#### 随着时间的推移，某村的CBA（村BA）比赛即将迎来总决赛，由baller带领的一只鱼腩球队~~靠运气~~成功挤进了总决赛，实在令人难以理解。由于队员们知道自己的实力还不如一些小学生，所以他们决定进行抗压投篮训练，以此来避免自己输得太惨，与此同时，测评队员的投篮稳定性也是必不可少的，而baller是一个不折不扣的牛马，根本不会用c++，于是他找来了身为大聪明的你帮忙。

## 题目描述

虽然技术不行，但是条件还是很优越的。球员们将在一个长，宽分别为x,y的篮球场训练。现在只对baller进行特训，给出此队员的站立摸高h1，弹跳m1，体力s，初始状态下的投篮命中率a。同时场上有若干名防守人，每个防守队员的周围8个位置是过不去的（因为他们很强壮）。baller最后要用最少步数到达投篮点，已知每走一步，baller的体力变为99%，弹跳变为原来的98%。在投篮点还有另一名防守人，站立摸高h2,弹跳m2，baller需要起跳投篮，防守人要起跳防守，结果分以下几种：若baller跳的比防守人低或和防守人跳的一样高，那么输出“Oh f**k！！！”（因为被盖帽了）；在跳的比防守人高的情况下，若跳的高度高于篮筐高度（305.00cm)，那么输出“jam！！！”，否则输出当前的投篮命中率。

#### PS:本题中，1:s,h1,h2,m1,m2,a为双精度实数，其余的为整数。------2:最终的投篮命中率=初始命中率*（最后的体力/100）*（最后的弹跳/150）。---------3:baller的初始位置用'@'表示，不在投篮点的防守人用'#'表示，投篮点（同时也是该位置的防守人）用'?'表示，没有人的点用'.'表示。————4：baller只能上下左右走，走过的地方不能重复走（否则会受到教练的批评）。----5：最后的跳的高度=最后的弹跳+站立摸高

## 输入格式

第一行：4个数，分别表示baller的站立摸高，弹跳，体力值，初始投篮命中率。

 第二行：两个数：表示投篮点处防守人的站立摸高，弹跳。

 第三行：2个数：表示篮球场的长，宽x，y。

#### 最后输入球场的矩阵。

## 输出格式

#### 先输出最少的步数，再按照题干中描述的输出，若输出投篮命中率，保留到小数点后2位。

## 样例 #1

### 样例输入 #1

```
225 75 90 50
225 60
5 4
@...#
.....
..... 
#...?
```

### 样例输出 #1

```
7
18.21
```

## 样例 #2

### 样例输入 #2

```
250 90 90 50
225 60
6 7 
......
.....#
..@...
#.....
......
....#.
?.....
```

### 样例输出 #2

```
6
jam！！！
```

## 样例 #3

### 样例输入 #3

```
220 90 90 50
225 60
11 10
........... 
..@........
...........
....#......
...........
......?....
...........
....#......
...........
...........
```

### 样例输出 #3

```
8
21.20
```

## 提示

#### 对于所有的数据，满足0<x,y<1001;

#### 0<s<=100;

#### 30<m1,m2<150;

#### 200<h1,h2<270;

#### 0<a<100;**

#### **对于所有的数据，baller都可以到达投篮点。**
