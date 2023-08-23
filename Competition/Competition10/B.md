# [PFOI Round1] Two Repeats

## 题目背景

这天 [@huhe ](https://www.luogu.com.cn/user/70496) 哥哥在教小 z 证明一个东西，但小 z 没学好，就准备水谷来缓解心情。

小 z 在水谷时突然发现了一个好东西：串串。

## 题目描述

我们把连接两个相同的字符串得到的字符串称为连续双串。例如：$\tt IAKIOIIAKIOI$ 和 $\tt KKKK$ 是连续双串，$\tt IAKNOI$ 和 $\tt AFO$ 不是连续双串。

给定一个非空字符串 $S$，定义 $f(S)$ 是由尾部添加一个或者多个字符得到的最短的连续双串，例如： $f(\texttt{xyxxxyx}) =\tt xyxxxyxx$。我们可以证明 $f(S)$ 是由 $S$ 唯一确定的。

当然，我们也可以定义 $f^{n}(S) = f(f(...f(S)...))$，即在  $S$ 上应用 $n$ 次 $f$，例如：$f^2(S)=f(f(S))$,  $f^3(S)=f(f(f(S)))$，以此类推。

现在给定你一个**连续双串** $S$ 和一个字符串 $T$，以及整数 $k$，你需要计算 $T$ 在 $f^{k}(S)$ 里面总共出现了多少次。答案可能很大，所以请对 $10^9+7$ 取模。

## 输入格式

第一行一个字符串 $S$。

第二行一个字符串 $T$。

第三行一个整数 $k$。

## 输出格式

第一行一个整数表示答案。

## 样例 #1

### 样例输入 #1

```
abaaba
ab
1
```

### 样例输出 #1

```
4
```

## 提示

【样例解释】

$f(\texttt{abaaba})=\texttt{abaaba\color{red}baab}$，其中 $\texttt{ab}$ 出现 $4$ 次。

---

【数据范围】

对于 $100\%$ 的数据，满足 $1\leq |S|,|T|\leq 5\times 10^5$，$S$ 是一个连续双串，$1\leq k\leq 10^{18}$，字符集为小写字母。

- $\text{Subtask}\ 0(20\ \text{pts})$：$|S|\leq 50,\ k\leq 10$。
- $\text{Subtask}\ 1(15\ \text{pts})$： $S$ 的最小周期小于 $|S|/2$。
- $\text{Subtask}\ 2(15\ \text{pts})$：$|T|=1$。
- $\text{Subtask}\ 3(25\ \text{pts})$：$2|T|<|S|\leq 10^5,\ k\leq 10^5$。
- $\text{Subtask}\ 4(25\ \text{pts})$：无特殊限制。
