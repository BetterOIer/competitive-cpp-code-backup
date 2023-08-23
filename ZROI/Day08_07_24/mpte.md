# Subtree

## 题面翻译

给一棵树，对每一个节点染成黑色或白色。  

对于每一个节点，求强制把这个节点染成黑色的情况下，所有的黑色节点组成一个联通块的染色方案数，答案对 $M$ 取模。

## 题目描述

[problemUrl]: https://atcoder.jp/contests/dp/tasks/dp_v

$ N $ 頂点の木があります。 頂点には $ 1,\ 2,\ \ldots,\ N $ と番号が振られています。 各 $ i $ ($ 1\ \leq\ i\ \leq\ N\ -\ 1 $) について、$ i $ 番目の辺は頂点 $ x_i $ と $ y_i $ を結んでいます。

太郎君は、各頂点を白または黒で塗ることにしました。 このとき、どの黒い頂点からどの黒い頂点へも、黒い頂点のみを辿って到達できるようにします。

正整数 $ M $ が与えられます。 各 $ v $ ($ 1\ \leq\ v\ \leq\ N $) について、次の質問に答えてください。

- 頂点 $ v $ が黒であるような頂点の色の組合せは何通りか？ $ M $ で割った余りを求めよ。

## 输入格式

入力は以下の形式で標準入力から与えられる。

> $ N $ $ M $ $ x_1 $ $ y_1 $ $ x_2 $ $ y_2 $ $ : $ $ x_{N\ -\ 1} $ $ y_{N\ -\ 1} $

## 输出格式

$ N $ 行出力せよ。 $ v $ ($ 1\ \leq\ v\ \leq\ N $) 行目には、次の質問に対する答えを出力せよ。

- 頂点 $ v $ が黒であるような頂点の色の組合せは何通りか？ $ M $ で割った余りを求めよ。

## 样例 #1

### 样例输入 #1

```
3 100
1 2
2 3
```

### 样例输出 #1

```
3
4
3
```

## 样例 #2

### 样例输入 #2

```
4 100
1 2
1 3
1 4
```

### 样例输出 #2

```
8
5
5
5
```

## 样例 #3

### 样例输入 #3

```
1 100
```

### 样例输出 #3

```
1
```

## 样例 #4

### 样例输入 #4

```
10 2
8 5
10 8
6 5
1 5
4 8
2 10
3 6
9 2
1 7
```

### 样例输出 #4

```
0
0
1
1
1
0
1
0
1
1
```

## 提示

### 制約

- 入力はすべて整数である。
- $ 1\ \leq\ N\ \leq\ 10^5 $
- $ 2\ \leq\ M\ \leq\ 10^9 $
- $ 1\ \leq\ x_i,\ y_i\ \leq\ N $
- 与えられるグラフは木である。

### Sample Explanation 1

頂点の色の組合せは次図の $ 7 $ 通りです。 このうち、頂点 $ 1 $ が黒であるようなものは $ 3 $ 通り、頂点 $ 2 $ が黒であるようなものは $ 4 $ 通り、頂点 $ 3 $ が黒であるようなものは $ 3 $ 通りです。 !\[\](https://img.atcoder.jp/dp/subtree\_0\_muffet.png)

### Sample Explanation 4

答えを $ M $ で割った余りを出力することを忘れずに。


# Zero Tree

## 题面翻译

题目描述

一棵树是一个有n个节点与正好n-1条边的图；并且符合以下条件：对于任意两个节点之间有且只有一条简单路径。

我们定义树T的子树为一棵所有节点是树T节点的子集，所有边是T边的子集的树。

给定一颗有n个节点的树，假设它的节点被编号为1到n。每个节点有一个权值，$v_i$表示编号为i的节点的权值。你需要进行一些操作，每次操作符合以下规定：

    - 在给定的这棵树中选择一棵子树，并保证子树中含有节点1
    - 把这棵子树中的所有节点加上或减去1

你需要计算至少需要多少次操作来让所有的节点的权值归零。
输入数据

第一行包含一个整数n，表示树中节点的数量

接下来的n-1行，一行两个整数u,v，表示u和v之间有一条边(u!=v)。

最后一行包含n个整数$v_i$，用空格隔开，表示每个节点的权值
输出数据

一行一个整数，输出最小需要的操作次数。
输入样例
```
3
1 2
1 3
1 -1 1
```
输出样例
```
3
```
数据规模
对于$30\%$的数据，$n\leq100,|vi|\leq1000$

对于$50\%$的数据，$n\leq10^4$

对于$100\%$的数据，$n\leq10^5,|vi|\leq10^9$

Translated by 首相大大

## 题目描述

A tree is a graph with $ n $ vertices and exactly $ n-1 $ edges; this graph should meet the following condition: there exists exactly one shortest (by number of edges) path between any pair of its vertices.

A subtree of a tree $ T $ is a tree with both vertices and edges as subsets of vertices and edges of $ T $ .

You're given a tree with $ n $ vertices. Consider its vertices numbered with integers from 1 to $ n $ . Additionally an integer is written on every vertex of this tree. Initially the integer written on the $ i $ -th vertex is equal to $ v_{i} $ . In one move you can apply the following operation:

1. Select the subtree of the given tree that includes the vertex with number 1.
2. Increase (or decrease) by one all the integers which are written on the vertices of that subtree.

Calculate the minimum number of moves that is required to make all the integers written on the vertices of the given tree equal to zero.

## 输入格式

The first line of the input contains $ n $ ( $ 1<=n<=10^{5} $ ). Each of the next $ n-1 $ lines contains two integers $ a_{i} $ and $ b_{i} $ ( $ 1<=a_{i},b_{i}<=n; a_{i}≠b_{i} $ ) indicating there's an edge between vertices $ a_{i} $ and $ b_{i} $ . It's guaranteed that the input graph is a tree.

The last line of the input contains a list of $ n $ space-separated integers $ v_{1},v_{2},...,v_{n} $ ( $ |v_{i}|<=10^{9} $ ).

## 输出格式

Print the minimum number of operations needed to solve the task.

Please, do not write the %lld specifier to read or write 64-bit integers in С++. It is preferred to use the cin, cout streams or the %I64d specifier.

## 样例 #1

### 样例输入 #1

```
3
1 2
1 3
1 -1 1
```

### 样例输出 #1

```
3
```