# 炉石传说

## 题目描述

AISakura 是一个爱搓炉石的镧孩子，最近他想玩一套很快乐的娱乐性卡组，可是他又想在快乐的同时保证这套卡组有较高的胜率。

现在这套卡里仍缺少若干张卡，AISakura 想要用比较强的卡去填满剩下的卡位，可是他又有选择恐惧症，于是他上网找了 $n$ 篇攻略，每篇攻略认可编号$\geqslant l$ 且 $\leqslant r$（卡的编号为 $1$ 开始的正整数）的卡比较强。若大于或等于 $k$ 篇攻略认为某个编号的卡比较强，则这个编号的卡则会进入 AISakura 的候选名单。

现在，AISakura 有 $q$ 个询问，每次询问编号 $\geqslant a$ 且 $\leqslant b$ 的卡中有几张有资格进入候选名单（即被大于等于 $k$ 篇攻略认可）。

遗憾的是差劲的他并不会数据统计，现在他找到了善于编程的你来帮助他完成构筑一套完($la$)美($ji$)卡组的梦想。请你依次输出 $q$ 个询问的结果。

## 输入格式

第一行 $3$ 个正整数 $n,k,q$。分别对应题中意义，即攻略数量，有资格进入候选名单所需攻略认可的篇数，以及询问数量。

接下来 $n$ 行，每行两个正整数 $l,r$，即每篇攻略认可范围。

接下来 $q$ 行，每行两个正整数 $a,b$ 即 AISakura 每次询问的范围。

## 输出格式

共 $q$ 行，每行一个正整数代表每次询问的结果。

## 样例 #1

### 样例输入 #1

```
3 2 4
91 94
92 97
97 99
92 94
93 97
95 96
90 100
```

### 样例输出 #1

```
3
3
0
4
```

## 提示

| 测试点 |                        $k,n$                        |                        $l,r$                        |                        $a,b$                        |                   $q$                   |
| :----: | :----------------------------------------------------: | :----------------------------------------------------: | :----------------------------------------------------: | :----------------------------------------: |
|  1~3  | $1\leqslant k \leqslant n \leqslant 5 \times 10 ^ 3$ | $1\leqslant l \leqslant r \leqslant 5 \times 10 ^ 3$ | $1\leqslant a \leqslant b \leqslant 5 \times 10 ^ 3$ | $1\leqslant q \leqslant 5 \times 10 ^ 3$ |
|  4~6  |     $1\leqslant k \leqslant n \leqslant 10 ^ 5$     |     $1\leqslant l \leqslant r \leqslant 10 ^ 5$     |     $1\leqslant a \leqslant b \leqslant 10 ^ 5$     |     $1\leqslant q \leqslant 10 ^ 5$     |
|  7~10  |     $1\leqslant k \leqslant n \leqslant 10 ^ 6$     |     $1\leqslant l \leqslant r \leqslant 10 ^ 6$     |     $1\leqslant a \leqslant b \leqslant 10 ^ 6$     |     $1\leqslant q \leqslant 10 ^ 6$     |
