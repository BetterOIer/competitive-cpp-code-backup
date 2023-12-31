# 彩灯

## 题目背景

wlzx 一年一度的元旦文艺汇演就要到了，为了装饰会场，王校长从~~数竞~~经费中抽调了一部分（ $19198101145.14￥$ ） 来购买彩灯。

王校长对彩灯上灯珠的排列十分感兴趣，然而，由于 王校长**对数学的理解不够**，所以他找到了1506机房的高一蒟蒻来解决这个问题，可是他们也不会。

现在，便是你为王校长排忧解难的时刻。

## 题目描述

对于每条彩灯而言，它有 $n$ 颗灯珠，每颗灯珠都有颜色（用一个正整数表示）。

王校长拿出一条彩灯，他想知道有多少种方式来选出一段**连续的且颜色各不相同**的灯珠（只要起始位置不同，就当作是不同的选法）。

### 题意简化

给出一个长度为 $n$ 的数列，求出该数列中元素各不相同的子串个数。~~（不会真的有人看不懂题目吧~~

## 输入格式

第一行给出一个整数 $n$，表示彩灯的长度。

第二行给出 $n$ 个正整数，表示每个灯珠的颜色 $A_i$。

## 输出格式

一个整数，表示方案数。

## 样例 #1

### 样例输入 #1

```
5
1 1 2 1 5
```

### 样例输出 #1

```
9
```

## 样例 #2

### 样例输入 #2

```
7
2 2 6 8 4 6 2
```

### 样例输出 #2

```
18
```

## 提示

对于 $30\%$ 的数据，$1\le n,A_i\le 10$；

对于 $60\%$ 的数据，$1\le n,A_i\le 10^5$；

对于 $100\%$ 的数据，$1≤n≤10^5$，$1≤A_i≤10^{18}$。
